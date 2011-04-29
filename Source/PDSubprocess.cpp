/*
 *  PDSubprocess.cpp
 *  SoundFXMachine
 *
 *  Created by James Russell McClellan on 4/2/11.
 
 Permission is hereby granted, free of charge, to any person or organization
 obtaining a copy of the software and accompanying documentation covered by
 this license (the "Software") to use, reproduce, display, distribute,
 execute, and transmit the Software, and to prepare derivative works of the
 Software, and to permit third-parties to whom the Software is furnished to
 do so.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.

 *
 */

#include "PDSubprocess.h"
#include "JuceHeader.h"
#include "PD_characteristics.h"
#include "OwnedCFRef.h"
#include "z_libpd.h"
#include "../JuceLibraryCode/JucePluginCharacteristics.h"
#include <mach/mach_init.h>
#include <mach/thread_policy.h>
#include <mach/thread_act.h>
#include <mach/mach_time.h>
#include <CoreAudio/HostTime.h>
#include "PDSubprocessInternal.h"

#include <iostream>
using namespace std;
namespace 
{    
int set_realtime(int period, int computation) {
    struct thread_time_constraint_policy ttcpolicy;
    int ret;
    boolean_t				fetchDefaults = false;
    mach_msg_type_number_t itemCount = THREAD_TIME_CONSTRAINT_POLICY_COUNT;
    thread_policy_get(mach_thread_self(), THREAD_TIME_CONSTRAINT_POLICY, (integer_t*)&ttcpolicy, &itemCount, &fetchDefaults);
    
    ttcpolicy.period=AudioConvertNanosToHostTime(period); // HZ/160
    ttcpolicy.computation=AudioConvertNanosToHostTime(computation); // HZ/3300;
    ttcpolicy.constraint=AudioConvertNanosToHostTime(100000 + computation); // HZ/2200;
    ttcpolicy.preemptible=1;
    
    if ((ret=thread_policy_set(mach_thread_self(),
                               THREAD_TIME_CONSTRAINT_POLICY, (thread_policy_t)&ttcpolicy,
                               itemCount)) != KERN_SUCCESS) {
        cerr<<"set_realtime failed"<<endl;
        return 0;
    }
    cerr<<"set_realtime worked."<<endl;
    return 1;
}

void set_realtime_pthread()
{
    void* handle = (void*) pthread_self();
    int priority = 10;
    
    struct sched_param param;
    int policy;
    pthread_getschedparam ((pthread_t) handle, &policy, &param);
    param.sched_priority = jlimit (1, 127, 1 + (priority * 126) / 11);
    if( pthread_setschedparam ((pthread_t) handle, policy, &param) == 0)
    {
        cerr<<"pthread priority worked!\n"<<endl;
    }
    else 
    {
        cerr<<"pthread priority failed!\n"<<endl;
    }

}
}

class HostConnection : public InterprocessConnection
{
public:
    virtual void 	connectionMade ()
    {
        cerr<<"Child connected"<<endl;
    }
    
    virtual void 	connectionLost ()
    {
        cerr<<"Child lost connection."<<endl;
        JUCEApplication::quit();
    }
    
    virtual void 	messageReceived (const MemoryBlock &message)
    {            
        static bool procSet = false;
        if(not procSet)
        {
            Process::setPriority(Process::RealtimePriority);
            
            // mac-specific
            set_realtime(100000,100000);
            procSet = true;
        }
        
        if(message.getSize() < sizeof(uint32_t))
            return;
        
        uint32_t opcode = reinterpret_cast<uint32_t*>(message.getData())[0];
        
        switch(opcode)
        {
            case kSubProcQuit:
                JUCEApplication::quit();
                break;
            case kSubProcStartup:
            {
                cerr<<"Got startup message"<<endl;
                int numInputs = reinterpret_cast<uint32_t*>(message.getData())[1];
                int numOutputs = reinterpret_cast<uint32_t*>(message.getData())[2];
                int sampleRate = reinterpret_cast<uint32_t*> (message.getData())[3];
                if(fProc)
                {
                    cerr<<"Sending processor start-up! in:"<<numInputs<<" out: "<<numOutputs<<" sample:"<<sampleRate<<endl;
                    fProc->startAudio(numInputs, numOutputs, sampleRate);
                }
            }
                break;
            case kSubProcParam:
            {
                int paramIndex = reinterpret_cast<uint32_t*>(message.getData())[1];
                float paramValue = reinterpret_cast<float*> (message.getData())[2];
                if(fProc)
                    fProc->setParam(paramIndex, paramValue);
            }
                break;
            case kSubProcProcess:
            {
                int numSamples = reinterpret_cast<uint32_t*>(message.getData())[1];
                float* inBuffer = &(reinterpret_cast<float*>(message.getData())[2]);
                if(fProc)
                {
                    MemoryBlock outBlock(sizeof(uint32_t) + sizeof(float)*numSamples*fProc->GetNumOutputs());
                    reinterpret_cast<uint32_t*>(outBlock.getData())[0] = kHostFillBuffer;
                    float* outBuffer = &(reinterpret_cast<float*>(outBlock.getData())[1]);
                    fProc->doAudioStep(inBuffer, numSamples, outBuffer);
                    sendMessage(outBlock);
                }
            }
            break;
        }
    }
    
    void setProcessor(PDSubprocessor* proc)
    {
        fProc = proc;
    }
    
    HostConnection() :fProc(0)
    {
    }
private:
    PDSubprocessor* fProc;
};

namespace 
{ 
    void pdprint(const char *s) 
    {
        cerr<<s<<endl;;
    }
}

