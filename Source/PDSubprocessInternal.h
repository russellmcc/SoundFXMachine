/*
 *  PDSubprocessInternal.h
 *  SoundFXMachine
 *
 *  Created by James Russell McClellan on 4/28/11.
 
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

#ifndef PDSubprocessInternal_h
#define PDSubprocessInternal_h

#include "JuceHeader.h"
#include "PD_characteristics.h"

class PDSubprocessor : public ReferenceCountedObject
{
public:
    PDSubprocessor();
    
    void setParam(int i, float newValue);
    void startAudio(int numInputs, int numOutputs, int sampleRate);
    void doAudioStep(float* ins, int numSamples, float* outs);
    typedef ReferenceCountedObjectPtr<PDSubprocessor> Ptr;
    
    int GetNumOutputs() {return fNumOutputs;}
private:
    float scaleFloat(float in, float minVal, float maxVal, PDMessageInfo::Taper taper);
    
    auto_array<float> fInBuff;
    auto_array<float> fOutBuff;
    int fCurrInBuffIndex;
    bool fLatencyFilled;
    int fNumInputs;
    int fNumOutputs;
    void* fOpenHandle;
};

#endif