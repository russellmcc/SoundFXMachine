/*
 *  PD_characteristics.h
 *  JucePD
 *
 *  Created by James Russell McClellan on 3/27/11.

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

#ifndef PD_characteristics_h
#define PD_characteristics_h

#include "JuceHeader.h"

#define PD_Patch "remco.pd"

struct PDMessageInfo
{
    String name;  // name on the automation
    String pdName; // name on the pd-side.
    
    float defaultValue;  //scale from 0-1
    
    float minValue;
    float maxValue;
    
    enum Taper 
    {
        kLinearTaper,
        kLogTaper
    };
    
    Taper taper;
};

static const PDMessageInfo PDMessages[] = 
{
    {"Speed Range", "slf-range", .5, 0, 1, PDMessageInfo::kLinearTaper},
    {"Speed Fast/Slow", "slf-freq", .5, 0.1, 1, PDMessageInfo::kLogTaper},
    {"Speed Amount", "vco-mod", .5, 20, 1000, PDMessageInfo::kLinearTaper},
    {"Sound Hi/Lo", "noise-freq", .5, 50, 10000, PDMessageInfo::kLogTaper},
    {"Tone Range", "vco-range", .5, 0, 1, PDMessageInfo::kLinearTaper},
    {"Tone Hi/Lo", "vco-freq", .5, 0.1, 1, PDMessageInfo::kLogTaper},
    {"Mixer A", "mixera", 0, 0, 1, PDMessageInfo::kLinearTaper},
    {"Mixer B", "mixerb", 0, 0, 1, PDMessageInfo::kLinearTaper},
    {"Mixer C", "mixerc", 0, 0, 1, PDMessageInfo::kLinearTaper},
    {"One Shot On/Off", "one-shot-on", 0, 0, 1, PDMessageInfo::kLinearTaper},
    {"One Shot Activator", "one-shot", 1, 0, 1, PDMessageInfo::kLinearTaper},
    {"One Shot Short/Long", "attack", .2, 100, 3000, PDMessageInfo::kLinearTaper},
    {"Fade Out Short/Long", "release", .2, 100, 3000, PDMessageInfo::kLinearTaper},
    {"Volume", "volume", .1, 0, 1, PDMessageInfo::kLinearTaper}
};

#endif