PDSubprocessor::PDSubprocessor()
{
    fCurrInBuffIndex = 0;
    fLatencyFilled = false;
    
    libpd_printhook = (t_libpd_printhook) pdprint;
    libpd_init();    
    
    CFBundleRef thisBundle = CFBundleGetBundleWithIdentifier(CFSTR(QUOTEME(JucePlugin_CFBundleIdentifier)));
    OwnedCFRef<CFURLRef> exeURL(CFBundleCopyExecutableURL (thisBundle));
    OwnedCFRef<CFStringRef> exePathString(CFURLCopyFileSystemPath(exeURL.get(), kCFURLPOSIXPathStyle));
    char strBuffer[512];
    CFStringGetCString(exePathString.get(), strBuffer, sizeof(strBuffer), kCFStringEncodingMacRoman);
    for(int i = strlen(strBuffer); i; --i)
    {
        if(strBuffer[i] == '/')
        {
            strBuffer[i+1] = 0;
            break;
        }
    }
    
    libpd_add_to_search_path(strBuffer);
    
    fOpenHandle = libpd_openfile(PD_Patch, strBuffer);
    if(!fOpenHandle)
        cerr<<"uh oh- couldn't open file"<<endl;
    
    cerr<<"opened file!: "<<strBuffer<<endl;
    
    cerr<<"ended initialization: "<<endl;    
}

float PDSubprocessor::scaleFloat(float in, float minVal, float maxVal, PDMessageInfo::Taper taper)
{
    switch(taper)
    {
        case PDMessageInfo::kLinearTaper:
            return (in * (maxVal - minVal)) + minVal;
            break;
        case PDMessageInfo::kLogTaper:
        {
            double logmin = log(minVal)/log(2);
            double logmax = log(maxVal)/log(2);
            return pow(2, (in * (logmax - logmin)) + logmin);
        }
            break;
    }
    return 0;
}    

// new value is 0-1
void PDSubprocessor::setParam(int i, float newValue)
{
    int val = libpd_float(PDMessages[i].pdName.toUTF8(), scaleFloat(newValue, PDMessages[i].minValue, PDMessages[i].maxValue, PDMessages[i].taper));
    if(val != 0)
        cerr<<"set "<<PDMessages[i].pdName.toUTF8()<<" failed err "<<val<<endl;    
}    

void PDSubprocessor::startAudio(int numInputs, int numOutputs, int sampleRate)
{
    cerr<<"prepare for play"<<endl;
    
    libpd_start_message();
    libpd_add_float(0.0f);
    libpd_finish_message("pd", "dsp");
    
    fNumInputs = numInputs;
    fNumOutputs = numOutputs;
    
    libpd_init_audio(fNumInputs, fNumOutputs, sampleRate, 1);
    
    fInBuff.reset(new float[fNumInputs * 64]);
    fOutBuff.reset(new float[fNumOutputs * 64]);
    fCurrInBuffIndex = 0;
    
    libpd_start_message();
    libpd_add_float(1.0f);
    libpd_finish_message("pd", "dsp");
}

void PDSubprocessor::doAudioStep(float* ins, int numSamples, float* outs)
{
    int samplesFilled = 0;
    
    while(samplesFilled < numSamples)
    {
        int samplesThisPass = min(64, min(64 - fCurrInBuffIndex, numSamples - samplesFilled));
        
        if(fLatencyFilled)
        {
            // Now send the output.
            for (int channel = 0; channel < fNumOutputs; ++channel)
                memcpy(&(outs[channel*numSamples + samplesFilled]), &(fOutBuff.get()[64 * channel + fCurrInBuffIndex]), samplesThisPass * sizeof(float));
        }
        else
        {
            for (int channel = 0; channel < fNumOutputs; ++channel)
                memset(&(outs[channel*numSamples + samplesFilled]), 0, samplesThisPass * sizeof(float));
        }
        
        // now, collect up the input buffer.
        for (int channel = 0; channel < fNumInputs; ++channel)
            memcpy(&((fInBuff.get())[64*channel + fCurrInBuffIndex]), &(ins[channel*numSamples*sizeof(float) + samplesFilled]), samplesThisPass * sizeof(float));
        
        fCurrInBuffIndex += samplesThisPass;
        samplesFilled += samplesThisPass;        
        
        if(fCurrInBuffIndex >= 64)
        {
            // Do a tick of PD processing
            int res = libpd_process_raw(fInBuff.get(), fOutBuff.get());
            if(res)
                cerr<<"PD failed with code"<<res<<endl;
            fLatencyFilled = true;
            fCurrInBuffIndex = 0;
        }
    }
}

#if !STANDALONE_VERSION
class PDProcessorApp : public JUCEApplication
{
public:
    void initialise (const String& commandLine)
    {
        cerr<<"Going in!"<<endl;
        MessageManager::getInstance();

        fSubProcessor = new PDSubprocessor;
        
        fHostConnection.setProcessor(fSubProcessor.getObject());
        
        cerr<<"With command:"<<commandLine<<endl;
        fHostConnection.connectToPipe(commandLine);
    }
    
    void shutdown()
    {
        cerr<<"Shutting down!"<<endl;
    }
    
    const String getApplicationName()
    {
        return "PDProcessor";
    }
    
    const String getApplicationVersion()
    {
        return "1.0";
    }    
private:
    PDSubprocessor::Ptr fSubProcessor;
    HostConnection fHostConnection;
};

START_JUCE_APPLICATION (PDProcessorApp)
#endif