/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  24 Apr 2011 10:49:16pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_JUCEPDAUDIOPROCESSOREDITOR_PLUGINEDITOR_F90FE379__
#define __JUCER_HEADER_JUCEPDAUDIOPROCESSOREDITOR_PLUGINEDITOR_F90FE379__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "GhostFactLookFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class JucePdAudioProcessorEditor  : public AudioProcessorEditor,
                                    public AudioProcessorListener,
                                    public SliderListener,
                                    public ButtonListener
{
public:
    //==============================================================================
    JucePdAudioProcessorEditor (JucePdAudioProcessor* proc);
    ~JucePdAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void buttonStateChanged(Button* button);
    virtual void audioProcessorParameterChanged (AudioProcessor *processor, int parameterIndex, float newValue);
    virtual void 	audioProcessorChanged (AudioProcessor *processor) {}

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);

    // Binary resources:
    static const char* soundFxMachine_png;
    static const int soundFxMachine_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    GhostFactLookAndFeel gfLaF;
    bool dontUpdate;
    //[/UserVariables]

    //==============================================================================
    Slider* sound;
    Slider* speedRange;
    Slider* speedFastSlow;
    Slider* toneHiLo;
    Slider* toneRange;
    Slider* oneShot;
    TextButton* oneShotActive;
    Slider* oneShotShortLong;
    Slider* fadeOutShortLong;
    Slider* mixera;
    Slider* mixerb;
    Slider* mixerC;
    Image cachedImage_soundFxMachine_png;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    JucePdAudioProcessorEditor (const JucePdAudioProcessorEditor&);
    const JucePdAudioProcessorEditor& operator= (const JucePdAudioProcessorEditor&);
};


#endif   // __JUCER_HEADER_JUCEPDAUDIOPROCESSOREDITOR_PLUGINEDITOR_F90FE379__
