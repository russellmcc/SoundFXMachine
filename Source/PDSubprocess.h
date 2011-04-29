/*
 *  PDSubprocess.h
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

#ifndef PDSubprocess_h
#define PDSubprocess_h

enum SubProcessCommands
{
    kSubProcStartup, // takes 32-bit int numInputs, int numOutputs, int samplerate.
    kSubProcParam, // takes 32-bit int paramIndex, 32-bit float value (0-1)
    kSubProcProcess, // takes int number of samples, input buffer
    kSubProcQuit
};

enum HostCommands
{
    kHostFillBuffer
};

#endif