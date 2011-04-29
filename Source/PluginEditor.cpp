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

//[Headers] You can add your own extra header files here...
#include "PD_characteristics.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
JucePdAudioProcessorEditor::JucePdAudioProcessorEditor (JucePdAudioProcessor* proc)
    : AudioProcessorEditor(proc),
      sound (0),
      speedRange (0),
      speedFastSlow (0),
      toneHiLo (0),
      toneRange (0),
      oneShot (0),
      oneShotActive (0),
      oneShotShortLong (0),
      fadeOutShortLong (0),
      mixera (0),
      mixerb (0),
      mixerC (0),
      cachedImage_soundFxMachine_png (0)
{
    addAndMakeVisible (sound = new Slider (T("Sound Hi/Lo")));
    sound->setRange (0, 1, 0);
    sound->setSliderStyle (Slider::RotaryVerticalDrag);
    sound->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sound->setColour (Slider::rotarySliderFillColourId, Colours::black);
    sound->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    sound->addListener (this);

    addAndMakeVisible (speedRange = new Slider (T("Speed Range")));
    speedRange->setRange (0, 1, 0.33333);
    speedRange->setSliderStyle (Slider::RotaryVerticalDrag);
    speedRange->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    speedRange->setColour (Slider::rotarySliderFillColourId, Colours::black);
    speedRange->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    speedRange->addListener (this);

    addAndMakeVisible (speedFastSlow = new Slider (T("Speed Fast/Slow")));
    speedFastSlow->setRange (0, 1, 0);
    speedFastSlow->setSliderStyle (Slider::RotaryVerticalDrag);
    speedFastSlow->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    speedFastSlow->setColour (Slider::rotarySliderFillColourId, Colours::black);
    speedFastSlow->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    speedFastSlow->addListener (this);

    addAndMakeVisible (toneHiLo = new Slider (T("Tone Hi/Lo")));
    toneHiLo->setRange (0, 1, 0);
    toneHiLo->setSliderStyle (Slider::RotaryVerticalDrag);
    toneHiLo->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    toneHiLo->setColour (Slider::rotarySliderFillColourId, Colours::black);
    toneHiLo->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    toneHiLo->addListener (this);

    addAndMakeVisible (toneRange = new Slider (T("Tone Range")));
    toneRange->setRange (0, 1, 0.3333);
    toneRange->setSliderStyle (Slider::RotaryVerticalDrag);
    toneRange->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    toneRange->setColour (Slider::rotarySliderFillColourId, Colours::black);
    toneRange->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    toneRange->addListener (this);

    addAndMakeVisible (oneShot = new Slider (T("One Shot On/Off")));
    oneShot->setRange (0, 1, 1);
    oneShot->setSliderStyle (Slider::LinearVertical);
    oneShot->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oneShot->setColour (Slider::thumbColourId, Colour (0xff00c4e8));
    oneShot->setColour (Slider::trackColourId, Colour (0xff101114));
    oneShot->addListener (this);

    addAndMakeVisible (oneShotActive = new TextButton (T("One Shot Activator")));
    oneShotActive->setButtonText (String::empty);
    oneShotActive->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    oneShotActive->addListener (this);
    oneShotActive->setColour (TextButton::buttonColourId, Colour (0xff292937));
    oneShotActive->setColour (TextButton::buttonOnColourId, Colour (0xff101016));

    addAndMakeVisible (oneShotShortLong = new Slider (T("One Shot Short/Long")));
    oneShotShortLong->setRange (0, 1, 0);
    oneShotShortLong->setSliderStyle (Slider::RotaryVerticalDrag);
    oneShotShortLong->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    oneShotShortLong->setColour (Slider::backgroundColourId, Colours::black);
    oneShotShortLong->setColour (Slider::thumbColourId, Colour (0x0));
    oneShotShortLong->setColour (Slider::trackColourId, Colours::black);
    oneShotShortLong->setColour (Slider::rotarySliderFillColourId, Colours::black);
    oneShotShortLong->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    oneShotShortLong->setColour (Slider::textBoxHighlightColourId, Colour (0x1111ee));
    oneShotShortLong->setColour (Slider::textBoxOutlineColourId, Colour (0x808080));
    oneShotShortLong->addListener (this);

    addAndMakeVisible (fadeOutShortLong = new Slider (T("Fade Out Short/Long")));
    fadeOutShortLong->setRange (0, 1, 0);
    fadeOutShortLong->setSliderStyle (Slider::RotaryVerticalDrag);
    fadeOutShortLong->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    fadeOutShortLong->setColour (Slider::backgroundColourId, Colours::black);
    fadeOutShortLong->setColour (Slider::thumbColourId, Colour (0xbbbbff));
    fadeOutShortLong->setColour (Slider::rotarySliderFillColourId, Colours::black);
    fadeOutShortLong->setColour (Slider::rotarySliderOutlineColourId, Colours::black);
    fadeOutShortLong->addListener (this);

    addAndMakeVisible (mixera = new Slider (T("Mixer A")));
    mixera->setRange (0, 1, 1);
    mixera->setSliderStyle (Slider::LinearVertical);
    mixera->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    mixera->setColour (Slider::thumbColourId, Colour (0xffffce00));
    mixera->setColour (Slider::trackColourId, Colour (0xff252716));
    mixera->addListener (this);

    addAndMakeVisible (mixerb = new Slider (T("Mixer B")));
    mixerb->setRange (0, 1, 1);
    mixerb->setSliderStyle (Slider::LinearVertical);
    mixerb->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    mixerb->setColour (Slider::thumbColourId, Colour (0xffffce00));
    mixerb->setColour (Slider::trackColourId, Colour (0xff1d1c14));
    mixerb->addListener (this);

    addAndMakeVisible (mixerC = new Slider (T("Mixer C")));
    mixerC->setRange (0, 1, 1);
    mixerC->setSliderStyle (Slider::LinearVertical);
    mixerC->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    mixerC->setColour (Slider::thumbColourId, Colour (0xffffce00));
    mixerC->setColour (Slider::trackColourId, Colour (0xff141410));
    mixerC->addListener (this);

    cachedImage_soundFxMachine_png = ImageCache::getFromMemory (soundFxMachine_png, soundFxMachine_pngSize);

    //[UserPreSize]
    setLookAndFeel(&gfLaF);
    oneShotActive->setClickingTogglesState(false);
    //[/UserPreSize]

    setSize (600, 400);

    //[Constructor] You can add your own custom stuff here..
    dontUpdate = false;
    proc->addSuperListener(this);
    //[/Constructor]
}

JucePdAudioProcessorEditor::~JucePdAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    dynamic_cast<JucePdAudioProcessor*>(getAudioProcessor())->removeSuperListener(this);
    //[/Destructor_pre]

    deleteAndZero (sound);
    deleteAndZero (speedRange);
    deleteAndZero (speedFastSlow);
    deleteAndZero (toneHiLo);
    deleteAndZero (toneRange);
    deleteAndZero (oneShot);
    deleteAndZero (oneShotActive);
    deleteAndZero (oneShotShortLong);
    deleteAndZero (fadeOutShortLong);
    deleteAndZero (mixera);
    deleteAndZero (mixerb);
    deleteAndZero (mixerC);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void JucePdAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    // TODO: Sync up to values.

    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.drawImage (cachedImage_soundFxMachine_png,
                 0, 0, 600, 400,
                 0, 0, cachedImage_soundFxMachine_png.getWidth(), cachedImage_soundFxMachine_png.getHeight());

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void JucePdAudioProcessorEditor::resized()
{
    sound->setBounds (270, 263, 60, 60);
    speedRange->setBounds (50, 263, 60, 60);
    speedFastSlow->setBounds (145, 263, 60, 60);
    toneHiLo->setBounds (480, 263, 60, 60);
    toneRange->setBounds (379, 263, 60, 60);
    oneShot->setBounds (154, 151, 16, 56);
    oneShotActive->setBounds (196, 151, 56, 56);
    oneShotShortLong->setBounds (271, 151, 60, 60);
    fadeOutShortLong->setBounds (379, 151, 60, 60);
    mixera->setBounds (220, 40, 16, 56);
    mixerb->setBounds (296, 40, 16, 56);
    mixerC->setBounds (369, 40, 16, 56);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void JucePdAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    int numParams = sizeof(PDMessages) / sizeof(PDMessageInfo);
    for(int i = 0; i < numParams; ++i)
    {
        dontUpdate = true;
        if(sliderThatWasMoved->getName() == PDMessages[i].name)
            getAudioProcessor()->setParameterNotifyingHost(i, sliderThatWasMoved->getValue());
        dontUpdate = false;
    }
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sound)
    {
        //[UserSliderCode_sound] -- add your slider handling code here..
        //[/UserSliderCode_sound]
    }
    else if (sliderThatWasMoved == speedRange)
    {
        //[UserSliderCode_speedRange] -- add your slider handling code here..
        //[/UserSliderCode_speedRange]
    }
    else if (sliderThatWasMoved == speedFastSlow)
    {
        //[UserSliderCode_speedFastSlow] -- add your slider handling code here..
        //[/UserSliderCode_speedFastSlow]
    }
    else if (sliderThatWasMoved == toneHiLo)
    {
        //[UserSliderCode_toneHiLo] -- add your slider handling code here..
        //[/UserSliderCode_toneHiLo]
    }
    else if (sliderThatWasMoved == toneRange)
    {
        //[UserSliderCode_toneRange] -- add your slider handling code here..
        //[/UserSliderCode_toneRange]
    }
    else if (sliderThatWasMoved == oneShot)
    {
        //[UserSliderCode_oneShot] -- add your slider handling code here..
        //[/UserSliderCode_oneShot]
    }
    else if (sliderThatWasMoved == oneShotShortLong)
    {
        //[UserSliderCode_oneShotShortLong] -- add your slider handling code here..
        //[/UserSliderCode_oneShotShortLong]
    }
    else if (sliderThatWasMoved == fadeOutShortLong)
    {
        //[UserSliderCode_fadeOutShortLong] -- add your slider handling code here..
        //[/UserSliderCode_fadeOutShortLong]
    }
    else if (sliderThatWasMoved == mixera)
    {
        //[UserSliderCode_mixera] -- add your slider handling code here..
        //[/UserSliderCode_mixera]
    }
    else if (sliderThatWasMoved == mixerb)
    {
        //[UserSliderCode_mixerb] -- add your slider handling code here..
        //[/UserSliderCode_mixerb]
    }
    else if (sliderThatWasMoved == mixerC)
    {
        //[UserSliderCode_mixerC] -- add your slider handling code here..
        //[/UserSliderCode_mixerC]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void JucePdAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == oneShotActive)
    {
        //[UserButtonCode_oneShotActive] -- add your button handler code here..
        //[/UserButtonCode_oneShotActive]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void JucePdAudioProcessorEditor::buttonStateChanged(Button* button)
{
    int numParams = sizeof(PDMessages) / sizeof(PDMessageInfo);
    for(int i = 0; i < numParams; ++i)
    {
        dontUpdate = true;
        if(button->getName() == PDMessages[i].name)
            getAudioProcessor()->setParameterNotifyingHost(i, button->isDown() ?  0 : 1);
        dontUpdate = false;
    }
}

void JucePdAudioProcessorEditor::audioProcessorParameterChanged (AudioProcessor *processor, int parameterIndex, float newValue)
{
    if(!dontUpdate)
    {
        for(int i = 0; i < getNumChildComponents(); ++i)
        {
            //TODO: doesn't work for grand-children
            Component* child = getChildComponent(i);
            if(child->getName() == PDMessages[parameterIndex].name)
            {
                Slider* slider = dynamic_cast<Slider*> (child);
                // if it's not a slider, don't worry.
                if(slider)
                {
                    slider->setValue(newValue, false);
                }
            }
        }
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="JucePdAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public AudioProcessorListener"
                 constructorParams="JucePdAudioProcessor* proc" variableInitialisers="AudioProcessorEditor(proc)"
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <IMAGE pos="0 0 600 400" resource="soundFxMachine_png" opacity="1" mode="0"/>
  </BACKGROUND>
  <SLIDER name="Sound Hi/Lo" id="624194eabe6c323" memberName="sound" virtualName=""
          explicitFocusOrder="0" pos="270 263 60 60" rotarysliderfill="ff000000"
          rotaryslideroutline="ff000000" min="0" max="1" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Speed Range" id="4d81e27a041b2d65" memberName="speedRange"
          virtualName="" explicitFocusOrder="0" pos="50 263 60 60" rotarysliderfill="ff000000"
          rotaryslideroutline="ff000000" min="0" max="1" int="0.33333"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Speed Fast/Slow" id="12e327e847c7d5fa" memberName="speedFastSlow"
          virtualName="" explicitFocusOrder="0" pos="145 263 60 60" rotarysliderfill="ff000000"
          rotaryslideroutline="ff000000" min="0" max="1" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Tone Hi/Lo" id="6784cdef3568f4a6" memberName="toneHiLo"
          virtualName="" explicitFocusOrder="0" pos="480 263 60 60" rotarysliderfill="ff000000"
          rotaryslideroutline="ff000000" min="0" max="1" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Tone Range" id="d20bf14e0e1275df" memberName="toneRange"
          virtualName="" explicitFocusOrder="0" pos="379 263 60 60" rotarysliderfill="ff000000"
          rotaryslideroutline="ff000000" min="0" max="1" int="0.3333" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="One Shot On/Off" id="311c18edd009e3d1" memberName="oneShot"
          virtualName="" explicitFocusOrder="0" pos="154 151 16 56" thumbcol="ff00c4e8"
          trackcol="ff101114" min="0" max="1" int="1" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="One Shot Activator" id="3ce1da508a956fc7" memberName="oneShotActive"
              virtualName="" explicitFocusOrder="0" pos="196 151 56 56" bgColOff="ff292937"
              bgColOn="ff101016" buttonText="" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="One Shot Short/Long" id="77a9de0f874450b4" memberName="oneShotShortLong"
          virtualName="" explicitFocusOrder="0" pos="271 151 60 60" bkgcol="ff000000"
          thumbcol="0" trackcol="ff000000" rotarysliderfill="ff000000"
          rotaryslideroutline="ff000000" textboxhighlight="1111ee" textboxoutline="808080"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Fade Out Short/Long" id="a3eab8fe791f0260" memberName="fadeOutShortLong"
          virtualName="" explicitFocusOrder="0" pos="379 151 60 60" bkgcol="ff000000"
          thumbcol="bbbbff" rotarysliderfill="ff000000" rotaryslideroutline="ff000000"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Mixer A" id="f1c5de55ecfa03e1" memberName="mixera" virtualName=""
          explicitFocusOrder="0" pos="220 40 16 56" thumbcol="ffffce00"
          trackcol="ff252716" min="0" max="1" int="1" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Mixer B" id="6d06385f468b0a1d" memberName="mixerb" virtualName=""
          explicitFocusOrder="0" pos="296 40 16 56" thumbcol="ffffce00"
          trackcol="ff1d1c14" min="0" max="1" int="1" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Mixer C" id="d4a416d9fdc34b1a" memberName="mixerC" virtualName=""
          explicitFocusOrder="0" pos="369 40 16 56" thumbcol="ffffce00"
          trackcol="ff141410" min="0" max="1" int="1" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: soundFxMachine_png, 29493, "../../../../Downloads/soundFX MACHINE.png"
static const unsigned char resource_JucePdAudioProcessorEditor_soundFxMachine_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,2,88,0,0,1,144,8,6,0,0,0,114,53,30,152,0,0,0,1,115,82,71,66,0,
174,206,28,233,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,14,196,0,0,14,196,1,149,43,14,27,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,65,100,111,98,101,32,73,109,
97,103,101,82,101,97,100,121,113,201,101,60,0,0,114,165,73,68,65,84,120,94,237,157,7,120,20,85,247,198,15,45,64,66,21,233,61,244,174,20,149,34,72,83,65,68,4,65,62,62,81,154,93,164,89,80,236,138,96,5,68,
176,129,253,143,136,162,128,40,126,210,20,69,84,154,32,210,164,23,233,157,4,164,237,127,222,27,103,51,187,217,205,246,217,153,157,247,62,79,158,36,59,183,156,251,59,179,51,239,156,91,38,135,136,184,180,
31,38,18,32,1,18,32,1,18,32,1,18,32,129,40,17,200,25,165,122,88,13,9,144,0,9,144,0,9,144,0,9,144,192,191,4,40,176,120,42,144,0,9,144,0,9,144,0,9,144,64,148,9,80,96,69,25,40,171,35,1,18,32,1,18,32,1,18,
32,1,10,44,158,3,36,64,2,36,64,2,36,64,2,36,16,101,2,20,88,81,6,202,234,72,128,4,72,128,4,72,128,4,72,128,2,139,231,0,9,144,0,9,144,0,9,144,0,9,68,153,0,5,86,148,129,178,58,18,32,1,18,32,1,18,32,1,18,
160,192,226,57,64,2,36,64,2,36,64,2,36,64,2,81,38,64,129,21,101,160,172,142,4,72,128,4,72,128,4,72,128,4,40,176,120,14,196,148,192,200,199,251,203,248,209,119,100,219,198,250,57,221,221,199,145,119,233,
151,189,221,255,227,239,249,83,250,123,148,199,103,51,38,103,214,185,123,97,71,185,176,172,102,150,159,59,251,101,212,235,125,252,216,207,45,178,216,132,54,244,58,80,127,213,170,85,98,202,69,175,28,253,
208,237,52,165,65,155,53,130,243,199,219,183,56,95,218,183,109,105,179,158,196,214,92,112,2,23,157,149,175,115,60,182,22,176,118,18,32,1,111,2,20,88,60,39,98,78,224,222,118,139,252,138,136,15,198,223,
41,213,139,255,225,215,134,71,95,223,46,173,171,47,150,135,6,103,136,46,220,72,170,151,220,42,15,140,154,239,81,102,212,204,230,146,179,241,122,143,159,183,222,253,204,157,199,120,252,245,57,53,4,54,233,
117,66,212,213,44,189,71,174,121,184,132,84,239,121,86,10,230,59,45,47,63,210,54,230,92,32,226,90,215,90,43,29,154,23,141,121,91,118,110,96,207,137,84,183,95,225,31,164,123,123,213,180,115,151,162,106,
59,206,223,71,110,88,44,115,87,21,117,115,122,104,82,105,105,223,224,72,150,135,147,168,54,204,202,72,128,4,178,37,64,129,197,19,196,20,2,47,14,216,147,37,234,0,177,212,187,233,15,217,182,63,119,254,34,
153,48,175,165,12,186,225,144,138,42,221,215,97,131,64,32,109,218,180,57,108,187,71,60,59,89,22,110,108,46,205,234,229,87,117,148,47,46,178,116,75,57,65,91,168,183,102,135,207,164,75,255,183,195,174,63,
216,130,125,255,115,149,202,10,145,101,86,196,44,88,219,172,154,15,254,129,144,168,89,230,136,85,77,52,213,46,68,63,241,176,208,115,84,21,25,56,60,243,156,197,195,69,167,129,43,100,215,161,220,166,218,
195,198,72,128,4,50,9,80,96,241,108,136,57,1,68,32,246,28,43,45,227,31,40,233,110,171,71,183,235,212,83,247,242,157,77,2,182,175,223,56,126,120,167,134,108,220,87,89,32,144,162,153,254,220,118,94,137,
28,179,135,234,186,53,59,46,31,46,170,45,39,255,41,36,131,6,196,62,98,22,77,102,241,172,11,145,25,136,44,38,145,30,237,10,169,135,133,105,211,191,206,130,3,98,244,182,129,111,17,19,9,144,64,156,8,80,96,
197,9,188,211,154,29,248,242,62,41,93,120,143,26,178,64,180,102,204,125,46,117,99,152,244,213,233,160,80,124,241,107,57,41,93,112,139,124,150,125,192,43,168,186,16,57,195,176,35,132,21,18,4,27,132,206,
27,247,252,161,230,127,153,33,180,32,48,49,52,58,110,210,124,65,223,32,26,152,124,19,128,223,141,243,176,112,30,129,27,147,168,161,237,181,59,114,17,5,9,144,128,5,9,80,96,89,208,41,137,104,18,134,223,
48,47,4,194,102,249,135,165,85,23,239,124,226,251,160,187,170,11,144,107,46,75,242,89,6,209,48,227,77,216,56,81,30,5,140,199,241,55,134,29,141,145,48,68,201,48,135,235,151,13,249,149,208,10,52,49,63,104,
195,253,100,188,238,170,114,74,96,34,202,48,107,238,122,37,182,204,16,118,145,218,29,143,242,198,57,88,240,209,194,117,181,5,209,76,38,18,32,1,18,176,50,1,10,44,43,123,39,193,108,195,188,16,8,155,130,
73,7,101,200,235,57,130,158,71,5,177,131,168,197,240,143,155,120,76,120,55,226,241,158,228,222,228,198,143,60,232,233,199,241,251,196,153,139,253,70,64,32,180,48,159,5,243,90,98,181,82,13,17,188,46,141,
254,148,255,253,118,70,217,8,241,9,177,197,201,238,193,157,240,88,224,128,168,22,162,128,78,79,235,247,148,150,218,21,50,34,177,76,36,64,2,214,34,64,129,101,45,127,36,188,53,186,128,241,53,103,196,87,
231,33,70,110,109,185,86,13,225,189,56,246,35,249,104,73,43,247,132,247,112,96,33,106,133,249,96,143,15,106,231,46,238,29,173,210,109,75,173,152,57,103,44,156,182,252,149,193,228,118,136,204,209,183,44,
117,71,221,16,217,235,220,96,17,39,187,135,0,186,104,225,228,16,114,39,102,214,105,243,142,171,135,14,95,98,19,223,157,88,71,98,19,147,42,123,69,2,209,33,64,129,21,29,142,172,37,4,2,193,138,43,84,137,
237,18,48,177,93,159,232,254,236,184,121,170,165,72,38,133,143,209,118,111,192,234,69,68,168,240,211,245,242,93,106,238,149,190,146,15,123,83,33,202,53,127,209,138,16,122,21,124,214,171,27,158,81,145,
60,239,109,37,208,102,36,253,10,222,2,123,231,196,57,17,75,255,216,137,142,30,21,158,250,200,102,15,49,133,225,230,217,227,27,170,185,125,92,161,106,39,143,210,214,68,34,64,129,149,72,222,76,176,190,96,
159,42,68,117,176,23,150,158,48,103,105,220,204,98,106,8,207,248,212,238,61,7,11,243,177,48,153,221,87,194,77,9,171,23,177,170,17,195,115,125,158,59,169,178,109,156,154,71,69,148,154,164,238,82,243,197,
34,217,10,194,159,43,112,227,107,84,126,169,154,119,229,157,16,165,131,216,99,242,36,224,61,201,61,150,254,177,35,123,60,124,96,232,27,98,74,159,135,136,109,81,212,118,22,218,150,35,177,56,143,237,200,
137,54,147,128,217,4,114,104,13,186,204,110,148,237,145,0,9,144,0,9,144,0,9,144,64,34,19,96,4,43,145,189,203,190,145,0,9,144,0,9,144,0,9,196,133,0,35,88,113,193,158,216,141,14,29,248,95,169,85,57,69,202,
20,115,73,153,34,233,137,221,89,246,142,4,72,192,182,4,54,236,41,32,39,210,93,178,110,107,154,188,58,254,255,108,219,15,26,110,77,2,20,88,214,244,139,237,172,74,77,173,44,143,220,215,94,122,54,253,67,
82,242,112,211,76,219,57,144,6,147,128,195,9,164,157,45,42,83,151,212,147,81,175,207,149,45,91,182,58,156,6,187,31,13,2,20,88,209,160,232,240,58,186,117,185,86,70,223,157,44,85,138,173,117,56,9,118,159,
4,72,192,238,4,54,31,170,45,195,223,72,151,233,51,190,181,123,87,104,127,156,9,80,96,197,217,1,118,111,30,226,234,253,135,143,49,106,101,119,71,210,126,18,32,1,55,1,68,179,250,188,80,152,34,139,231,68,
68,4,40,176,34,194,231,236,194,24,22,92,245,127,165,40,174,156,125,26,176,247,36,144,144,4,32,178,26,252,119,47,135,11,19,210,187,230,116,138,171,8,205,225,156,144,173,188,63,234,42,138,171,132,244,44,
59,69,2,36,128,185,164,184,198,49,145,64,184,4,40,176,194,37,231,240,114,253,111,235,38,45,170,44,113,56,5,118,159,4,72,32,145,9,224,26,135,107,29,19,9,132,67,128,2,43,28,106,44,35,93,219,92,68,10,36,
64,2,36,144,240,4,120,173,75,120,23,199,172,131,156,131,21,51,180,137,93,49,94,201,193,68,2,36,64,2,78,32,128,247,134,50,145,64,168,4,24,193,10,149,24,243,51,100,206,115,128,4,72,192,81,4,56,76,232,40,
119,71,173,179,20,88,81,67,233,156,138,202,151,46,228,156,206,178,167,36,64,2,142,39,192,107,158,227,79,129,176,0,80,96,133,133,205,217,133,202,150,200,227,108,0,17,246,126,207,137,84,185,123,98,61,193,
176,3,126,240,247,137,51,23,171,90,103,173,106,41,215,60,92,194,227,56,62,115,114,26,53,179,185,155,85,207,81,85,100,227,129,122,10,7,56,130,159,241,56,254,118,90,34,159,216,123,156,215,188,216,51,78,
196,22,40,176,18,209,171,236,147,165,9,12,121,29,83,31,69,48,143,237,216,207,45,228,200,177,116,121,104,82,105,183,205,115,231,47,146,102,151,94,164,142,127,48,254,78,121,96,212,124,75,247,39,150,198,
77,152,215,82,190,255,249,47,217,189,176,163,226,209,160,118,41,233,52,112,133,91,144,162,237,29,187,143,171,99,235,231,116,151,17,207,78,118,11,176,88,218,101,149,186,201,199,42,158,160,29,36,144,149,
0,5,22,207,10,18,48,145,0,162,47,211,166,127,45,47,14,216,163,90,45,152,116,80,158,25,144,44,111,189,251,153,138,200,32,85,173,90,69,122,55,253,65,253,221,174,238,78,217,180,105,179,251,152,137,166,90,
162,169,113,147,230,203,240,254,213,164,116,193,45,202,158,71,110,88,172,126,47,92,87,219,109,223,144,238,25,127,86,47,254,135,180,111,219,82,214,255,93,212,18,182,155,97,4,249,152,65,153,109,144,64,120,
4,40,176,194,227,198,82,36,16,51,2,149,43,150,141,89,221,137,88,113,193,124,105,137,216,173,168,245,137,124,162,134,146,21,145,64,72,4,40,176,66,194,197,204,36,16,25,1,68,89,122,116,187,206,61,36,136,
185,87,79,76,74,151,59,251,117,119,71,105,34,107,33,177,74,15,26,208,86,70,79,254,203,29,193,211,231,88,181,174,197,23,139,195,211,228,147,88,231,59,123,147,88,4,40,176,18,203,159,236,141,13,8,140,185,
207,165,172,196,4,237,194,205,126,146,162,133,147,221,67,134,54,48,223,84,19,239,109,183,72,174,106,86,77,202,182,254,70,241,90,181,118,175,204,30,223,80,13,173,50,137,144,15,207,2,18,176,46,1,110,52,
106,93,223,88,214,178,119,94,189,67,250,183,92,100,89,251,104,24,9,144,0,9,68,147,192,228,69,45,229,246,161,111,71,179,74,214,229,0,2,140,96,57,192,201,236,34,9,144,0,9,144,0,9,144,128,185,4,40,176,204,
229,205,214,72,128,4,72,128,4,72,128,4,28,64,128,2,203,1,78,102,23,73,128,4,72,128,4,72,128,4,204,37,64,129,101,46,111,182,70,2,36,64,2,36,64,2,36,224,0,2,20,88,14,112,50,187,72,2,36,64,2,36,64,2,36,96,
46,1,10,44,115,121,179,53,18,32,1,18,32,1,18,32,1,7,16,160,192,114,128,147,217,69,18,32,1,18,32,1,18,32,1,115,9,80,96,153,203,155,173,145,0,9,144,0,9,144,0,9,56,128,0,5,150,3,156,204,46,146,0,9,144,0,
9,144,0,9,152,75,128,2,203,92,222,108,141,4,72,128,4,72,128,4,72,192,1,4,40,176,28,224,100,118,145,4,72,128,4,72,128,4,72,192,92,2,20,88,230,242,102,107,36,64,2,36,64,2,36,64,2,14,32,64,129,229,0,39,179,
139,36,64,2,36,64,2,36,64,2,230,18,160,192,50,151,55,91,35,1,18,32,1,18,32,1,18,112,0,1,10,44,7,56,153,93,36,1,18,32,1,18,32,1,18,48,151,0,5,150,185,188,217,26,9,144,0,9,144,0,9,144,128,3,8,80,96,57,192,
201,236,34,9,144,0,9,144,0,9,144,128,185,4,40,176,204,229,205,214,72,128,4,72,128,4,72,128,4,28,64,128,2,203,1,78,102,23,73,128,4,72,128,4,72,128,4,204,37,64,129,101,46,111,182,70,2,36,64,2,36,64,2,36,
224,0,2,20,88,14,112,50,187,72,2,36,64,2,36,64,2,36,96,46,1,10,44,115,121,179,53,18,32,1,18,32,1,18,32,1,7,16,160,192,114,128,147,217,69,18,32,1,18,32,1,18,32,1,115,9,80,96,153,203,155,173,145,0,9,144,
0,9,144,0,9,56,128,0,5,150,3,156,204,46,146,0,9,144,0,9,144,0,9,152,75,128,2,203,92,222,108,141,4,72,128,4,72,128,4,72,192,1,4,40,176,28,224,100,118,145,4,72,128,4,72,128,4,72,192,92,2,20,88,230,242,102,
107,36,64,2,36,64,2,36,64,2,14,32,64,129,229,0,39,179,139,36,64,2,36,64,2,36,64,2,230,18,160,192,50,151,55,91,35,1,18,32,1,18,32,1,18,112,0,1,10,44,7,56,153,93,36,1,18,32,1,18,32,1,18,48,151,0,5,150,185,
188,217,26,9,144,0,9,144,0,9,144,128,3,8,80,96,57,192,201,236,34,9,144,0,9,144,0,9,144,128,185,4,40,176,204,229,205,214,72,128,4,72,128,4,72,128,4,28,64,128,2,203,1,78,102,23,73,128,4,72,128,4,72,128,
4,204,37,64,129,101,46,111,182,70,2,36,64,2,36,64,2,36,224,0,2,20,88,14,112,50,187,72,2,36,64,2,36,64,2,36,96,46,1,10,44,115,121,179,53,18,32,1,18,32,1,18,32,1,7,16,160,192,114,128,147,217,69,18,32,1,
18,32,1,18,32,1,115,9,80,96,153,203,155,173,145,0,9,144,0,9,144,0,9,56,128,0,5,150,3,156,204,46,146,0,9,144,0,9,144,0,9,152,75,128,2,203,92,222,108,141,4,72,128,4,72,128,4,72,192,1,4,40,176,28,224,100,
118,145,4,72,128,4,72,128,4,72,192,92,2,20,88,230,242,102,107,36,64,2,36,64,2,36,64,2,14,32,64,129,229,0,39,179,139,36,64,2,36,64,2,36,64,2,230,18,160,192,50,151,55,91,35,1,18,32,1,18,32,1,18,112,0,1,
10,44,7,56,153,93,36,1,18,32,1,18,32,1,18,48,151,0,5,150,185,188,217,26,9,144,0,9,144,0,9,144,128,3,8,80,96,57,192,201,236,34,9,144,0,9,144,0,9,144,128,185,4,40,176,204,229,205,214,72,128,4,72,128,4,72,
128,4,28,64,128,2,203,1,78,102,23,73,128,4,72,128,4,72,128,4,204,37,64,129,101,46,111,182,70,2,36,64,2,36,64,2,36,224,0,2,20,88,14,112,50,187,72,2,36,64,2,36,64,2,36,96,46,1,10,44,115,121,179,53,18,32,
1,18,32,1,18,32,1,7,16,160,192,114,128,147,217,69,18,32,1,18,32,1,18,32,1,115,9,80,96,153,203,155,173,145,0,9,144,0,9,144,0,9,56,128,0,5,150,3,156,204,46,218,139,192,132,121,45,37,103,227,245,82,189,231,
89,217,115,34,85,253,224,111,124,134,99,76,153,4,22,110,108,174,184,224,7,127,35,245,28,85,69,253,143,223,78,79,228,227,244,51,128,253,143,39,1,10,172,120,210,103,219,36,224,131,192,192,225,111,203,252,
41,253,229,147,151,154,201,137,211,41,50,111,77,121,105,216,160,166,28,251,185,133,148,47,78,100,70,2,211,230,29,151,241,163,239,144,245,115,186,75,161,252,103,100,249,206,38,50,109,250,215,138,85,175,
142,101,229,196,153,139,29,13,140,124,28,237,126,118,62,206,4,40,176,226,236,0,54,79,2,190,8,64,44,52,42,191,84,170,23,255,67,29,46,90,56,89,10,38,29,148,206,13,22,17,152,23,129,66,41,57,20,39,240,210,
147,206,10,191,157,158,200,199,233,103,0,251,31,47,2,20,88,241,34,207,118,73,128,4,72,128,4,72,128,4,18,150,0,5,86,194,186,150,29,179,42,1,204,169,186,123,98,61,247,220,33,252,173,15,101,93,243,112,9,
101,118,147,27,63,18,252,61,107,85,75,185,109,224,91,242,214,187,159,169,252,248,223,105,105,212,204,204,121,86,152,87,181,241,64,61,133,0,159,131,11,248,128,13,184,130,27,18,254,199,113,39,36,242,113,
130,151,217,71,59,18,160,192,178,163,215,104,179,173,9,12,121,61,135,178,255,194,178,140,121,85,71,142,165,203,67,147,74,171,207,254,247,194,126,245,123,233,151,189,213,223,24,18,252,96,252,157,114,103,
191,238,42,191,211,134,8,49,169,255,251,159,255,146,221,11,59,170,254,55,168,93,74,58,13,92,161,4,233,35,55,44,86,92,192,7,199,74,23,220,162,184,233,108,113,60,209,19,249,36,186,135,217,63,59,19,160,192,
178,179,247,226,100,251,238,253,103,227,212,178,253,155,69,244,5,147,176,95,28,176,71,117,6,115,132,158,25,144,172,34,49,136,192,48,121,18,24,55,105,190,12,239,95,77,137,39,36,93,52,45,92,87,155,168,52,
2,228,99,206,105,192,107,158,57,156,19,173,21,10,172,68,243,168,9,253,217,185,231,184,9,173,176,9,18,32,1,18,176,6,1,94,243,172,225,7,187,89,65,129,101,55,143,89,192,222,201,31,76,183,128,21,246,52,1,
171,221,122,116,187,206,61,36,136,161,174,39,38,165,171,161,46,61,74,99,207,158,197,198,234,65,3,218,202,232,201,127,185,163,123,250,188,170,214,181,214,198,166,65,155,213,74,62,230,56,140,215,60,115,
56,39,90,43,20,88,137,230,81,147,250,51,231,207,43,77,106,41,241,154,25,115,159,75,117,10,19,177,11,55,251,73,109,193,160,15,25,38,94,111,35,235,209,189,237,22,201,85,205,170,73,217,214,223,40,94,171,
214,238,149,217,227,27,170,161,85,38,17,242,137,253,89,192,107,93,236,25,39,106,11,152,109,155,113,181,103,34,129,16,8,244,191,173,155,188,51,240,207,16,74,48,43,9,144,0,9,216,143,192,237,227,235,8,35,
88,246,243,155,21,44,166,192,178,130,23,108,106,195,162,79,251,74,139,42,75,108,106,61,205,38,1,18,32,129,236,9,252,180,185,169,180,188,249,61,98,34,129,176,8,80,96,133,133,141,133,64,32,53,181,178,172,
250,191,82,146,146,231,8,129,144,0,9,144,64,66,17,72,59,91,84,26,252,119,175,108,217,178,53,161,250,197,206,152,71,128,115,176,204,99,157,112,45,225,194,211,231,133,194,130,11,17,19,9,144,0,9,36,10,1,
92,211,112,109,163,184,74,20,143,198,167,31,185,180,102,159,138,79,211,108,53,17,8,172,91,191,73,54,30,170,43,141,234,148,145,139,146,15,36,66,151,216,7,18,32,1,7,19,216,124,168,182,220,55,54,151,76,159,
241,173,131,41,176,235,209,32,192,33,194,104,80,100,29,106,184,240,145,251,218,75,207,166,127,112,200,144,231,3,9,144,128,237,8,32,106,53,117,73,61,25,245,250,92,70,174,108,231,61,107,26,76,129,101,77,
191,216,218,170,161,3,255,43,181,42,167,72,193,228,28,82,163,244,73,91,247,133,198,147,0,9,36,46,129,13,123,10,200,137,116,151,172,219,154,38,175,142,255,191,196,237,40,123,22,23,2,20,88,113,193,206,70,
73,128,4,72,128,4,72,128,4,18,153,0,39,185,39,178,119,217,55,18,32,1,18,32,1,18,32,129,184,16,160,192,138,11,118,54,74,2,36,64,2,36,64,2,36,144,200,4,40,176,18,217,187,236,27,9,144,0,9,144,0,9,144,64,
92,8,80,96,197,5,59,27,37,1,18,32,1,18,32,1,18,72,100,2,20,88,137,236,93,246,141,4,72,128,4,72,128,4,72,32,46,4,40,176,226,130,157,141,146,0,9,144,0,9,144,0,9,36,50,1,10,172,68,246,46,251,70,2,36,64,2,
36,64,2,36,16,23,2,20,88,113,193,206,70,73,128,4,72,128,4,72,128,4,18,153,0,55,26,77,100,239,90,168,111,247,62,246,140,228,107,114,141,108,43,90,78,89,85,232,236,41,41,242,219,108,25,243,200,96,15,43,
31,156,182,64,150,189,245,188,44,156,63,207,227,115,148,119,53,239,34,19,59,212,87,159,223,51,103,181,236,75,41,150,165,135,73,239,61,41,159,188,55,201,227,243,214,109,219,73,195,251,71,186,219,78,93,
57,71,94,26,52,64,229,193,177,139,158,252,64,14,63,125,91,150,54,187,45,218,45,222,245,5,211,15,127,182,161,61,95,246,89,200,77,52,197,38,4,238,127,244,46,41,208,38,45,139,181,121,254,42,33,79,223,253,
138,199,231,79,190,49,76,254,250,117,183,76,121,127,106,150,207,207,86,219,239,254,44,239,217,36,57,179,174,160,140,28,58,214,253,89,235,54,173,164,233,163,21,124,82,121,190,221,71,126,105,61,56,114,160,
20,104,152,46,255,228,57,163,242,164,28,45,42,251,86,156,145,215,158,127,211,93,6,125,40,113,69,14,121,172,243,27,89,236,194,7,232,199,115,179,238,150,244,100,223,111,131,216,246,241,217,44,125,178,137,
251,104,166,67,8,48,130,229,16,71,199,179,155,67,70,141,149,189,87,247,151,11,107,151,200,244,150,101,213,79,242,194,41,146,179,118,83,25,54,243,87,15,211,210,10,94,172,196,80,213,170,85,2,154,92,234,
187,201,238,250,244,122,189,197,21,42,185,172,207,32,201,249,79,154,202,123,102,236,32,73,171,126,153,64,40,133,154,130,237,7,68,160,110,143,46,170,178,179,47,84,59,152,159,4,64,32,57,189,128,64,228,24,
127,188,197,21,190,71,57,43,29,149,106,151,151,245,9,13,130,76,47,127,232,199,60,146,92,225,130,140,252,252,254,44,223,191,37,207,239,200,210,150,63,47,60,55,101,176,20,174,119,78,80,159,94,247,209,13,
46,41,118,229,89,25,241,234,224,144,156,7,241,165,215,129,130,16,85,250,255,222,130,49,164,138,153,153,4,76,32,64,129,101,2,100,39,55,241,159,190,3,100,71,243,238,74,216,24,163,85,19,158,123,66,102,14,
235,37,167,146,242,203,131,227,60,35,78,136,114,221,248,252,59,81,195,118,226,226,138,146,190,250,39,85,223,87,95,124,174,162,96,104,63,148,20,78,63,66,169,159,121,73,32,22,4,58,246,104,175,170,133,200,
10,244,208,130,232,210,123,195,191,22,87,210,89,185,177,111,199,176,204,65,228,74,10,252,35,239,15,253,206,35,90,245,210,136,241,178,252,157,125,226,170,127,72,110,191,191,111,88,117,179,16,9,216,141,
0,5,150,221,60,102,51,123,43,180,185,65,170,110,95,161,132,141,119,218,180,105,179,228,88,60,67,14,214,189,202,227,16,134,240,182,148,170,145,69,120,133,219,245,130,59,215,170,225,73,12,7,134,155,194,
233,71,184,109,177,28,9,68,139,64,201,134,73,114,114,69,178,228,210,134,255,130,17,77,248,78,30,251,35,183,26,222,11,39,161,28,202,163,30,239,52,235,139,217,130,136,89,133,75,139,134,83,53,203,144,128,
237,8,80,96,217,206,101,246,50,24,209,163,51,187,178,94,108,245,94,236,88,187,90,142,231,201,239,33,126,210,15,252,45,69,166,143,145,45,151,118,16,12,203,69,154,94,184,163,167,228,62,190,95,205,181,122,
248,237,169,97,9,173,112,250,17,169,221,44,79,2,145,16,232,220,181,147,164,21,57,34,95,190,247,141,18,61,69,106,96,202,109,224,180,251,175,3,106,238,20,230,95,133,146,144,31,229,80,222,95,74,63,124,70,
114,20,59,21,74,181,204,75,2,182,37,64,129,101,91,215,37,182,225,147,199,189,44,21,22,127,166,134,23,251,15,122,192,103,103,49,175,11,19,209,245,31,76,144,247,151,94,232,125,189,172,234,215,82,36,127,
138,18,90,24,242,51,38,124,102,172,11,127,51,145,128,149,9,96,242,247,163,243,122,123,252,244,234,211,211,109,114,189,22,85,37,255,206,226,42,154,180,108,254,106,37,182,140,199,67,233,27,38,186,27,219,
82,67,129,76,36,64,2,217,18,160,192,226,9,18,83,2,5,15,110,151,164,114,254,39,172,87,168,93,95,173,40,244,94,53,8,163,48,103,171,234,250,31,229,104,183,33,146,92,188,76,22,59,189,39,185,191,212,163,77,
182,125,193,141,6,66,11,194,173,104,143,251,61,242,98,21,161,62,17,221,56,65,93,207,20,73,63,98,10,152,149,59,150,128,175,73,238,250,196,111,204,183,74,170,117,66,118,172,60,162,248,44,92,240,131,18,91,
254,38,187,27,33,150,173,86,92,176,162,16,101,244,228,61,201,29,115,170,188,19,242,163,28,202,251,75,201,23,37,137,235,80,126,199,250,140,29,119,22,1,10,44,103,249,219,244,222,238,88,48,83,54,85,108,40,
215,119,189,41,75,219,184,9,96,235,133,139,215,124,239,215,46,12,239,165,238,221,160,134,11,195,73,104,195,123,152,113,239,198,53,62,183,120,200,174,254,72,251,17,142,237,44,67,2,225,18,192,228,118,12,
215,21,239,124,206,29,121,58,85,254,128,96,91,134,236,38,187,227,24,86,0,94,216,86,36,172,166,49,223,11,229,125,181,129,33,75,180,175,139,190,83,39,255,145,243,154,141,222,121,243,20,62,47,231,78,157,
15,171,125,22,34,1,43,17,160,192,178,146,55,18,208,22,108,155,128,136,81,210,224,113,30,66,7,219,36,220,240,202,20,201,127,230,148,123,79,42,127,221,255,242,209,219,165,210,145,93,97,209,105,114,101,107,
53,204,168,175,84,196,197,188,76,151,219,149,104,11,37,69,163,31,161,180,199,188,36,16,9,129,18,117,243,201,217,95,139,100,217,90,1,17,38,127,147,221,177,47,85,223,209,215,73,142,51,121,228,255,94,153,
17,86,243,42,178,117,50,175,244,121,245,106,65,125,122,194,144,98,163,219,75,74,142,213,197,228,157,215,222,83,31,227,55,38,223,247,121,230,122,143,124,233,37,14,201,207,179,87,134,213,62,11,145,128,149,
8,80,96,89,201,27,9,106,11,134,250,48,156,135,125,175,244,121,78,233,173,123,169,125,177,94,185,225,242,128,189,198,208,222,138,215,70,40,49,102,76,222,115,176,80,183,247,254,86,16,70,216,220,243,66,165,
122,170,237,6,239,46,82,85,96,51,211,80,83,164,253,8,181,61,230,39,129,112,8,96,158,21,68,10,230,93,121,39,61,194,164,127,142,136,146,62,183,10,251,84,165,239,200,41,35,110,122,45,203,42,64,239,57,88,
40,227,111,18,252,99,189,198,170,73,245,168,79,175,27,19,236,177,47,150,113,19,83,216,48,127,236,90,101,138,158,15,209,47,236,117,101,28,158,12,135,1,203,144,128,21,8,112,39,119,43,120,129,54,144,0,9,
144,0,9,144,0,9,36,20,1,70,176,18,202,157,236,12,9,144,0,9,144,0,9,144,128,21,8,80,96,89,193,11,180,129,4,72,128,4,72,128,4,72,32,161,8,112,136,48,161,220,25,223,206,244,184,181,175,84,190,170,147,28,
43,83,93,14,36,95,100,170,49,169,251,55,201,75,55,101,221,24,113,232,203,19,101,251,101,55,152,106,11,27,115,30,1,156,127,39,150,205,147,239,166,125,44,91,182,108,141,42,128,161,79,221,43,197,234,231,
148,180,66,71,163,90,47,43,243,36,144,188,187,184,236,249,243,164,76,120,241,109,162,33,129,168,16,160,192,138,10,70,103,87,146,154,90,89,186,63,59,81,54,149,175,31,55,16,20,88,113,67,207,134,13,4,138,
167,31,150,195,83,94,149,105,31,102,172,148,139,36,117,186,161,163,52,189,173,10,133,85,36,16,195,40,155,114,176,152,76,126,116,102,212,133,114,24,166,176,136,205,9,112,136,208,230,14,140,183,249,16,87,
55,140,155,22,87,113,21,111,6,108,159,4,116,2,136,220,158,31,240,156,220,53,252,241,136,160,64,92,53,190,187,52,197,85,68,20,195,43,156,118,241,33,233,255,114,39,193,181,141,137,4,34,33,64,129,21,9,61,
135,151,213,197,213,142,194,89,119,89,119,56,26,118,223,225,4,14,116,212,246,148,186,119,80,88,20,240,189,66,228,234,76,238,51,97,149,103,161,200,9,96,56,246,182,225,93,35,175,136,53,56,154,0,5,150,163,
221,31,89,231,111,26,246,180,80,92,69,198,144,165,19,151,192,249,110,247,135,21,5,233,113,87,103,70,174,44,112,90,252,147,186,95,110,238,221,221,2,150,208,4,187,18,160,192,178,171,231,226,108,119,171,
214,109,100,115,189,182,113,182,130,205,147,128,117,9,164,229,206,39,120,8,9,37,33,122,149,179,225,225,80,138,48,111,12,9,212,235,81,44,134,181,179,234,68,39,64,129,149,232,30,142,81,255,174,232,125,111,
140,106,102,181,36,144,56,4,246,214,106,30,82,20,11,209,43,38,235,16,72,207,159,198,40,150,117,220,97,59,75,40,176,108,231,50,107,24,188,167,210,37,214,48,132,86,144,128,133,9,32,138,117,117,143,91,130,
182,176,64,173,127,130,206,203,140,230,16,168,125,101,5,115,26,98,43,9,71,128,2,43,225,92,26,251,14,93,215,229,70,193,141,131,137,4,72,32,48,129,66,229,171,5,206,164,229,104,213,250,74,65,196,132,201,
90,4,114,149,166,79,172,229,17,251,88,67,129,101,31,95,89,198,210,18,101,249,68,103,25,103,208,16,203,19,112,149,172,24,148,141,85,106,113,91,128,160,64,153,156,9,162,23,226,151,137,4,66,37,64,129,21,
42,49,230,151,162,149,107,132,69,161,212,119,147,101,122,203,178,234,231,204,216,65,82,233,200,46,85,79,201,180,67,234,51,227,113,252,205,68,2,78,34,80,162,82,81,39,117,215,86,125,45,85,174,148,173,236,
165,177,214,32,64,129,101,13,63,36,188,21,21,22,127,38,107,151,44,146,123,230,172,150,110,139,118,75,133,218,245,101,230,176,94,82,232,236,41,119,223,15,239,222,161,142,13,155,249,171,76,120,238,9,183,
0,75,120,56,236,32,9,104,4,242,23,201,77,14,22,37,112,113,105,138,95,139,186,198,210,102,81,96,89,218,61,137,99,220,87,147,199,203,101,125,6,201,190,148,140,101,207,123,175,238,175,126,151,216,188,204,
221,201,50,93,110,87,127,111,43,90,78,90,183,109,39,185,247,69,247,157,110,137,67,147,61,73,68,2,185,11,157,79,196,110,37,68,159,10,94,156,63,33,250,193,78,152,75,128,2,203,92,222,108,45,27,2,167,146,
120,17,227,9,66,2,36,64,2,36,144,24,4,40,176,18,195,143,150,239,197,245,253,7,202,111,239,143,83,243,173,144,244,57,86,251,171,52,182,188,237,52,144,4,72,128,4,72,128,4,66,37,64,129,21,42,49,230,15,139,
192,142,230,221,165,118,211,150,50,177,67,125,53,161,125,199,218,213,114,195,43,83,228,120,30,70,173,194,2,202,66,36,64,2,36,64,2,150,38,64,129,101,105,247,36,150,113,152,119,133,73,236,248,73,26,60,78,
205,181,66,194,188,44,124,166,207,207,194,103,23,61,249,129,108,170,201,165,209,137,117,6,176,55,36,64,2,36,224,28,2,20,88,206,241,53,123,74,2,36,64,2,36,64,2,36,96,18,1,10,44,147,64,179,25,18,32,1,18,
32,1,18,32,1,231,16,160,192,114,142,175,217,83,18,32,1,18,32,1,18,32,1,147,8,80,96,153,4,154,205,144,0,9,144,0,9,144,0,9,56,135,0,5,150,115,124,205,158,146,0,9,144,0,9,144,0,9,152,68,128,2,203,36,208,
108,134,4,72,128,4,72,128,4,72,192,57,4,40,176,156,227,107,246,148,4,72,128,4,72,128,4,72,192,36,2,20,88,38,129,102,51,36,64,2,36,64,2,36,64,2,206,33,64,129,229,28,95,179,167,36,64,2,36,64,2,36,64,2,38,
17,160,192,50,9,52,155,33,1,18,32,1,18,32,1,18,112,14,1,10,44,231,248,154,61,37,1,18,32,1,18,32,1,18,48,137,0,5,150,73,160,217,12,9,144,0,9,144,0,9,144,128,115,8,80,96,57,199,215,236,41,9,144,0,9,144,
0,9,144,128,73,4,40,176,76,2,205,102,72,128,4,72,128,4,72,128,4,156,67,128,2,203,57,190,102,79,73,128,4,72,128,4,72,128,4,76,34,64,129,101,18,104,54,67,2,36,64,2,36,64,2,36,224,28,2,20,88,206,241,53,123,
74,2,36,64,2,36,64,2,36,96,18,1,10,44,147,64,179,25,18,32,1,18,32,1,18,32,1,231,16,160,192,114,142,175,217,83,18,32,1,18,32,1,18,32,1,147,8,80,96,153,4,154,205,144,0,9,144,0,9,144,0,9,56,135,0,5,150,115,
124,205,158,146,0,9,144,0,9,144,0,9,152,68,128,2,203,36,208,108,134,4,72,128,4,72,128,4,72,192,57,4,40,176,156,227,107,246,148,4,72,128,4,72,128,4,72,192,36,2,20,88,38,129,102,51,36,64,2,36,64,2,36,64,
2,206,33,64,129,229,28,95,179,167,36,64,2,36,64,2,36,64,2,38,17,160,192,50,9,52,155,33,1,18,32,1,18,32,1,18,112,14,1,10,44,231,248,154,61,37,1,18,32,1,18,32,1,18,48,137,0,5,150,73,160,217,12,9,144,0,9,
144,0,9,144,128,115,8,80,96,57,199,215,236,41,9,144,0,9,144,0,9,144,128,73,4,40,176,76,2,205,102,72,128,4,72,128,4,72,128,4,156,67,128,2,203,57,190,102,79,73,128,4,72,128,4,72,128,4,76,34,64,129,101,18,
104,54,67,2,36,64,2,36,64,2,36,224,28,2,20,88,206,241,53,123,74,2,36,64,2,36,64,2,36,96,18,1,10,44,147,64,179,25,18,32,1,18,32,1,18,32,1,231,16,160,192,114,142,175,217,83,18,32,1,18,32,1,18,32,1,147,8,
80,96,153,4,154,205,144,0,9,144,0,9,144,0,9,56,135,0,5,150,115,124,205,158,146,0,9,144,0,9,144,0,9,152,68,128,2,203,36,208,108,134,4,72,128,4,72,128,4,72,192,57,4,40,176,156,227,107,246,148,4,72,128,4,
72,128,4,72,192,36,2,20,88,38,129,102,51,36,64,2,36,64,2,36,64,2,206,33,64,129,229,28,95,179,167,36,64,2,36,64,2,36,64,2,38,17,160,192,50,9,52,155,33,1,18,32,1,18,32,1,18,112,14,1,10,44,231,248,154,61,
37,1,18,32,1,18,32,1,18,48,137,0,5,150,73,160,217,12,9,144,0,9,144,0,9,144,128,115,8,80,96,57,199,215,236,41,9,144,0,9,144,0,9,144,128,73,4,40,176,76,2,205,102,72,128,4,72,128,4,72,128,4,156,67,128,2,
203,57,190,102,79,73,128,4,72,128,4,72,128,4,76,34,64,129,101,18,104,54,67,2,36,64,2,36,64,2,36,224,28,2,20,88,206,241,53,123,74,2,36,64,2,36,64,2,36,96,18,1,10,44,147,64,179,25,18,32,1,18,32,1,18,32,
1,231,16,160,192,114,142,175,217,83,18,32,1,18,32,1,18,32,1,147,8,80,96,153,4,154,205,144,0,9,144,0,9,144,0,9,56,135,0,5,150,115,124,205,158,146,0,9,144,0,9,144,0,9,152,68,128,2,203,36,208,108,134,4,72,
128,4,72,128,4,72,192,57,4,40,176,156,227,107,246,148,4,72,128,4,72,128,4,72,192,36,2,20,88,38,129,102,51,36,64,2,36,64,2,36,64,2,206,33,64,129,229,28,95,91,186,167,85,183,175,144,233,45,203,170,31,252,
141,116,102,236,32,245,63,126,51,89,139,64,213,245,63,202,225,167,111,179,150,81,154,53,73,239,61,41,169,43,231,88,206,46,43,24,148,231,175,18,178,228,249,29,86,48,197,195,134,109,31,159,149,28,171,139,
89,206,46,26,68,2,145,18,160,192,138,148,32,203,71,133,192,142,5,51,101,200,168,177,50,108,230,175,114,33,111,138,164,238,221,32,95,125,241,185,244,157,191,73,106,95,123,147,20,58,123,42,42,237,152,85,
73,165,35,187,60,196,162,89,237,178,29,18,32,1,18,32,1,107,16,160,192,178,134,31,104,133,70,32,119,114,1,217,86,180,156,108,41,85,195,205,227,120,158,252,178,169,230,149,130,223,86,78,136,154,32,122,162,
39,244,163,219,162,221,178,169,98,195,176,205,246,174,51,236,138,108,80,16,130,26,209,74,38,251,16,64,212,9,209,39,38,18,32,1,223,4,40,176,120,102,144,0,9,144,0,9,144,0,9,144,64,148,9,80,96,69,25,40,171,
243,79,160,212,119,147,221,243,172,48,175,10,195,104,72,248,252,147,247,38,201,75,131,6,168,227,37,211,14,201,75,61,218,168,99,248,31,199,205,76,136,166,96,126,17,218,94,213,175,165,26,174,212,19,162,
74,248,12,199,144,7,199,48,31,9,182,163,15,106,14,153,246,63,250,160,247,5,115,202,80,70,31,230,196,111,252,143,207,145,79,159,107,134,252,250,252,33,95,117,194,6,180,103,204,95,97,241,103,110,219,96,
15,162,104,186,221,209,98,166,215,169,247,205,88,175,191,99,217,217,9,127,162,15,58,71,156,7,177,242,183,191,115,78,247,143,241,184,241,60,243,246,11,56,235,254,140,22,215,88,214,131,200,210,243,237,62,
82,63,152,123,101,76,254,142,33,34,53,237,174,159,85,25,252,54,150,195,220,45,189,156,126,108,228,208,177,50,229,253,169,62,219,136,164,111,39,23,164,184,109,95,51,241,136,164,28,45,170,170,75,78,47,160,
62,55,30,199,223,122,194,113,228,215,251,125,246,215,34,234,111,124,206,68,2,241,32,64,129,21,15,234,14,108,19,55,168,181,75,22,201,61,115,86,171,161,179,10,181,235,203,204,97,189,148,232,216,123,117,
127,249,79,223,1,242,224,184,73,234,216,190,148,98,242,224,180,5,138,18,254,199,113,51,83,250,234,159,228,178,155,7,168,182,187,61,52,82,150,189,245,188,106,30,130,8,66,234,198,231,223,81,199,144,71,246,
108,81,67,152,176,29,125,80,195,130,218,255,198,132,97,194,242,21,43,203,197,107,190,87,31,227,119,173,250,151,170,225,195,130,59,215,42,22,40,7,54,168,31,55,119,95,117,226,243,47,31,189,93,106,182,186,
86,229,199,124,181,223,231,205,246,152,212,125,242,216,81,117,172,193,187,139,162,130,12,66,105,233,143,11,213,92,56,248,228,194,169,147,238,122,23,206,159,39,229,46,185,66,181,135,254,79,127,113,132,
58,22,140,157,235,86,175,148,171,199,127,169,202,98,56,53,22,254,206,238,156,211,59,113,120,247,14,55,203,9,207,61,225,22,253,235,94,30,42,5,10,23,81,199,208,247,77,75,127,138,10,207,236,42,57,119,60,
87,84,218,72,222,95,76,126,251,105,169,60,61,167,191,60,55,101,176,156,59,117,62,211,103,11,126,144,202,245,75,201,163,243,122,203,136,87,7,203,255,189,50,67,29,203,191,179,184,64,48,245,121,230,122,117,
236,191,195,186,200,211,119,191,34,168,75,79,39,143,159,84,199,122,188,217,76,206,86,219,175,202,247,234,211,83,125,134,255,163,145,32,138,254,248,101,157,60,55,235,110,85,111,165,154,229,228,189,225,
95,75,222,179,73,238,234,15,254,125,84,29,27,249,249,253,242,218,243,111,186,5,216,252,177,107,165,64,161,2,234,24,250,190,97,249,214,104,152,164,234,56,147,126,46,106,117,177,34,231,16,160,192,114,142,
175,227,218,211,175,38,143,151,203,250,12,82,226,9,73,23,77,37,54,47,139,171,93,254,26,127,225,142,158,42,98,129,223,16,18,72,7,151,253,160,38,226,235,115,196,32,130,182,92,218,33,40,251,33,198,190,28,
63,74,9,202,101,179,166,170,137,251,122,194,141,29,109,77,236,80,95,125,148,114,226,160,207,58,83,54,254,166,132,153,222,38,132,73,227,206,61,85,125,122,130,248,138,102,66,95,155,92,217,90,146,23,78,145,
156,71,247,123,244,183,106,213,42,238,255,211,170,95,38,155,54,109,86,226,42,24,59,91,93,119,163,251,92,136,166,189,198,186,130,57,231,202,116,185,93,21,1,203,214,109,219,73,238,125,91,149,200,130,207,
243,221,50,92,29,195,252,191,234,183,61,24,43,51,221,245,158,58,26,157,155,120,122,137,67,114,89,139,38,114,232,199,60,114,246,88,46,113,213,63,228,110,3,62,211,255,207,95,245,31,229,51,68,120,118,172,
60,34,15,142,28,40,40,139,4,193,116,251,253,125,101,255,154,211,238,178,245,90,84,141,57,131,47,223,251,70,218,244,110,36,233,201,25,66,190,64,155,52,245,251,194,182,34,238,182,235,116,202,136,200,165,
21,57,34,173,219,180,146,51,7,242,40,145,181,80,19,143,53,110,206,136,104,253,147,231,140,92,222,43,53,106,246,238,222,28,29,1,25,53,131,88,145,45,8,80,96,217,194,77,214,50,50,253,224,30,107,25,20,69,
107,112,115,133,224,209,35,109,122,100,37,210,38,32,198,16,197,202,57,235,77,85,149,30,229,66,212,231,225,183,167,102,68,203,180,159,72,83,206,252,209,31,14,57,211,247,105,73,111,221,75,78,238,216,168,
134,69,245,161,78,244,39,220,148,175,96,161,112,139,70,181,220,169,36,235,44,158,56,113,48,122,43,101,43,221,146,71,138,93,121,86,142,236,76,83,91,51,232,17,160,242,21,202,133,205,47,119,254,232,68,216,
194,54,224,223,130,174,36,243,39,214,239,221,181,55,82,179,89,222,129,4,40,176,28,232,244,72,187,124,248,239,140,185,83,161,164,235,251,15,148,223,222,31,167,34,28,72,250,124,151,253,85,26,135,82,141,
105,121,243,159,201,184,217,97,184,80,79,23,55,110,37,99,30,25,236,158,147,133,121,82,198,61,151,48,60,7,241,161,247,209,219,88,68,177,38,143,123,57,99,104,209,144,244,97,55,212,231,157,140,117,34,74,
132,161,53,189,77,136,65,68,175,16,197,138,85,210,87,50,34,138,227,106,222,69,69,118,46,58,153,25,17,241,213,110,36,118,130,159,62,55,47,210,62,133,123,206,233,209,172,211,31,143,86,38,192,166,141,31,
188,20,182,57,57,143,251,142,72,122,87,184,125,67,232,223,43,95,70,233,171,251,16,197,41,113,69,14,21,217,201,157,150,57,87,201,87,153,10,151,22,149,151,70,140,119,15,9,98,254,213,59,175,189,39,37,234,
230,203,182,223,24,54,132,120,139,214,60,167,27,251,118,148,5,31,45,119,215,167,207,177,202,89,233,104,182,118,232,209,172,13,159,102,68,188,96,211,175,83,182,132,237,51,99,193,164,115,73,242,195,194,
172,223,205,168,84,206,74,18,154,0,5,86,66,187,55,54,157,155,246,225,123,33,87,188,163,121,119,169,221,180,165,26,6,195,112,216,142,181,171,229,134,87,166,88,110,251,5,220,92,239,125,236,25,121,229,134,
203,221,118,234,157,197,156,41,204,53,194,60,40,244,225,183,79,39,185,57,232,162,226,189,182,85,37,199,226,25,62,249,32,106,133,97,40,163,168,196,28,47,125,114,255,218,111,63,247,40,231,93,39,134,87,49,
255,107,253,15,223,170,246,97,227,37,237,58,5,61,76,25,178,211,180,2,250,112,164,62,132,137,121,102,96,148,93,10,199,78,12,69,94,223,245,38,1,191,21,175,101,204,229,138,52,69,114,206,213,122,224,85,129,
184,69,191,97,19,230,201,133,155,142,109,252,61,168,162,179,103,126,35,201,167,178,23,66,193,84,164,15,1,98,130,247,99,157,223,80,243,164,32,64,178,75,167,202,31,80,115,170,222,127,226,43,53,49,28,115,
179,158,124,99,152,123,200,208,87,89,12,49,174,93,189,78,158,236,48,89,246,255,226,10,198,180,128,121,242,92,126,84,234,93,81,75,217,13,59,182,173,223,37,125,71,95,167,134,252,2,165,182,131,107,11,4,31,
202,193,38,204,223,138,70,202,177,163,72,52,170,97,29,14,36,144,67,235,115,116,190,25,14,132,231,228,46,63,252,238,116,217,84,245,10,203,32,72,221,191,73,94,186,169,85,22,123,134,190,60,81,182,95,118,
131,101,236,164,33,246,32,128,40,154,81,72,98,178,63,86,58,134,51,140,187,178,79,11,217,178,37,184,9,215,79,140,31,42,231,106,29,176,7,36,139,89,137,121,88,70,33,137,9,250,143,245,26,171,38,189,71,146,
246,126,145,67,222,157,248,97,36,85,176,172,67,9,48,130,229,80,199,71,218,237,173,223,207,142,180,10,150,39,1,75,18,192,144,32,162,104,198,109,27,118,205,153,162,86,137,134,154,170,110,250,37,104,113,
133,186,127,248,98,105,168,77,48,191,70,0,67,130,243,38,174,82,91,56,232,105,237,119,123,85,244,46,146,132,136,34,197,85,36,4,157,93,150,2,203,217,254,15,187,247,24,38,172,186,115,117,216,229,89,144,4,
172,74,0,243,205,48,68,136,97,108,253,253,152,24,46,44,218,227,254,144,76,78,57,119,90,126,249,104,66,72,101,48,215,39,239,22,207,125,171,66,170,192,161,153,49,132,136,33,66,12,41,234,251,96,97,184,176,
118,215,140,61,180,194,77,123,126,188,16,110,81,150,35,1,225,16,33,79,130,176,9,164,166,86,150,22,147,230,73,90,238,236,39,194,134,221,64,8,5,57,68,24,2,44,102,53,133,64,241,111,222,148,55,71,63,27,114,
91,248,94,221,58,177,141,156,201,29,120,222,81,200,149,179,64,208,4,82,14,22,147,17,61,199,6,157,159,25,73,192,155,0,35,88,60,39,194,38,128,121,37,135,94,123,64,240,164,206,68,2,36,144,73,0,67,131,225,
136,43,212,128,239,213,178,55,18,119,43,20,59,156,39,88,57,56,249,209,153,118,48,149,54,90,152,0,5,150,133,157,99,7,211,190,158,241,165,18,89,21,142,253,109,7,115,105,35,9,196,148,0,30,54,16,185,122,161,
95,183,136,218,193,138,194,205,31,156,22,220,232,153,204,37,144,114,188,136,18,184,193,46,76,48,215,58,182,102,39,2,20,88,118,242,150,69,109,133,200,26,115,125,19,117,99,161,208,178,168,147,104,86,76,
9,64,88,33,106,181,253,217,219,195,142,92,121,27,248,233,71,159,201,194,23,54,170,57,89,20,90,49,117,159,170,28,140,47,172,184,72,38,63,48,91,32,112,153,72,32,82,2,156,131,21,41,65,150,247,73,160,199,
173,125,77,37,147,118,252,168,64,232,121,167,86,173,219,72,201,242,21,77,181,133,141,57,139,192,190,157,219,181,141,40,51,222,157,25,203,116,115,239,238,177,172,222,209,117,167,29,79,163,168,114,244,25,
16,155,206,83,96,197,134,43,107,37,1,18,32,1,18,32,1,18,112,48,1,14,17,58,216,249,236,58,9,144,0,9,144,0,9,144,64,108,8,80,96,197,134,43,107,37,1,18,32,1,18,32,1,18,112,48,1,10,44,7,59,159,93,39,1,18,
32,1,18,32,1,18,136,13,1,10,172,216,112,101,173,36,64,2,36,64,2,36,64,2,14,38,64,129,229,96,231,179,235,36,64,2,36,64,2,36,64,2,177,33,64,129,21,27,174,172,149,4,72,128,4,72,128,4,72,192,193,4,40,176,
28,236,124,118,157,4,72,128,4,72,128,4,72,32,54,4,40,176,98,195,149,181,146,0,9,144,0,9,144,0,9,56,152,128,45,55,26,109,221,166,149,180,187,167,129,164,21,57,162,92,151,99,117,49,25,57,116,172,250,251,
254,71,239,146,2,109,210,60,92,154,127,103,113,249,96,228,76,217,180,105,179,160,108,211,71,43,248,116,249,243,237,62,10,120,28,5,159,155,117,183,164,39,159,116,215,145,114,180,168,28,221,224,146,151,
70,140,119,240,169,196,174,39,2,129,59,251,117,151,39,122,167,73,233,130,91,228,196,153,139,229,245,57,53,100,196,179,147,61,186,54,242,241,254,210,173,217,113,169,94,252,15,245,57,242,125,184,168,182,
12,28,254,182,59,95,251,182,45,229,127,47,236,151,107,30,46,33,115,231,47,114,127,142,178,125,218,236,145,178,173,51,94,69,178,244,203,222,242,232,235,219,61,242,224,115,239,124,187,23,118,84,54,233,105,
227,129,122,50,119,85,81,143,54,19,129,127,164,125,184,103,206,106,217,151,82,204,103,53,73,239,61,41,159,188,55,73,29,187,247,177,103,36,95,147,107,100,91,209,114,234,255,66,103,79,73,145,223,102,203,
152,71,6,187,203,182,110,219,78,26,223,249,168,188,212,163,77,150,250,30,126,123,170,250,236,133,59,122,10,242,93,244,228,7,62,219,156,222,178,108,164,93,98,121,18,176,45,1,91,70,176,218,244,110,36,174,
51,57,5,130,104,205,196,35,146,191,234,63,74,88,233,41,57,189,128,58,134,159,37,207,239,144,156,5,207,73,159,103,174,247,112,18,62,215,243,232,191,141,25,2,29,63,185,32,197,93,30,226,170,64,195,116,121,
242,141,97,182,61,17,104,56,9,128,192,139,3,246,200,23,191,150,147,156,141,215,43,113,245,200,13,139,5,98,73,79,227,71,223,161,62,131,184,65,30,61,95,251,6,71,100,253,156,208,95,229,82,166,200,33,25,255,
64,73,169,90,181,74,64,7,140,154,217,220,221,38,218,191,181,229,90,153,49,249,142,128,229,156,148,97,98,135,250,2,81,163,11,27,136,42,253,127,93,92,13,25,53,86,246,94,221,95,46,172,93,226,62,150,188,112,
138,228,172,221,84,134,205,252,213,3,215,150,82,53,68,23,83,129,56,30,126,250,54,119,125,70,27,2,149,227,113,18,72,84,2,182,20,88,57,138,157,146,253,107,78,43,159,204,250,98,182,60,214,249,13,121,237,
249,55,125,250,104,225,130,31,228,207,217,251,37,189,196,161,160,46,226,225,56,26,145,171,229,239,236,147,179,213,246,75,175,62,61,195,169,130,101,72,32,238,4,32,164,10,38,29,148,89,115,215,43,91,16,185,
130,128,210,35,80,136,110,221,219,110,145,244,28,85,197,35,114,132,124,157,6,174,144,130,249,210,228,131,241,119,134,220,15,68,194,62,121,169,89,72,229,16,45,187,253,149,194,210,185,193,34,129,93,76,193,
17,248,79,223,1,178,163,121,119,57,51,118,144,71,180,106,194,115,79,200,204,97,189,228,84,82,126,121,112,92,70,148,75,79,155,106,94,41,16,101,76,36,64,2,161,17,176,165,192,58,187,59,89,74,54,76,82,195,
121,86,73,16,122,24,138,172,213,170,140,85,76,162,29,36,16,18,1,8,169,61,39,82,229,249,251,124,191,28,187,71,187,66,178,112,99,115,153,54,253,235,44,245,98,248,253,253,5,165,165,75,163,63,67,106,19,153,
63,90,210,74,26,149,95,26,178,56,131,29,176,7,118,49,5,71,160,66,155,27,164,234,246,21,242,213,23,159,251,244,97,142,197,51,228,96,221,171,60,142,165,174,156,163,68,89,255,65,15,4,215,8,115,145,0,9,40,
2,182,20,88,79,223,253,138,92,56,145,91,205,165,194,176,92,118,66,11,199,234,116,42,33,201,251,139,169,57,88,177,76,199,255,62,43,136,174,49,145,128,93,9,244,121,238,164,22,137,58,45,199,126,110,145,69,
240,212,44,189,71,214,238,200,229,183,107,171,214,238,85,17,48,227,144,98,48,28,118,237,63,39,195,63,110,34,189,155,254,32,24,130,12,37,193,30,216,197,20,28,129,19,23,87,148,51,187,252,95,7,119,172,93,
45,199,243,228,87,243,170,244,180,108,214,84,129,200,58,218,109,136,92,223,245,166,224,26,98,46,18,32,1,123,10,44,248,237,241,190,175,202,180,187,126,150,220,249,92,74,104,25,135,230,48,1,253,209,121,
218,228,89,237,7,199,32,198,222,127,226,43,15,119,227,115,61,15,126,63,56,114,96,72,199,121,238,144,64,34,18,64,20,171,102,135,207,212,240,219,229,85,15,11,38,151,135,42,152,194,225,242,226,216,143,100,
194,188,150,106,8,242,161,193,189,195,169,130,101,98,72,224,165,65,3,84,228,235,226,123,71,123,136,47,99,147,152,232,222,109,209,110,247,15,135,21,99,232,16,86,109,11,2,182,140,96,233,100,17,145,130,208,
58,251,107,17,169,221,181,168,27,184,113,146,59,38,176,35,143,119,244,202,123,18,187,247,10,192,64,199,125,121,183,80,153,60,226,58,148,223,22,142,167,145,36,144,29,1,12,191,65,104,173,223,83,90,238,237,
85,83,101,197,223,181,43,156,247,91,172,65,237,82,106,69,161,113,213,96,40,148,49,175,106,214,170,150,50,250,150,165,82,174,68,238,160,138,194,30,216,197,20,28,129,130,7,183,75,82,57,255,11,10,42,212,
174,175,86,20,46,156,63,47,75,133,211,159,30,44,23,157,60,36,181,30,120,85,36,127,74,150,227,222,147,220,141,43,18,131,179,142,185,72,32,177,8,216,78,96,97,181,145,119,180,105,247,95,7,60,182,77,136,135,
139,58,119,237,36,167,202,31,144,3,127,165,199,163,121,182,73,2,17,19,232,209,237,186,44,19,198,49,4,87,246,162,140,97,239,105,243,142,75,235,234,139,5,249,188,19,190,151,216,126,97,198,242,58,234,208,
214,237,187,213,239,212,138,37,61,178,22,74,201,37,39,78,103,189,57,235,153,186,244,127,91,150,239,204,24,46,12,148,96,7,236,249,101,93,160,156,60,174,19,216,177,64,219,174,166,98,67,159,67,125,240,161,
171,121,23,185,120,205,247,62,129,225,33,117,197,107,35,212,49,212,193,68,2,36,144,61,1,219,9,172,203,90,52,145,60,151,31,149,17,175,14,86,61,195,69,65,159,99,21,47,103,67,240,53,186,189,164,228,249,171,
132,223,213,140,241,178,141,237,146,64,176,4,174,108,82,86,109,211,128,61,168,144,32,96,186,94,190,75,126,217,144,17,149,125,235,221,207,212,48,222,212,71,54,123,204,149,66,254,217,227,27,42,225,116,219,
192,183,50,110,192,218,205,24,209,168,33,218,2,63,125,136,17,171,253,176,181,194,244,159,179,159,148,254,159,7,127,22,236,115,149,93,194,92,173,119,134,29,83,109,120,239,211,21,108,127,157,152,15,91,53,
84,88,252,153,36,13,30,231,177,50,16,251,98,221,240,202,20,201,127,230,148,96,56,208,95,66,100,107,231,59,207,168,40,23,19,9,144,64,246,4,108,185,209,40,230,91,65,84,233,27,141,98,163,207,121,19,87,9,
182,100,192,126,88,37,174,200,161,182,110,240,149,178,219,104,20,195,130,72,254,54,34,197,113,180,193,141,70,249,181,74,84,2,16,46,16,65,152,172,142,132,85,122,109,123,133,190,209,168,206,7,251,84,97,
43,5,61,65,160,25,55,36,197,28,47,172,62,244,22,73,16,101,216,31,11,195,148,72,220,104,52,244,51,14,243,161,140,155,139,26,107,8,118,163,81,204,171,194,208,159,247,144,33,86,20,94,92,167,113,192,141,70,
125,149,13,189,39,44,65,2,246,36,96,75,129,101,79,212,180,154,4,72,128,4,72,128,4,72,192,41,4,108,55,68,232,20,199,176,159,36,64,2,36,64,2,36,64,2,246,37,96,139,8,86,167,27,58,74,245,75,43,75,82,114,112,
43,139,236,235,14,90,78,2,25,4,246,111,59,34,223,127,251,163,108,217,178,53,102,72,82,83,43,75,151,235,154,73,173,202,254,39,157,199,172,113,135,84,188,123,255,89,249,112,218,247,49,243,35,124,216,170,
67,103,41,90,185,134,67,136,178,155,78,39,112,46,61,77,54,175,248,89,190,158,241,165,229,81,88,90,96,221,251,208,29,82,250,202,156,146,158,223,243,229,205,150,167,74,3,73,32,74,4,242,110,41,33,11,62,249,
77,126,88,248,99,148,106,204,168,230,157,87,239,144,158,77,255,144,148,60,25,47,76,103,138,45,129,105,203,90,201,163,47,126,23,53,161,213,170,117,27,185,162,247,189,178,169,234,21,177,53,156,181,147,128,
69,9,20,79,63,44,242,253,52,121,115,244,179,22,181,80,196,146,2,11,79,101,253,159,191,65,210,46,62,100,89,112,52,140,4,204,34,144,116,46,73,118,204,58,43,239,78,252,48,226,38,241,221,250,223,27,151,74,
149,98,107,35,174,139,21,132,70,96,243,161,218,114,205,221,43,35,22,89,125,239,29,36,231,187,221,47,105,185,243,133,102,0,115,147,64,2,18,72,221,191,73,166,63,212,39,226,239,85,44,208,88,78,96,41,113,
245,114,39,73,43,116,52,22,253,101,157,36,96,91,2,199,190,203,47,19,94,124,59,34,251,87,206,252,175,52,40,187,60,162,58,88,56,124,2,145,138,172,187,134,63,46,7,58,222,21,190,1,44,73,2,9,72,160,194,177,
191,101,230,160,30,150,19,89,150,155,228,222,239,201,27,41,174,18,240,11,192,46,69,78,160,240,213,167,4,243,17,195,77,24,22,164,184,10,151,94,116,202,33,114,56,254,201,204,247,252,133,82,235,117,93,110,
164,184,10,5,24,243,58,134,192,142,194,101,164,251,179,19,45,215,95,75,9,172,126,247,220,42,233,101,15,88,14,18,13,34,1,171,16,104,250,159,234,97,153,210,182,117,11,53,231,138,41,254,4,58,212,249,81,250,
223,214,45,100,67,106,223,50,56,228,50,44,64,2,78,33,176,169,124,125,193,240,185,149,146,165,4,86,149,118,133,173,196,134,182,144,128,229,8,96,94,34,30,68,66,77,183,223,92,135,19,218,67,133,22,195,252,
183,117,204,126,55,123,239,166,113,227,216,82,162,106,12,45,98,213,36,96,127,2,69,174,189,197,82,157,176,140,192,194,208,7,231,93,89,234,220,160,49,22,37,144,122,249,197,33,91,118,93,131,213,33,151,97,
129,216,17,104,81,101,137,32,170,24,108,42,209,236,218,96,179,50,31,9,56,150,0,134,10,49,148,110,149,100,25,129,85,183,121,53,171,48,161,29,36,96,105,2,161,14,163,15,29,248,95,70,175,44,232,209,142,109,
107,5,109,21,134,63,152,72,128,4,2,19,168,209,162,125,224,76,38,229,176,140,192,42,88,1,11,26,153,72,128,4,130,33,112,115,111,237,45,202,65,38,110,36,26,36,40,147,179,53,169,118,46,168,22,123,220,218,
55,168,124,204,68,2,36,32,146,171,82,29,203,96,176,140,192,146,164,243,150,129,66,67,72,32,145,8,52,174,194,141,122,173,232,207,106,37,255,182,162,89,180,137,4,108,77,224,92,222,100,203,216,111,25,129,
197,249,87,150,57,39,104,136,13,8,84,174,87,38,104,43,75,21,62,24,116,94,102,52,143,64,201,2,219,131,106,172,92,253,38,65,229,99,38,18,32,1,17,204,195,178,74,178,140,192,178,10,16,218,65,2,137,70,32,216,
27,121,162,245,155,253,33,1,18,32,129,120,18,160,192,138,39,125,182,77,2,36,224,104,2,225,236,135,229,104,96,236,60,9,216,136,0,5,150,141,156,69,83,73,128,4,72,128,4,72,128,4,236,65,128,2,203,30,126,162,
149,36,64,2,36,64,2,36,64,2,54,34,64,129,101,35,103,209,84,18,32,1,18,32,1,18,32,1,123,16,160,192,178,135,159,104,37,9,144,0,9,144,0,9,144,128,141,8,80,96,217,200,89,52,149,4,72,128,4,72,128,4,72,192,
30,4,40,176,236,225,39,90,73,2,36,64,2,36,64,2,36,96,35,2,20,88,54,114,22,77,37,1,18,32,1,18,32,1,18,176,7,1,10,44,123,248,137,86,146,0,9,144,0,9,144,0,9,216,136,0,5,150,141,156,69,83,73,128,4,72,128,
4,72,128,4,236,65,128,2,203,30,126,162,149,36,64,2,36,64,2,36,64,2,54,34,64,129,101,35,103,209,84,18,32,1,18,32,1,18,32,1,123,16,160,192,178,135,159,104,37,9,144,0,9,144,0,9,144,128,141,8,80,96,217,200,
89,52,149,4,72,128,4,72,128,4,72,192,30,4,40,176,236,225,39,90,73,2,36,64,2,36,64,2,36,96,35,2,20,88,54,114,22,77,37,1,18,32,1,18,32,1,18,176,7,1,10,44,123,248,137,86,146,0,9,144,0,9,144,0,9,216,136,0,
5,150,141,156,69,83,73,128,4,72,128,4,72,128,4,236,65,128,2,203,30,126,162,149,36,64,2,36,64,2,36,64,2,54,34,64,129,101,35,103,209,84,18,32,1,18,32,1,18,32,1,123,16,160,192,178,135,159,104,37,9,144,0,
9,144,0,9,144,128,141,8,80,96,217,200,89,52,149,4,72,128,4,72,128,4,72,192,30,4,40,176,236,225,39,90,73,2,36,64,2,36,64,2,36,96,35,2,20,88,54,114,22,77,37,1,18,32,1,18,32,1,18,176,7,1,10,44,123,248,137,
86,146,0,9,144,0,9,144,0,9,216,136,0,5,150,141,156,69,83,73,128,4,72,128,4,72,128,4,236,65,128,2,203,30,126,162,149,36,64,2,36,64,2,36,64,2,54,34,64,129,101,35,103,209,84,18,32,1,18,32,1,18,32,1,123,16,
160,192,178,135,159,104,37,9,144,0,9,144,0,9,144,128,141,8,80,96,217,200,89,52,149,4,72,128,4,72,128,4,72,192,30,4,40,176,236,225,39,90,73,2,36,64,2,36,64,2,36,96,35,2,20,88,54,114,22,77,37,1,18,32,1,
18,32,1,18,176,7,1,10,44,123,248,137,86,146,0,9,144,0,9,144,0,9,216,136,0,5,150,141,156,69,83,73,128,4,72,128,4,72,128,4,236,65,128,2,203,30,126,162,149,36,64,2,36,64,2,36,64,2,54,34,64,129,101,35,103,
209,84,18,32,1,18,32,1,18,32,1,123,16,160,192,178,135,159,104,37,9,144,0,9,144,0,9,144,128,141,8,80,96,217,200,89,52,149,4,72,128,4,72,128,4,72,192,30,4,40,176,236,225,39,90,73,2,36,64,2,36,64,2,36,96,
35,2,20,88,54,114,22,77,37,1,18,32,1,18,32,1,18,176,7,1,10,44,123,248,137,86,146,0,9,144,0,9,144,0,9,216,136,0,5,150,141,156,69,83,73,128,4,72,128,4,72,128,4,236,65,128,2,203,30,126,162,149,36,64,2,36,
64,2,36,64,2,54,34,64,129,101,35,103,209,84,18,32,1,18,32,1,18,32,1,123,16,160,192,178,135,159,104,37,9,144,0,9,144,0,9,144,128,141,8,80,96,217,200,89,52,149,4,72,128,4,72,128,4,72,192,30,4,40,176,236,
225,39,90,73,2,36,64,2,36,64,2,36,96,35,2,20,88,54,114,22,77,37,1,18,32,1,18,32,1,18,176,7,1,10,44,123,248,137,86,146,0,9,144,0,9,144,0,9,216,136,0,5,150,141,156,69,83,73,128,4,72,128,4,72,128,4,236,65,
128,2,203,30,126,162,149,36,64,2,36,64,2,36,64,2,54,34,64,129,101,35,103,209,84,18,32,1,18,32,1,18,32,1,123,16,160,192,178,135,159,104,37,9,144,0,9,144,0,9,144,128,141,8,80,96,217,200,89,52,149,4,72,128,
4,72,128,4,72,192,30,4,40,176,236,225,39,90,73,2,36,64,2,36,64,2,36,96,35,2,20,88,54,114,22,77,37,1,18,32,1,18,32,1,18,176,7,1,10,44,123,248,137,86,146,0,9,144,0,9,144,0,9,216,136,0,5,150,141,156,69,83,
73,128,4,72,128,4,72,128,4,236,65,128,2,203,30,126,162,149,36,64,2,36,64,2,36,64,2,54,34,64,129,101,35,103,209,84,18,32,1,18,32,1,18,32,1,123,16,160,192,178,135,159,44,109,229,182,143,207,74,142,213,197,
44,109,163,209,184,179,191,22,145,231,219,125,36,211,238,250,89,146,211,11,216,198,110,171,26,122,247,196,122,242,209,146,86,86,53,207,195,174,61,39,82,37,103,227,245,130,223,76,36,96,37,2,169,123,55,
200,244,150,101,173,100,82,182,182,148,250,110,178,224,135,201,63,1,10,44,158,29,142,35,240,210,136,241,242,236,123,67,165,207,51,215,75,142,51,121,28,215,127,118,216,63,129,234,61,207,202,132,121,45,
137,136,4,72,32,2,2,169,43,231,40,177,88,232,236,169,8,106,177,127,81,10,44,251,251,144,61,8,131,64,142,188,23,36,189,196,33,73,43,114,36,228,210,201,251,139,169,8,24,83,226,17,216,56,53,143,220,219,110,
81,226,117,140,61,34,1,19,9,108,185,180,131,116,91,180,91,142,231,201,111,98,171,214,107,138,2,203,122,62,161,69,36,64,2,36,64,2,36,64,2,54,39,224,88,129,149,231,175,18,106,14,206,154,137,71,84,52,66,
159,67,116,96,86,110,245,63,126,48,183,72,79,75,158,223,33,39,23,164,168,50,56,134,114,121,207,38,185,143,27,203,225,111,228,71,27,72,152,231,131,186,244,122,81,143,29,19,34,55,254,250,111,236,15,250,
167,247,21,156,82,142,22,85,135,241,185,145,41,254,71,157,58,35,148,209,255,143,21,31,248,5,233,177,94,99,149,143,84,219,154,13,248,219,61,47,203,96,147,126,126,224,56,250,1,95,162,44,18,242,219,213,151,
177,226,139,185,77,152,147,133,121,78,248,193,223,39,206,92,28,171,230,194,174,247,253,5,165,221,54,142,154,217,220,93,207,53,15,151,144,89,171,56,68,120,248,233,219,36,233,189,39,213,48,207,170,126,25,
60,48,71,8,159,235,159,225,127,164,146,105,135,212,103,152,143,131,223,250,223,58,84,99,57,148,71,62,252,118,31,215,134,147,208,6,202,225,243,74,71,118,133,237,215,68,42,8,110,103,198,14,114,51,173,176,
248,51,203,117,239,240,238,29,110,27,141,190,171,186,254,71,15,31,91,206,112,147,12,114,172,192,2,223,77,155,54,75,147,235,171,203,163,243,122,139,171,254,33,117,3,77,59,126,74,158,158,211,95,125,182,
103,199,30,183,72,66,254,109,235,119,73,159,87,175,86,199,79,28,61,33,103,214,21,84,110,194,77,118,223,174,3,242,220,172,187,85,185,252,5,242,202,194,5,63,184,93,248,219,251,59,229,228,241,147,170,28,
242,160,30,59,77,10,215,59,178,246,187,189,114,243,61,215,171,62,214,104,84,89,114,167,101,21,138,152,64,254,199,47,235,220,44,42,213,44,39,239,13,255,90,137,209,146,13,147,100,202,251,83,149,72,193,207,
107,207,191,41,168,19,233,212,166,188,210,171,79,79,53,108,23,203,212,244,209,10,170,250,231,166,12,22,253,239,253,107,78,75,203,238,141,85,191,254,59,172,139,204,159,180,210,109,83,129,66,5,212,231,205,
58,93,42,103,14,228,145,244,228,147,170,44,18,62,47,208,38,45,150,230,218,174,238,33,175,231,80,54,95,88,86,83,142,253,220,66,142,28,75,151,135,38,149,182,92,63,118,236,62,174,108,92,63,167,187,140,120,
118,178,108,60,80,47,46,54,46,252,113,69,92,218,13,166,209,147,199,142,170,97,158,6,239,102,12,153,166,175,254,73,46,187,121,128,250,172,219,67,35,101,217,91,207,123,84,131,155,45,142,13,155,249,171,76,
120,238,9,37,148,32,190,94,234,209,70,26,119,238,169,142,53,188,127,164,172,93,146,57,4,91,117,251,10,121,105,144,86,167,86,31,142,35,223,138,215,70,56,126,238,14,184,125,249,232,237,82,179,213,181,110,
166,191,207,155,45,152,219,100,165,180,244,199,133,82,179,231,61,202,198,212,186,151,200,209,5,214,19,129,241,228,229,104,129,85,181,106,21,57,85,254,128,7,127,136,170,39,59,76,86,209,9,136,164,115,167,
206,187,143,215,107,81,85,221,96,255,201,115,70,234,93,81,75,78,28,60,173,142,125,51,109,174,18,106,56,134,132,155,46,234,70,130,104,155,245,197,108,185,188,87,170,42,135,60,200,251,199,79,155,226,233,
247,176,218,174,125,117,41,101,55,4,101,129,134,233,62,231,47,125,249,222,55,210,166,119,35,15,22,234,134,187,173,136,202,15,17,5,49,181,255,23,151,220,126,127,223,12,193,165,69,140,126,158,189,82,170,
93,30,191,21,52,79,223,253,138,242,57,126,235,226,56,127,213,127,148,48,86,145,182,10,23,228,108,181,253,97,113,139,119,161,180,179,25,17,196,88,39,136,148,105,211,191,150,23,7,236,81,77,21,76,58,40,207,
12,72,150,183,222,253,204,114,171,246,134,116,207,160,81,189,248,31,210,190,109,75,89,255,183,57,140,188,125,176,101,203,214,88,187,37,236,250,113,115,247,78,47,220,209,83,69,84,240,123,225,252,121,30,
135,203,116,185,93,253,191,173,104,57,105,221,182,157,228,222,183,85,82,54,254,38,215,119,189,73,48,39,71,63,6,17,165,167,131,203,126,144,254,131,30,144,77,53,175,84,31,33,95,129,194,69,164,196,223,235,
194,182,59,17,10,130,91,173,250,151,102,225,182,108,214,84,75,117,175,213,117,55,202,150,82,53,148,77,23,215,105,44,91,214,252,110,41,251,226,109,140,101,4,86,242,41,243,135,205,202,87,40,231,193,127,
219,162,19,74,56,33,50,129,31,136,1,99,202,157,63,87,216,254,26,113,211,107,238,97,179,199,251,190,42,107,87,219,239,2,130,232,82,221,123,138,74,209,242,41,178,252,157,125,97,69,225,32,162,32,166,32,74,
43,182,203,39,247,63,122,151,138,24,237,220,177,43,46,2,6,2,24,145,52,61,250,168,71,167,224,104,136,97,244,23,145,183,63,103,239,23,12,253,90,37,157,56,24,252,234,156,77,251,185,37,129,183,223,10,230,
139,127,228,49,88,225,155,126,48,67,176,154,157,114,230,207,220,194,4,209,40,68,165,238,153,179,90,69,43,30,156,182,32,139,57,167,146,194,155,208,60,121,220,203,238,97,48,136,183,175,190,248,92,46,28,
222,103,118,119,217,94,24,4,242,21,44,20,70,169,216,22,41,158,126,56,182,13,132,80,187,101,4,86,142,180,124,33,152,29,187,172,167,78,254,163,42,199,141,247,183,159,150,6,213,80,199,30,237,101,193,71,203,
221,123,42,33,226,129,225,71,36,68,109,58,119,237,36,35,94,29,236,22,110,16,21,216,34,192,78,9,67,124,152,135,132,104,19,34,57,24,250,219,191,237,88,150,46,220,216,183,99,22,22,200,148,179,210,81,149,
23,191,33,166,46,107,209,68,9,152,18,87,228,80,17,35,12,61,198,51,233,219,53,96,184,80,79,16,84,24,202,133,15,33,12,23,126,227,185,186,12,76,244,249,101,102,219,126,112,79,240,171,31,255,62,154,108,138,
121,136,6,245,232,118,157,123,72,16,115,175,158,152,148,46,119,246,235,46,165,11,110,49,197,6,59,53,18,172,240,61,252,183,117,230,36,229,63,147,33,236,49,92,24,76,74,171,126,153,18,76,250,208,22,132,154,
49,10,115,113,227,86,42,194,165,11,55,12,47,254,167,239,0,119,228,38,152,54,18,49,15,184,173,91,189,50,11,55,99,244,47,17,251,29,141,62,21,60,73,129,149,133,227,63,7,226,175,245,42,181,44,168,110,162,
24,42,154,55,113,149,120,71,184,252,57,95,13,9,214,77,149,199,58,191,225,115,249,254,101,125,202,203,214,213,123,51,39,207,107,115,176,92,255,196,191,191,161,156,204,24,222,108,59,224,82,121,255,137,175,
84,63,84,4,234,138,194,89,170,200,115,249,81,21,5,212,89,96,190,89,223,209,215,169,225,81,36,252,134,32,197,112,163,186,80,107,34,11,67,133,24,142,139,71,130,120,130,224,213,35,140,176,87,79,136,176,97,
72,84,31,58,212,69,32,34,121,16,205,24,74,198,121,18,143,180,116,241,178,160,155,93,186,238,92,208,121,35,205,56,230,62,151,170,2,19,220,11,55,251,73,138,22,78,118,15,25,70,90,119,162,149,95,182,57,184,
168,253,178,159,190,143,123,215,49,236,119,239,99,207,200,43,55,92,174,162,77,59,214,174,14,202,166,125,41,197,84,180,11,162,10,229,48,191,10,115,117,244,180,169,98,67,53,207,232,187,129,55,170,227,168,
191,84,245,186,142,159,131,5,110,55,62,255,142,172,255,225,91,55,151,75,218,117,114,188,240,12,230,164,203,177,111,123,48,217,76,201,131,25,169,25,87,196,56,167,126,247,220,42,165,186,90,194,148,144,73,
96,194,246,121,77,56,232,34,2,21,224,166,140,225,166,88,79,218,14,217,88,22,176,61,129,148,227,69,100,68,215,241,65,247,35,53,181,178,108,154,150,55,232,252,204,104,14,129,238,207,85,146,233,51,190,13,
170,177,33,95,45,149,29,133,203,4,149,215,106,153,16,181,130,64,211,19,162,89,187,126,255,69,206,244,125,218,106,166,210,158,4,32,80,232,211,23,229,189,9,227,44,209,19,203,132,81,222,157,248,161,36,157,
203,220,246,192,18,116,130,52,98,251,188,211,106,78,146,190,109,3,134,149,48,201,253,124,209,19,65,214,192,108,36,16,60,129,67,171,47,4,159,89,203,137,137,212,63,109,110,26,82,25,102,142,45,129,125,39,
43,6,45,174,96,201,249,149,223,199,214,160,24,213,14,113,133,168,20,150,237,35,97,117,28,162,89,229,46,185,34,70,45,178,90,39,19,72,57,119,218,50,226,10,126,176,140,192,130,49,167,87,219,243,189,112,197,
59,159,147,146,229,138,187,87,31,98,18,55,230,88,25,35,90,78,62,233,217,247,232,17,192,67,200,140,15,191,9,185,194,15,190,57,30,114,25,22,136,29,129,183,190,13,45,26,53,251,253,137,130,155,135,221,18,
34,87,24,34,252,237,211,73,106,168,107,98,135,250,106,136,80,95,85,104,183,254,208,94,107,19,184,120,197,255,44,101,160,101,134,8,65,5,67,25,253,198,93,35,233,249,227,191,194,199,82,94,162,49,36,240,47,
129,189,95,228,16,68,123,195,73,139,62,237,43,45,170,44,9,167,40,203,68,145,192,230,67,181,165,218,53,95,132,92,99,223,123,7,201,241,155,31,10,185,28,11,144,128,19,8,96,245,224,119,247,116,86,17,123,171,
36,75,69,176,0,230,151,73,59,108,59,84,104,21,167,210,142,196,36,144,119,75,137,176,197,21,136,244,121,228,123,9,118,107,128,196,36,24,255,94,129,255,240,55,210,195,50,4,243,74,170,110,250,37,172,178,
44,68,2,137,76,0,209,221,157,111,62,97,41,113,5,222,150,18,88,48,104,246,204,111,100,217,27,123,40,178,18,249,219,192,190,133,76,0,226,234,201,59,94,9,185,156,177,0,30,96,250,188,80,152,34,43,34,138,145,
21,126,101,102,205,144,230,94,121,183,246,66,191,110,20,89,145,185,128,165,19,140,0,196,213,161,215,30,144,175,103,124,105,185,158,97,231,204,167,172,102,213,198,13,127,137,107,119,1,169,89,165,154,156,
45,20,222,211,158,213,250,68,123,72,32,28,2,152,115,117,120,94,146,188,56,252,245,112,138,103,41,179,110,253,38,217,120,168,174,52,170,83,70,46,74,246,124,139,65,84,26,96,37,62,9,96,82,123,223,23,139,
202,27,147,62,143,152,208,226,153,211,164,85,201,20,201,81,185,174,156,205,105,157,205,111,35,238,24,43,32,129,16,9,84,221,185,90,254,28,59,92,230,126,107,173,87,8,233,221,176,212,28,44,95,108,91,181,
190,82,154,118,104,40,5,43,100,188,227,140,137,4,156,64,224,220,241,92,178,127,211,9,153,240,226,219,49,235,238,83,195,251,74,147,90,185,165,76,17,62,196,196,10,242,137,211,73,178,64,123,181,229,83,163,
223,139,73,19,119,13,127,92,10,87,191,68,46,20,178,222,11,181,99,210,97,86,74,2,26,129,243,219,254,148,229,95,127,46,63,44,204,250,70,1,43,1,178,188,192,178,18,44,218,66,2,36,64,2,36,64,2,36,64,2,193,
16,176,220,28,172,96,140,102,30,18,32,1,18,32,1,18,32,1,18,176,50,1,10,44,43,123,135,182,145,0,9,144,0,9,144,0,9,216,146,0,5,150,45,221,70,163,73,128,4,72,128,4,72,128,4,172,76,128,2,203,202,222,161,109,
36,64,2,36,64,2,36,64,2,182,36,64,129,101,75,183,209,104,18,32,1,18,32,1,18,32,1,43,19,136,251,42,194,220,121,242,200,133,11,161,189,188,214,106,64,47,156,63,111,53,147,104,15,9,144,0,9,144,0,9,144,64,
28,9,48,130,21,71,248,108,154,4,72,128,4,72,128,4,72,32,49,9,36,116,4,43,71,142,156,146,51,103,78,201,145,35,135,228,212,254,70,114,185,46,200,5,151,75,251,237,210,34,103,209,137,60,49,130,149,152,95,
14,246,138,4,72,128,4,72,128,4,194,37,144,48,2,43,135,228,144,164,164,188,146,170,189,94,167,65,189,186,210,160,126,61,169,175,253,174,88,169,146,20,42,92,88,59,150,71,49,58,123,246,156,164,165,157,148,
61,127,255,45,107,214,252,41,107,215,174,151,159,127,253,77,254,218,180,81,78,165,167,41,1,22,106,162,192,10,149,24,243,147,0,9,144,0,9,144,64,98,19,72,8,129,149,63,127,138,116,239,214,85,30,24,54,84,
106,213,173,227,142,86,133,226,186,109,219,182,201,27,19,38,202,123,31,125,44,135,15,30,16,45,198,21,116,113,10,172,160,81,49,35,9,144,0,9,144,0,9,56,130,128,173,5,86,222,124,201,210,251,63,189,100,216,
3,67,164,122,141,26,30,14,59,125,250,180,22,165,218,35,59,183,111,151,237,218,207,193,67,135,229,188,54,25,189,72,225,66,82,177,98,5,41,87,65,251,41,87,78,10,22,42,228,81,238,208,161,67,242,230,196,55,
101,210,123,31,200,206,29,91,131,18,90,20,88,142,248,174,176,147,36,64,2,36,64,2,36,16,18,1,132,106,226,246,163,173,34,116,229,204,149,43,228,159,130,133,139,186,62,157,242,137,54,149,42,51,105,171,17,
93,223,207,159,239,250,111,175,255,186,42,165,86,115,37,229,205,231,202,157,39,201,149,43,87,110,143,250,115,229,206,227,202,147,148,215,85,172,120,73,215,213,87,119,112,205,248,226,75,215,63,255,252,
227,81,215,201,147,39,93,221,187,247,80,229,3,217,23,79,126,108,59,126,231,46,217,147,61,207,1,158,3,60,7,120,14,100,115,14,196,23,78,56,2,171,110,221,75,92,203,151,46,117,11,162,99,199,142,185,158,121,
234,89,87,237,58,13,148,168,10,36,136,188,143,67,108,85,74,173,238,186,243,246,187,92,235,215,174,117,215,11,209,245,218,216,113,174,34,23,21,207,182,78,126,193,226,123,14,145,63,249,243,28,224,57,192,
115,128,231,128,5,207,129,248,58,37,84,129,85,165,106,117,215,182,173,219,220,34,104,161,22,177,170,90,189,102,150,40,85,168,34,75,207,95,160,80,17,215,179,79,63,227,66,52,76,79,147,222,122,59,219,72,
150,5,157,26,183,136,36,89,196,247,251,68,254,228,207,115,128,231,0,207,1,107,156,3,185,52,71,60,21,210,128,98,148,51,107,194,70,109,153,16,76,42,83,166,188,124,243,213,76,169,86,189,154,202,62,117,202,
84,185,165,79,63,217,183,119,119,48,197,131,202,115,246,236,25,249,241,167,197,178,228,231,95,165,69,243,166,82,164,104,81,185,164,225,165,226,58,231,146,197,63,47,241,185,202,48,88,251,131,50,128,153,
72,128,4,72,128,4,72,128,4,18,130,64,92,163,29,193,70,176,48,143,234,133,81,47,184,163,74,63,45,90,228,42,84,164,88,200,195,129,161,68,182,154,92,214,212,117,234,244,105,119,155,215,94,219,201,103,123,
124,90,176,198,211,2,253,64,63,240,28,224,57,192,115,128,231,128,85,206,1,219,172,34,108,112,73,67,249,241,135,133,146,146,146,34,127,254,241,135,180,239,208,41,170,145,43,95,82,25,27,149,118,188,182,
131,76,251,236,83,201,151,47,159,44,250,254,7,185,186,67,71,109,47,173,127,60,178,219,125,21,225,128,254,253,221,253,105,218,172,169,251,239,66,5,11,101,89,157,169,31,172,82,165,138,242,69,118,41,45,45,
77,54,111,222,236,51,203,198,13,27,228,248,137,227,238,99,75,180,232,160,158,38,77,158,156,16,79,46,236,4,9,144,0,9,144,128,115,9,216,66,96,105,209,43,249,234,139,47,228,154,235,58,42,79,117,233,210,77,
190,154,61,211,20,175,229,204,153,75,38,191,249,166,220,218,175,175,26,202,188,250,154,14,178,96,193,60,219,8,172,182,109,219,72,229,74,149,165,130,182,45,69,217,114,101,165,102,141,154,82,160,96,65,41,
85,170,148,148,40,81,194,20,134,225,54,178,127,255,126,217,187,119,175,156,60,113,66,214,111,88,47,39,142,159,208,54,135,93,35,91,183,109,149,249,243,23,132,91,45,203,145,0,9,144,0,9,144,64,204,9,216,
66,96,85,171,86,75,139,90,173,148,92,185,115,203,154,213,171,165,89,203,171,36,237,100,102,244,35,214,148,154,53,189,82,126,252,113,161,106,230,139,207,167,203,205,189,122,121,188,102,199,10,17,44,93,
72,33,2,165,139,168,250,245,235,103,139,102,213,170,85,234,56,4,204,134,141,27,212,223,199,143,31,151,53,127,172,241,40,55,249,221,119,163,138,184,127,191,126,30,245,213,213,118,220,47,244,239,126,100,
53,170,215,80,2,16,169,65,131,6,217,182,187,90,59,23,116,241,133,8,88,162,9,175,221,11,59,202,23,191,150,147,129,195,223,142,42,127,86,22,57,129,241,163,239,144,123,219,45,82,21,237,57,145,42,101,91,127,
19,121,165,172,193,177,4,120,62,37,166,235,109,33,176,238,28,112,167,76,124,115,130,242,64,231,206,93,228,235,111,102,251,245,70,145,162,197,229,146,122,245,4,55,106,188,246,102,227,95,155,100,197,170,
149,114,252,216,225,176,203,228,205,151,95,86,175,92,41,85,171,85,21,109,127,44,169,82,173,166,28,60,176,215,93,159,217,2,43,53,181,178,220,216,229,70,169,93,167,182,52,110,220,68,252,13,215,97,120,14,
246,46,95,190,204,45,156,142,30,61,42,211,181,104,160,157,82,183,174,93,165,72,145,34,162,11,177,70,141,26,75,129,2,5,84,191,189,147,62,44,185,108,217,82,89,251,231,90,249,114,198,151,178,101,203,86,59,
117,215,109,43,5,150,117,221,198,27,162,117,125,99,71,203,120,62,217,209,107,193,217,108,249,73,238,239,77,154,172,38,154,31,57,114,196,117,209,197,37,252,78,108,111,223,254,90,151,38,32,60,54,12,197,
63,216,207,170,195,181,215,251,44,135,61,181,252,149,233,216,161,179,42,131,141,73,63,159,250,169,187,222,90,117,46,241,168,75,195,28,83,134,154,160,114,13,27,58,212,245,217,180,105,46,77,52,101,233,159,
54,140,230,250,253,247,223,93,147,39,79,114,13,29,50,196,165,9,146,152,218,19,235,254,134,82,63,250,138,62,163,239,96,0,22,222,9,204,192,14,12,193,50,148,250,227,153,87,19,88,46,237,194,107,27,123,141,
172,150,126,217,219,133,159,120,242,139,101,219,240,203,133,101,53,213,15,252,148,93,91,95,205,154,149,229,156,140,228,131,246,237,219,101,105,175,106,213,42,174,141,27,55,122,84,235,43,95,48,76,62,254,
248,35,143,122,70,141,122,62,97,253,24,12,15,51,242,132,114,62,153,97,15,219,136,218,61,61,106,21,133,245,37,12,180,138,16,59,169,47,253,229,87,245,133,95,181,242,119,181,3,187,175,149,128,183,222,210,
71,229,89,190,116,153,171,251,77,61,93,53,53,17,84,181,70,93,215,181,154,176,154,249,229,12,215,153,51,103,92,200,99,44,219,164,73,83,151,246,106,28,215,180,79,166,185,218,180,185,218,85,77,203,95,187,
238,165,174,94,255,233,237,218,188,105,179,86,230,172,235,182,222,125,213,30,91,227,94,29,227,190,232,92,209,244,202,152,11,172,155,186,117,83,162,193,151,160,50,138,169,74,149,42,134,197,61,145,191,64,
96,98,20,93,190,4,23,216,130,177,149,57,68,83,96,141,124,188,191,18,3,102,245,23,226,106,253,156,238,166,181,103,86,191,244,118,66,185,33,154,33,176,96,215,205,61,122,120,156,234,203,151,47,15,153,191,
119,29,176,221,108,182,78,108,47,148,243,201,137,124,108,220,103,107,11,44,236,204,174,189,75,80,93,56,62,255,116,154,138,38,121,11,172,178,229,43,187,254,209,4,20,54,32,45,82,204,119,132,107,226,235,
111,168,58,234,215,111,164,202,23,45,86,210,117,234,84,186,235,127,223,124,235,115,19,81,108,56,10,65,135,212,160,65,35,215,99,143,60,106,16,88,45,98,34,176,112,195,71,164,101,223,190,125,30,23,202,77,
155,54,41,177,165,205,93,226,197,46,204,104,33,216,129,33,88,26,19,88,131,185,21,197,150,157,5,150,141,47,136,65,125,199,66,185,33,154,37,176,192,60,210,232,147,49,10,118,226,196,9,23,34,99,137,238,75,
43,244,47,148,243,41,92,123,123,116,187,78,69,91,241,160,53,127,74,127,250,53,204,123,73,136,252,173,45,176,10,105,239,28,60,124,248,176,186,39,190,242,210,43,62,163,87,99,95,25,171,162,77,85,171,213,
246,59,124,88,188,100,89,23,94,169,243,220,211,35,85,158,238,55,253,71,213,89,187,118,125,191,101,174,108,217,86,229,121,238,153,231,93,67,7,13,118,223,151,47,187,172,121,212,4,22,134,172,198,142,25,147,
69,84,253,244,227,143,174,167,159,122,202,197,8,85,244,207,79,48,5,91,48,246,22,91,240,133,89,195,136,184,224,33,202,163,15,53,33,234,99,188,161,121,11,44,68,161,244,11,36,202,124,48,254,78,143,139,36,
202,226,194,105,28,186,186,179,95,119,151,30,189,242,30,210,194,49,253,98,171,31,131,77,184,128,224,152,209,54,212,107,180,13,249,103,76,190,195,157,231,216,207,45,84,59,250,197,7,127,27,135,55,189,251,
138,186,219,183,109,105,219,139,124,40,55,68,163,192,250,251,239,191,99,218,103,248,8,109,232,41,20,145,52,113,226,4,143,239,3,135,6,163,127,237,241,119,115,14,229,124,10,241,6,239,62,223,140,215,14,124,
127,237,58,253,32,220,254,199,163,92,78,173,81,75,167,139,46,42,38,249,147,147,149,141,199,143,159,204,98,43,246,170,186,227,238,219,229,135,5,11,180,201,204,25,43,225,124,165,67,7,247,202,23,159,125,
46,237,175,110,171,14,55,189,252,114,89,185,124,185,182,122,110,157,223,50,191,253,182,68,180,119,19,74,251,246,109,180,85,131,23,50,243,97,105,64,132,9,171,254,190,157,51,71,219,39,106,139,12,26,60,88,
109,153,176,248,167,159,228,153,167,159,150,202,149,43,73,139,43,175,148,39,159,122,74,182,109,219,30,97,75,44,238,77,0,76,193,22,140,193,26,204,193,30,62,128,47,224,19,248,70,139,106,197,12,158,118,35,
148,119,134,29,147,19,167,243,73,206,198,235,213,15,210,236,241,13,125,182,169,9,30,121,228,134,197,106,85,33,242,94,243,112,9,185,188,234,97,209,68,150,59,63,202,150,45,122,92,29,67,30,228,237,208,188,
168,140,120,118,178,140,154,217,92,229,195,231,222,43,222,10,229,63,163,62,239,57,170,138,76,155,254,181,160,173,55,238,249,67,230,174,42,234,110,11,245,122,219,214,186,214,90,121,98,82,186,202,51,99,
121,29,185,175,195,6,65,191,144,234,84,202,37,87,212,56,165,254,214,132,84,150,190,162,223,87,53,203,120,35,3,83,244,8,108,218,180,89,94,27,55,206,93,33,22,131,140,121,117,76,192,6,180,249,90,210,187,
247,173,238,124,43,86,172,144,71,30,121,52,96,57,102,176,7,1,124,7,75,23,220,226,97,172,254,253,180,71,15,236,105,165,229,5,86,177,226,197,37,41,79,30,69,55,237,228,137,44,148,115,107,91,55,228,207,159,
172,137,43,207,147,199,151,59,54,105,171,234,46,186,232,34,117,168,72,145,2,178,107,231,46,159,175,190,209,203,158,59,119,86,180,185,88,170,12,30,3,162,145,176,169,39,182,71,152,55,111,190,92,115,237,
181,106,149,223,187,239,78,150,54,109,90,83,84,69,3,112,136,117,24,197,22,124,0,95,192,39,240,205,103,159,127,174,124,101,220,136,53,196,234,253,102,31,52,32,67,232,55,185,241,35,119,158,255,60,248,179,
84,47,254,135,104,209,158,44,229,122,180,43,36,11,55,54,119,111,217,48,119,254,34,121,247,127,249,164,75,163,63,85,94,136,34,148,29,243,153,8,142,33,97,123,135,46,253,3,111,241,240,217,15,25,205,65,92,
33,249,106,11,66,10,245,163,29,61,65,84,233,101,190,254,126,151,20,76,58,40,109,91,102,21,136,157,219,215,84,69,208,63,61,161,223,16,126,76,209,39,48,250,133,23,228,135,239,191,119,87,220,233,250,235,
229,174,59,51,133,184,175,22,71,60,58,66,173,204,213,211,240,225,15,71,223,48,214,24,55,2,184,38,96,59,17,99,250,101,67,254,184,217,227,148,134,45,47,176,10,107,251,35,229,204,153,97,230,17,109,139,1,
239,132,119,7,30,57,124,88,106,213,174,29,208,103,245,234,212,145,189,123,246,168,124,251,246,31,150,84,237,105,27,17,48,127,73,155,255,37,181,235,102,148,201,153,51,51,108,21,228,171,19,61,170,213,35,
86,239,76,154,36,216,159,74,155,251,163,34,39,5,181,61,159,250,247,31,32,11,23,102,94,16,3,118,132,25,98,66,0,62,128,47,224,19,248,6,62,130,175,224,51,68,180,224,195,104,165,242,197,69,9,18,45,84,239,
254,217,56,53,227,65,162,65,237,82,89,154,169,89,122,143,180,174,190,216,35,255,232,91,150,170,58,240,116,90,161,108,33,85,230,173,119,53,133,21,98,58,118,252,180,71,9,180,181,118,7,94,83,154,153,116,
33,165,183,131,35,199,211,50,31,59,142,28,205,250,240,163,151,70,95,55,238,171,44,136,174,48,153,67,96,228,243,35,213,131,130,158,158,120,242,73,191,13,15,127,248,97,105,117,213,85,238,227,111,188,49,
81,230,206,245,220,76,217,28,171,217,74,44,9,12,121,61,135,91,100,25,31,214,98,217,166,211,235,182,188,192,42,242,239,166,147,112,212,190,3,7,124,250,107,226,132,183,164,89,139,230,114,73,131,70,126,253,
89,182,108,69,185,161,235,141,242,245,215,223,170,60,191,252,246,155,212,169,91,87,219,204,210,247,144,12,242,180,108,209,74,42,167,166,106,101,254,39,136,148,101,166,208,226,89,218,188,30,153,57,115,
150,59,98,53,118,236,24,181,147,58,134,169,152,172,73,0,190,129,143,224,43,61,162,5,31,194,151,209,72,59,181,83,25,79,148,250,240,160,241,183,175,200,206,250,61,165,101,214,170,150,62,243,227,233,116,
199,238,140,141,119,141,17,166,112,237,68,91,181,43,156,247,40,174,71,213,244,118,66,169,27,125,173,94,114,171,123,248,48,148,178,204,27,30,1,8,164,143,62,250,208,93,184,116,233,210,162,205,177,202,82,
25,134,116,239,31,52,200,253,249,30,237,97,242,158,123,238,13,175,81,150,178,52,1,60,36,97,122,0,174,53,109,123,217,59,122,252,208,224,222,162,205,89,117,255,104,115,68,5,159,121,71,255,181,185,160,234,
1,52,94,201,242,2,171,116,169,204,215,185,28,58,124,196,39,167,151,113,19,60,113,82,230,126,55,71,74,151,41,159,37,15,94,119,51,238,213,151,37,175,246,62,193,169,218,78,236,72,115,231,207,149,125,123,
246,202,219,19,199,75,82,222,172,161,210,226,37,202,202,228,119,222,80,175,199,249,116,250,231,146,39,119,146,187,222,11,65,134,176,176,33,40,134,152,48,175,7,239,237,195,60,159,122,218,174,229,67,134,
12,141,151,191,217,110,136,4,224,43,248,12,190,131,15,225,75,248,20,190,141,36,141,155,52,95,10,228,61,174,46,16,122,194,102,131,198,255,141,245,79,155,119,92,58,55,88,36,200,163,39,92,84,244,255,17,185,
218,120,160,158,12,209,70,240,244,11,138,177,62,93,24,225,2,20,72,132,161,45,68,203,244,186,81,223,51,3,146,85,253,225,68,200,102,205,205,152,95,246,201,75,205,220,182,163,159,198,190,68,194,146,101,125,
19,128,80,250,235,175,191,220,7,239,190,251,30,109,62,105,59,143,204,79,105,15,18,16,95,122,66,228,150,137,4,172,78,224,139,217,63,203,164,175,78,75,193,124,167,5,67,157,111,77,223,43,229,75,229,87,215,
41,125,30,40,174,117,152,23,154,90,177,100,220,186,99,105,129,149,67,114,104,175,125,169,225,134,147,126,42,99,210,172,119,194,46,237,55,221,116,179,164,20,208,68,204,162,239,229,190,187,7,138,182,210,
79,46,189,244,114,249,111,207,91,228,183,37,75,164,117,219,214,210,174,93,71,217,177,35,99,152,226,244,169,147,210,180,121,75,41,160,13,65,206,253,230,27,233,217,253,63,90,254,203,164,73,227,166,50,108,
240,48,89,171,189,154,39,165,96,129,140,50,219,183,72,158,164,140,225,27,164,28,65,8,44,76,144,94,189,250,15,53,196,132,8,136,182,201,165,154,99,245,220,115,207,137,182,20,90,9,55,253,7,255,107,203,171,
125,246,77,91,5,228,247,24,10,32,188,143,122,240,219,87,194,201,134,186,81,143,177,77,124,230,125,177,245,46,175,173,126,202,82,70,63,121,205,62,99,97,43,236,9,54,105,251,249,168,252,198,62,227,111,124,
230,143,149,191,186,49,79,11,190,131,15,225,75,248,20,190,141,100,18,60,134,203,110,127,165,176,106,82,31,38,236,122,249,46,117,209,240,149,32,108,48,81,189,125,131,35,238,252,152,120,174,139,23,148,233,
52,112,133,236,62,82,72,254,247,194,126,149,199,88,31,202,47,223,217,68,166,62,178,89,158,232,157,166,158,246,252,37,228,189,123,98,61,119,91,168,15,245,162,254,112,18,34,108,232,43,46,134,122,95,241,
183,209,246,112,234,101,153,192,4,30,127,236,49,143,76,163,71,191,224,254,31,223,145,255,254,247,22,247,255,179,191,250,74,222,124,235,173,192,149,50,7,9,196,153,0,174,159,184,78,97,177,204,154,141,71,
220,115,65,75,23,222,35,111,61,115,149,18,89,99,238,11,109,164,41,86,93,138,233,178,97,205,232,108,235,207,110,163,81,236,121,245,245,172,175,212,210,97,109,21,159,171,122,205,186,126,183,84,192,214,11,
213,106,212,209,54,26,93,234,177,212,24,255,252,165,237,112,236,111,59,134,82,101,42,100,83,166,65,198,78,238,218,70,163,163,70,142,116,215,219,176,209,229,217,110,211,128,61,149,180,27,177,202,143,101,
210,216,109,92,187,169,171,229,211,216,252,207,123,249,51,150,71,227,152,175,37,220,40,143,189,109,252,113,68,189,72,248,237,157,7,237,32,125,191,112,161,218,132,80,63,142,29,158,245,165,227,104,219,87,
221,216,15,7,182,234,75,243,117,251,241,185,158,31,182,5,147,244,58,188,151,129,123,151,53,214,237,109,19,24,4,187,228,92,239,27,202,24,183,22,0,3,244,9,73,103,234,189,177,162,191,254,232,182,193,151,
122,191,225,99,43,238,159,21,232,59,199,227,145,47,191,15,101,89,189,153,219,52,248,242,173,191,189,177,184,231,85,228,231,65,180,190,75,161,156,79,209,106,51,17,234,193,214,54,216,82,6,125,1,67,252,96,
75,25,125,219,24,227,241,56,245,55,190,39,89,118,2,11,187,184,175,248,247,134,152,158,158,230,42,85,166,124,182,2,11,98,40,79,82,62,87,93,109,51,209,246,237,174,117,181,107,123,141,171,78,157,75,125,110,
36,106,220,172,52,80,25,181,147,251,152,177,238,123,239,37,151,54,241,43,176,176,135,146,190,81,168,46,174,180,21,60,110,161,227,207,201,16,2,190,94,109,17,174,192,210,197,140,63,1,5,59,116,113,230,45,
224,116,123,241,219,104,47,196,72,118,175,223,128,144,203,78,36,233,54,133,179,121,161,190,183,79,118,253,129,173,176,1,204,140,130,210,155,57,234,128,157,254,242,4,98,110,20,89,240,181,89,251,102,197,
233,2,17,215,7,48,171,246,57,148,27,98,188,5,150,247,222,88,248,46,233,223,113,253,162,198,61,175,226,123,31,12,229,124,178,234,119,34,30,118,249,18,88,56,223,245,61,190,226,45,176,44,61,68,152,148,148,
87,74,253,59,63,224,192,254,3,218,106,193,131,1,163,120,231,207,159,213,94,242,251,187,204,95,56,87,22,124,63,79,214,173,95,173,237,97,229,57,97,215,187,146,128,101,114,228,144,66,134,201,246,231,207,
27,246,196,242,170,108,226,132,137,106,63,37,164,193,218,228,81,188,88,121,232,176,97,106,46,196,85,173,91,251,181,31,33,207,104,173,220,65,120,20,123,218,32,228,159,221,132,85,44,231,198,138,33,12,19,
24,151,113,227,197,202,190,210,167,211,166,69,205,198,128,142,52,100,192,144,30,230,137,96,120,174,139,246,146,107,127,73,95,13,245,250,235,227,5,182,250,75,96,82,189,122,245,108,243,100,103,31,124,10,
223,34,193,215,240,57,19,9,88,149,128,247,222,88,248,46,25,87,21,114,207,43,171,122,142,118,133,67,0,231,59,182,168,177,66,178,180,192,42,82,180,152,123,223,42,237,37,190,114,254,124,246,66,41,150,64,
147,255,221,236,20,109,156,247,35,216,176,140,31,251,39,33,253,239,219,111,101,242,187,239,170,249,62,213,170,85,147,119,39,155,183,106,3,19,87,177,167,205,107,227,95,11,136,4,98,3,43,135,122,246,236,
233,206,171,189,252,90,253,125,251,29,153,19,170,3,86,20,195,12,221,181,185,34,176,17,194,9,55,7,127,115,168,250,105,123,140,33,159,25,27,36,194,183,240,49,18,124,30,233,22,14,250,132,116,227,182,13,90,
152,91,77,4,143,100,21,12,202,250,170,27,237,104,59,177,135,60,209,28,101,116,27,253,77,200,247,117,42,96,98,189,177,111,217,245,9,121,97,179,254,99,172,15,199,176,185,170,177,46,252,141,207,2,77,222,
15,116,138,162,61,44,28,240,85,119,118,115,214,2,213,107,133,227,222,123,99,25,39,182,71,186,231,149,63,127,225,65,15,76,113,30,27,153,194,87,254,252,239,207,191,168,199,215,254,112,193,176,133,239,80,
222,219,175,218,206,230,234,243,72,231,149,194,46,212,131,250,124,157,59,88,201,22,73,66,121,227,247,78,111,35,212,115,30,245,24,237,243,103,83,188,190,127,217,113,4,95,95,223,193,71,95,223,238,94,120,
131,133,67,248,49,38,227,241,72,124,16,110,89,75,11,172,66,133,10,75,222,164,140,213,123,59,182,109,83,19,150,227,149,176,130,12,9,54,156,61,123,206,167,25,189,122,245,114,127,254,217,103,25,251,17,53,
111,222,92,69,94,112,129,51,43,181,105,211,86,240,84,26,108,68,108,249,178,101,210,168,113,99,183,121,152,232,138,242,13,27,54,20,109,56,193,231,242,110,179,250,130,201,237,176,99,198,140,47,149,112,2,
203,107,255,21,177,70,27,144,15,66,22,249,204,74,223,125,247,157,187,41,163,239,67,105,31,23,21,92,152,239,109,183,72,26,149,95,234,81,20,123,92,225,115,76,50,15,245,34,141,27,24,196,2,202,250,170,27,
13,97,85,34,142,225,162,107,165,21,125,117,171,23,85,118,225,7,19,245,145,112,19,132,160,195,14,243,189,155,254,187,51,170,129,22,62,195,49,244,57,212,132,11,55,68,0,218,195,234,73,239,132,186,177,231,
152,246,122,159,136,196,110,168,118,69,59,191,247,222,88,168,63,26,123,94,249,242,23,110,210,203,63,44,173,152,226,60,54,38,240,196,121,233,125,195,132,239,252,249,23,245,96,129,134,241,205,5,129,248,
224,187,5,159,193,119,40,239,157,176,179,57,62,199,254,115,225,156,255,248,142,225,156,132,93,168,199,123,167,116,180,135,190,226,13,12,248,142,135,250,0,160,219,143,242,248,174,250,58,47,195,61,231,179,
99,103,246,247,47,24,142,224,11,63,122,115,212,55,85,70,127,16,185,242,222,107,207,120,60,208,249,18,139,227,150,22,88,133,11,21,212,150,236,101,108,240,185,98,229,239,217,238,186,30,11,56,122,157,57,
52,27,50,5,214,5,193,14,239,190,82,227,198,77,220,31,35,194,129,132,77,43,205,78,104,243,196,241,140,125,145,130,73,199,142,31,83,17,47,227,147,92,163,70,141,228,255,254,239,99,21,49,194,242,110,172,66,
244,181,143,78,48,245,71,146,231,182,219,110,83,162,234,213,87,95,85,213,104,115,172,212,166,136,222,43,32,47,42,154,177,67,191,153,233,85,195,158,88,70,223,7,107,131,254,186,28,95,23,102,239,58,112,145,
13,246,38,128,11,249,231,207,94,240,41,22,252,217,134,11,24,110,22,145,62,205,7,219,247,80,242,193,38,188,166,199,91,128,250,170,3,2,41,20,145,133,27,182,190,97,107,32,155,176,147,61,184,134,27,73,9,84,
127,162,28,7,31,220,248,189,133,149,119,255,192,93,103,137,115,207,151,184,245,46,3,193,18,204,247,0,226,13,194,7,62,11,38,225,252,15,166,94,189,46,212,15,145,24,204,57,137,50,248,142,131,73,176,15,74,
224,130,87,105,5,99,127,168,231,124,48,60,140,121,98,249,253,139,53,199,80,251,26,237,252,150,22,88,101,75,103,238,104,189,126,99,230,126,46,209,134,16,76,125,250,251,16,207,104,209,171,51,103,254,9,166,
72,212,242,96,142,148,247,118,3,250,255,163,70,143,142,90,59,149,43,123,238,237,116,203,45,189,181,168,80,85,53,151,11,2,12,66,11,2,39,210,244,215,95,155,124,246,7,203,198,189,19,162,113,136,176,233,79,
38,31,127,252,177,202,2,225,101,247,244,248,160,118,30,55,161,9,243,60,55,18,29,254,113,19,181,247,148,158,110,109,169,189,23,51,192,166,121,250,123,4,141,55,55,108,207,128,45,30,140,155,153,86,239,121,
86,208,158,241,245,25,184,89,64,200,88,77,100,97,217,53,110,52,39,206,92,172,108,134,237,198,190,224,51,99,194,13,39,152,27,25,110,168,222,209,48,108,230,10,238,198,250,241,142,70,189,13,112,197,242,239,
66,41,225,189,144,20,15,44,254,190,203,129,62,15,101,155,18,95,223,141,251,7,222,239,241,58,28,228,241,181,55,86,164,223,43,125,121,60,118,11,199,118,31,217,249,234,193,91,46,82,81,41,93,168,248,43,3,
223,235,9,98,40,208,16,51,196,155,158,178,59,111,140,231,127,160,122,245,250,32,10,140,245,227,115,95,231,13,222,9,234,125,110,226,65,41,152,72,22,24,226,92,139,246,57,31,142,111,99,245,253,243,197,17,
188,240,125,11,116,173,2,71,59,12,219,91,90,96,85,170,88,81,157,15,184,240,236,250,247,21,55,225,156,32,209,40,147,146,146,241,194,233,127,78,159,150,83,126,246,227,242,213,14,34,63,254,18,246,162,242,
190,168,250,202,143,72,18,162,104,190,126,30,25,62,60,75,245,168,163,160,182,191,87,176,169,176,54,20,139,40,145,175,33,69,8,155,235,59,119,86,66,11,195,134,136,30,69,26,201,66,93,190,250,226,61,49,93,
91,217,164,34,104,223,254,59,215,9,253,65,30,44,24,128,240,50,166,195,71,14,7,219,93,203,228,195,203,154,245,4,1,228,61,49,243,197,177,31,73,205,14,25,251,87,65,104,221,244,120,78,247,123,6,125,117,2,
194,232,197,1,25,175,130,210,19,196,130,175,247,254,233,19,65,177,179,243,71,75,90,185,243,67,200,188,252,136,39,219,120,2,195,147,63,4,19,24,52,186,117,143,98,228,61,12,128,207,112,81,54,166,110,205,
178,143,224,34,66,96,28,54,194,141,12,98,0,239,110,4,119,99,194,14,216,104,3,194,14,118,192,38,253,29,144,241,100,19,74,219,88,196,130,119,18,250,74,198,189,177,66,169,211,87,94,176,193,15,110,148,216,
45,220,123,99,90,112,4,103,61,65,88,233,34,55,187,50,250,158,113,122,185,91,186,212,202,214,84,93,144,5,58,111,90,221,190,193,227,33,227,222,94,25,239,205,244,151,32,236,70,244,216,234,62,156,221,121,
131,225,41,244,23,66,75,127,80,194,247,49,208,102,189,58,195,64,182,135,122,206,135,227,219,88,125,255,188,57,162,175,248,126,129,151,254,90,46,221,94,127,215,42,248,33,208,3,103,56,125,142,102,25,75,
11,172,10,229,51,118,101,199,205,127,187,54,7,43,94,9,98,32,249,223,57,88,16,87,167,79,165,249,52,101,217,178,204,167,166,161,67,134,168,60,139,23,47,86,79,141,190,38,102,35,66,100,20,26,16,82,209,72,
11,22,204,87,243,150,2,109,36,234,190,200,105,243,175,16,37,202,46,225,36,199,176,33,38,145,95,126,249,21,209,48,51,96,29,87,95,125,141,106,207,123,254,218,116,109,103,125,239,201,238,16,135,16,94,217,
173,50,12,216,96,136,25,116,31,163,152,209,247,193,86,83,48,95,230,121,180,106,237,94,191,197,240,146,100,8,173,64,243,9,32,140,140,145,43,220,200,188,197,130,175,70,110,27,248,150,135,200,194,124,143,
96,158,178,131,237,103,164,249,16,101,0,131,236,222,101,136,139,178,49,90,0,161,152,93,36,14,145,19,99,194,13,60,208,141,15,237,67,172,226,102,25,104,248,43,210,62,71,187,188,113,213,32,190,39,152,123,
165,39,92,43,240,48,19,173,132,155,101,118,171,184,244,77,111,141,237,5,42,3,255,34,186,165,39,227,195,137,183,221,168,31,15,35,120,112,128,191,178,59,111,112,236,139,95,203,185,171,104,93,107,109,182,
24,32,192,140,190,15,230,188,81,66,235,229,125,234,33,32,152,239,35,12,136,197,57,31,174,127,99,97,139,145,35,190,79,129,252,164,219,142,107,149,126,30,168,57,170,1,4,113,184,125,142,86,57,203,10,44,188,
132,185,126,131,140,39,157,125,218,10,194,35,113,140,80,228,209,38,218,167,252,251,166,249,52,77,236,157,61,235,123,14,214,148,41,83,220,126,233,218,181,171,250,27,226,0,23,52,172,112,51,43,97,21,33,68,
41,134,4,2,37,68,163,32,86,166,78,157,26,40,171,58,14,193,99,198,188,50,12,23,226,194,239,107,72,101,248,240,71,148,45,88,93,104,76,88,169,137,252,193,220,44,130,21,159,217,65,209,125,140,60,70,223,7,
5,82,203,116,226,116,198,194,9,164,74,229,253,207,33,11,230,37,201,16,19,198,137,176,24,178,8,36,24,140,118,62,59,110,158,199,147,124,143,118,193,71,64,131,237,111,184,249,222,95,80,58,168,23,69,255,184,
116,183,71,19,93,59,101,190,154,199,120,0,209,43,227,220,25,8,51,239,167,230,236,108,197,205,50,220,132,239,143,191,104,116,160,207,17,73,14,39,233,223,113,189,44,30,80,48,167,209,248,50,232,251,238,27,
24,181,161,225,207,178,174,65,200,98,54,94,111,98,76,193,148,49,190,128,28,59,118,103,151,32,106,112,51,14,38,25,207,27,253,229,233,190,202,33,90,226,253,29,11,246,188,129,61,193,230,69,219,209,62,231,
131,225,224,47,79,180,109,241,190,86,61,49,41,61,36,243,240,90,28,61,5,18,196,33,85,28,131,204,150,21,88,73,154,168,169,90,189,154,234,242,218,63,215,202,133,56,110,209,144,146,82,208,29,193,58,174,77,
30,247,183,154,113,254,252,5,242,185,190,122,176,69,11,209,35,28,120,93,5,110,252,209,152,191,20,204,57,128,27,50,94,244,138,33,129,236,134,243,16,85,195,28,12,68,206,244,87,100,64,120,224,213,61,254,
202,161,31,27,214,103,188,91,46,150,233,250,206,215,171,27,128,191,155,14,158,192,33,192,140,243,182,244,165,232,184,89,248,154,207,165,219,139,190,125,247,221,92,143,189,191,66,237,11,124,219,92,243,
49,18,124,14,223,135,154,230,174,42,234,46,50,232,134,67,17,69,141,6,13,240,28,214,155,48,37,52,31,101,121,146,215,134,229,172,50,23,235,189,79,190,15,10,173,247,13,172,112,193,204,247,135,26,43,184,178,
73,89,143,250,188,133,89,160,198,112,179,52,70,83,2,229,143,231,113,124,159,241,29,215,147,190,231,149,126,141,208,63,71,148,125,204,171,209,121,145,57,222,19,23,40,29,79,243,220,114,39,212,50,209,140,
32,30,57,234,57,141,195,223,187,235,58,183,247,28,62,156,242,141,167,160,15,212,231,80,142,71,251,156,15,165,109,239,188,209,182,197,120,173,66,244,42,20,225,9,219,144,95,159,59,135,243,192,202,115,177,
44,43,176,202,150,171,40,165,74,102,188,164,113,245,234,53,113,91,65,136,246,83,82,10,72,114,254,140,39,174,227,199,178,159,219,241,240,240,135,101,203,150,45,42,239,211,207,60,35,218,174,223,106,222,
208,0,45,130,85,93,123,175,162,47,241,2,161,3,241,133,201,236,209,18,97,216,223,106,244,232,81,238,137,233,70,193,161,191,215,15,19,228,33,84,48,84,169,39,12,181,65,64,225,162,108,156,84,139,155,173,246,
154,25,21,189,10,102,127,173,72,190,208,40,139,57,86,51,103,206,240,91,141,254,4,14,33,102,76,216,204,21,12,167,126,250,169,122,7,163,81,36,128,1,250,224,45,42,67,181,21,62,133,111,145,224,107,248,60,
156,132,61,91,244,11,133,190,202,8,203,202,195,217,155,167,124,241,76,11,112,209,10,52,156,232,203,94,188,211,203,152,26,54,200,126,62,74,56,125,14,181,12,230,184,4,19,193,11,165,94,35,43,212,31,234,5,
30,109,25,163,41,161,180,109,118,94,239,249,85,198,61,175,188,95,6,141,7,50,227,134,195,225,216,26,174,191,162,237,99,216,174,239,1,231,107,127,42,227,126,80,88,13,24,76,138,198,121,19,76,59,225,50,12,
166,238,80,243,196,194,22,227,2,17,12,229,123,239,29,22,204,255,198,149,215,120,201,179,85,147,101,5,86,163,75,234,107,47,88,206,120,2,93,183,110,93,92,249,229,203,151,95,114,229,202,165,108,56,176,111,
95,182,251,113,109,217,178,85,30,126,232,33,73,75,75,83,115,175,222,255,224,3,183,200,42,83,166,140,204,155,55,87,123,129,116,123,143,201,237,247,107,187,130,239,218,189,75,122,222,124,179,154,80,30,173,
132,125,163,174,190,186,189,170,123,146,54,124,166,79,168,71,244,6,91,51,160,61,95,59,189,195,6,136,179,50,101,203,186,203,96,229,31,182,126,232,218,245,198,160,247,215,10,183,31,250,144,198,87,179,190,
242,91,5,46,200,152,55,118,195,13,93,178,68,90,96,63,38,255,99,242,190,113,197,34,68,215,186,117,107,85,191,141,162,50,20,59,33,174,224,83,248,22,62,134,175,225,243,112,18,250,208,231,185,147,30,43,5,
113,193,209,247,230,9,101,163,209,178,23,101,190,8,29,47,64,13,39,109,217,238,57,244,149,221,176,101,56,245,135,83,230,228,63,209,31,170,52,178,218,184,207,115,229,108,176,54,122,71,96,130,45,103,102,
62,12,149,35,202,171,39,95,123,94,221,123,111,102,116,11,249,140,115,181,194,177,53,22,254,10,199,14,60,164,232,123,192,5,179,13,74,48,109,68,227,188,9,166,29,171,48,132,173,177,176,165,92,49,223,251,
72,6,195,198,87,158,112,87,244,134,219,94,40,229,44,41,176,48,255,170,83,199,140,29,209,145,214,105,55,247,120,166,228,252,153,55,172,205,91,181,155,105,128,13,79,63,159,62,93,250,104,219,8,32,186,161,
139,172,167,181,121,81,72,250,107,90,140,67,95,16,94,184,225,251,122,189,11,34,70,217,137,1,12,139,161,46,127,27,153,34,34,133,242,168,199,216,166,191,246,116,206,16,103,152,212,110,44,131,232,80,118,
155,151,226,56,94,65,227,47,161,239,168,47,208,211,170,158,47,187,215,221,160,13,180,135,126,249,170,15,60,32,180,188,135,24,3,245,27,245,250,99,14,31,234,226,10,190,133,143,225,235,72,18,34,77,152,192,
142,121,64,198,45,25,148,29,134,141,70,177,183,147,213,87,204,68,194,33,94,101,11,230,59,29,175,166,99,218,46,34,183,24,42,215,19,230,126,249,122,152,194,247,217,56,225,29,83,0,34,93,37,28,211,142,5,81,
57,182,125,240,181,177,104,16,69,153,197,134,4,10,39,199,111,3,242,64,184,44,41,176,242,39,167,72,171,54,109,148,237,71,142,28,145,29,59,182,5,234,71,76,143,23,40,144,57,25,249,175,77,218,30,78,234,189,
160,217,39,220,120,49,20,247,243,191,171,8,241,100,248,211,143,63,74,235,214,87,5,42,202,227,22,35,0,159,193,119,240,33,4,51,124,10,223,70,42,174,140,221,196,170,43,8,45,125,239,28,172,170,50,38,108,85,
128,77,46,253,137,172,221,135,51,195,228,101,138,28,10,139,160,247,220,147,109,59,237,183,245,69,48,29,55,178,10,52,89,218,95,125,133,82,50,34,218,86,77,152,79,133,115,85,79,207,60,253,180,95,83,245,215,
101,233,25,98,177,55,150,89,156,176,250,213,184,183,25,134,224,189,247,151,51,238,177,132,191,241,157,11,38,25,207,155,234,37,195,139,90,7,211,78,162,231,57,113,42,243,187,131,235,156,183,63,66,253,31,
91,171,88,53,89,82,96,85,172,80,73,202,149,203,88,58,251,235,207,75,228,216,81,207,185,33,102,195,44,93,42,115,195,211,125,251,14,4,221,60,134,142,48,17,122,220,216,177,106,56,9,127,207,210,134,189,38,
79,158,36,149,42,101,236,241,197,100,93,2,240,17,124,5,159,193,119,240,33,124,137,191,195,29,22,12,212,91,125,239,28,44,91,198,133,198,184,245,0,34,90,227,31,200,152,151,232,157,118,26,78,75,12,137,132,
19,237,194,43,50,140,105,197,170,208,38,202,103,215,55,239,186,3,113,136,229,113,35,43,48,13,103,103,246,43,106,100,14,201,198,210,214,112,234,246,222,243,10,27,5,235,139,88,252,213,231,45,192,162,185,
55,86,56,125,8,183,76,179,75,51,87,227,98,254,16,134,224,163,245,226,223,104,156,55,225,246,43,145,202,25,57,66,168,90,101,49,77,44,24,91,82,96,213,175,83,71,13,237,32,77,251,124,186,92,240,243,114,229,
88,0,241,85,103,169,18,25,79,56,152,195,116,80,139,168,133,154,6,107,43,206,234,215,175,167,94,14,140,167,202,126,253,250,203,31,127,172,161,208,10,21,164,73,249,117,97,5,31,193,87,240,25,124,7,31,194,
151,102,38,239,77,52,49,71,203,215,170,25,239,151,156,134,186,63,12,46,114,250,123,255,208,63,172,146,243,53,244,122,44,61,115,7,243,80,158,226,107,87,136,223,139,218,189,253,53,107,174,167,112,236,213,
209,115,85,97,32,255,66,188,6,251,138,148,64,117,197,226,184,113,30,21,134,6,135,12,13,124,206,66,128,65,136,233,41,218,123,99,197,162,159,190,234,52,238,143,53,99,121,157,176,22,123,248,179,53,210,243,
198,44,6,86,111,199,200,17,15,56,222,43,160,173,110,127,40,246,89,78,96,105,251,149,75,199,14,215,168,62,96,75,132,111,231,206,13,165,63,49,201,91,242,223,213,140,136,96,108,223,190,45,172,54,16,241,184,
182,67,7,109,130,123,219,44,66,235,219,57,115,56,116,24,22,213,232,22,106,221,250,42,129,47,188,133,21,124,6,223,197,34,106,21,76,164,9,171,220,140,67,134,190,86,205,64,12,97,239,43,61,133,186,89,40,94,
219,99,156,12,60,109,158,239,213,178,127,110,206,220,179,6,23,199,96,54,36,69,132,40,152,247,204,69,215,155,254,107,67,148,208,200,19,172,66,137,98,249,139,34,154,101,127,118,237,120,239,121,245,218,184,
113,1,231,60,234,245,65,136,65,144,233,41,154,123,99,153,197,198,184,121,239,174,253,193,77,166,46,90,36,184,247,197,226,188,241,254,142,133,114,222,4,243,250,38,179,56,197,179,29,111,142,193,188,2,204,
219,94,187,176,180,156,192,202,171,173,216,187,170,77,107,197,115,197,210,101,178,127,159,255,29,174,205,56,73,32,248,170,84,169,164,154,58,122,244,168,28,57,20,222,252,22,221,86,236,151,100,20,90,136,
212,93,115,237,181,178,96,193,66,237,66,184,73,48,145,154,195,135,102,120,54,163,13,176,6,115,176,135,15,224,11,248,4,17,43,93,88,133,179,199,85,160,30,32,10,133,229,227,239,63,230,249,146,237,64,229,
178,59,142,189,175,140,239,108,195,203,101,131,217,35,6,147,130,141,243,86,16,189,242,183,73,169,247,126,69,67,186,103,111,49,110,64,250,187,233,34,233,91,180,203,190,244,177,231,252,50,188,88,55,144,
88,68,148,15,47,37,70,20,209,248,14,187,104,219,22,110,125,222,123,94,253,240,253,247,126,23,191,248,106,3,34,29,130,76,79,209,220,27,43,220,62,133,90,238,239,163,197,220,69,202,149,200,29,84,241,80,34,
152,222,223,177,80,206,27,188,63,15,223,53,38,17,227,62,125,120,80,195,117,48,208,247,15,220,112,61,193,86,54,96,25,202,203,185,227,197,220,114,2,235,210,75,27,106,219,3,148,81,60,230,105,98,196,229,186,
16,22,27,8,163,104,164,28,57,115,170,253,171,144,246,254,253,183,156,59,31,220,83,81,160,182,117,161,133,97,167,103,181,61,149,176,42,173,74,149,42,106,34,245,214,173,219,212,164,234,49,99,94,101,100,
43,16,200,48,142,183,110,125,149,98,11,198,96,13,230,96,15,31,192,23,240,9,68,112,44,132,21,204,213,223,195,165,191,115,44,208,11,150,189,119,30,223,185,215,247,252,31,60,25,62,52,169,180,7,17,188,148,
22,162,192,251,137,15,98,1,23,40,136,60,163,184,194,74,198,59,159,248,222,47,85,239,72,25,196,6,46,120,222,245,195,102,220,76,166,62,178,217,253,110,186,48,92,21,179,34,222,175,214,193,69,30,130,116,198,
228,59,178,136,82,244,5,172,54,78,205,163,134,6,33,174,140,175,87,137,153,145,33,86,108,156,55,133,77,122,71,62,63,50,196,26,50,222,60,1,97,166,167,104,236,141,21,178,17,17,20,88,187,43,227,157,177,72,
120,95,100,160,8,49,252,106,220,157,61,80,211,248,142,141,156,150,185,181,71,118,231,141,190,15,151,126,222,160,110,124,215,236,32,12,2,113,136,244,56,56,226,253,171,122,210,247,1,196,106,105,95,209,41,
124,134,239,38,174,39,184,230,32,97,165,104,40,17,196,72,109,14,167,188,165,4,22,68,81,143,174,93,36,167,38,106,144,22,255,242,155,246,119,46,169,91,239,18,169,93,167,129,250,59,80,66,158,43,91,180,148,
62,183,222,42,197,138,25,118,95,204,166,96,82,222,124,82,174,124,69,201,157,59,235,206,207,73,73,121,165,236,191,19,238,215,105,59,202,187,46,132,39,248,252,53,143,97,39,253,6,143,136,9,38,81,227,70,143,
137,212,131,7,15,81,81,149,189,218,171,130,166,77,251,84,237,12,207,232,86,160,51,32,235,113,48,3,59,48,4,75,48,5,219,140,201,234,91,20,115,176,215,5,110,44,134,2,141,86,121,95,164,113,193,88,254,97,105,
159,27,140,226,98,140,167,100,61,33,66,149,221,174,215,136,60,225,29,132,198,72,22,68,1,158,248,140,27,248,225,162,143,11,148,113,88,16,226,170,211,192,21,1,135,148,30,24,149,185,65,42,236,130,253,222,
245,227,66,168,11,55,12,171,120,207,95,9,221,139,209,47,129,249,109,198,23,93,163,5,220,108,33,74,141,172,208,23,125,217,63,184,14,121,61,58,15,111,209,236,145,247,158,87,120,147,67,118,91,170,100,215,
54,132,153,241,53,58,145,238,141,21,205,126,6,170,235,231,149,153,145,73,136,31,172,188,245,181,113,47,62,195,131,7,252,106,252,174,4,170,31,199,241,62,65,188,180,217,152,124,157,55,250,62,92,198,124,
56,223,162,53,233,62,24,91,173,156,103,196,179,147,179,112,196,84,2,239,107,9,190,139,248,204,91,8,227,58,23,206,38,193,102,50,177,148,192,202,159,92,64,186,222,212,77,245,255,248,177,99,114,248,200,33,
153,244,230,155,178,244,215,159,101,249,210,37,242,192,144,161,218,134,159,254,195,190,16,87,247,220,113,167,182,153,231,119,50,233,221,201,178,66,123,249,114,243,102,153,243,82,124,129,45,94,188,180,
124,61,99,134,172,89,181,82,38,104,55,218,2,5,139,120,100,171,88,41,85,138,22,205,88,93,181,113,211,150,160,182,104,8,215,129,136,152,96,18,53,110,244,186,216,90,189,122,181,96,14,88,247,238,61,228,21,
237,253,97,136,184,96,56,11,98,1,67,91,173,91,95,21,110,115,9,91,78,237,180,174,177,1,35,176,2,51,176,3,67,176,4,83,163,168,2,243,88,69,171,252,65,198,69,218,123,133,160,190,193,168,241,230,142,207,140,
175,5,249,112,81,237,128,2,72,127,217,109,40,175,115,129,45,216,38,34,208,30,101,232,143,175,13,82,253,245,19,55,20,43,47,163,198,251,234,112,179,12,230,38,139,121,91,120,137,176,213,46,234,222,123,94,
225,221,167,190,246,188,10,246,11,15,97,6,129,166,39,59,237,141,133,115,223,120,222,235,123,201,225,129,194,251,123,165,47,84,48,70,164,130,101,132,239,47,94,222,236,189,157,138,191,242,56,191,112,158,
5,251,126,196,96,237,176,123,62,112,196,54,25,161,92,171,192,28,101,66,121,215,106,188,56,89,74,96,85,171,94,67,139,36,149,87,44,86,174,88,33,227,95,125,69,110,235,215,87,240,94,66,252,140,28,53,82,6,
221,119,159,207,72,22,132,215,131,218,141,114,204,248,113,90,36,42,67,132,149,43,95,78,190,249,102,150,92,213,170,141,22,27,203,250,212,153,148,39,175,76,124,109,172,180,209,246,52,42,88,168,144,12,184,
75,139,22,188,49,65,242,229,207,220,247,170,94,157,90,238,250,176,7,150,89,73,23,91,13,26,52,80,115,130,30,24,54,76,189,243,14,226,0,2,12,98,1,79,150,136,198,156,56,113,66,126,255,253,119,183,232,234,
223,175,159,89,102,198,189,29,244,85,23,83,96,0,22,216,159,10,108,192,8,172,192,12,236,192,16,44,193,52,30,162,202,27,22,158,100,241,20,22,236,124,30,136,160,96,159,126,17,37,107,219,107,178,223,125,181,
96,11,34,75,250,30,65,193,214,171,247,65,223,32,21,97,126,239,139,35,110,38,168,23,55,32,227,13,5,159,233,63,91,183,199,238,61,110,161,158,148,184,200,23,110,246,147,178,205,215,133,30,34,17,55,71,108,
157,161,191,130,8,175,21,210,251,18,239,225,194,79,63,157,230,177,231,21,222,125,26,105,130,64,195,123,11,245,132,189,177,34,125,141,78,164,54,5,91,30,231,125,48,55,108,93,244,4,243,30,68,95,109,67,104,
227,156,192,121,142,115,193,215,247,88,255,142,225,252,194,121,198,148,149,64,48,215,42,125,63,51,176,54,126,15,173,206,19,170,35,240,174,153,49,236,69,238,60,218,147,197,191,195,110,119,244,191,67,222,
120,107,162,106,45,61,61,93,146,147,51,198,211,177,178,229,162,98,197,36,175,38,178,206,157,59,39,119,220,126,167,124,168,189,103,78,159,159,149,91,19,74,195,135,61,32,79,63,151,177,153,222,233,127,254,
145,133,218,234,195,14,157,58,185,255,239,115,107,95,249,252,139,207,221,101,10,22,42,170,4,92,239,62,183,170,60,168,87,23,102,99,94,30,35,143,60,254,152,246,217,89,77,128,189,38,119,220,125,151,202,211,
184,73,83,89,185,114,105,22,26,241,120,17,53,222,109,216,180,89,83,169,89,163,166,84,173,86,77,74,252,187,149,132,209,56,132,249,55,111,222,172,189,255,112,131,18,30,127,174,249,83,142,105,145,193,249,
11,230,203,182,109,219,99,232,213,232,85,141,225,189,182,218,123,9,11,23,46,44,117,234,214,81,187,172,87,215,132,56,132,147,113,35,69,189,197,253,251,247,203,38,237,9,126,253,134,245,178,68,219,67,13,
175,8,178,67,194,28,131,58,149,114,101,9,131,235,243,125,48,196,22,206,251,5,237,208,119,218,72,2,177,32,128,73,211,216,127,205,123,87,119,245,174,78,237,69,235,216,218,4,209,88,68,0,141,91,5,240,187,
22,11,111,56,179,78,203,8,44,68,152,62,155,250,137,220,120,211,77,30,158,216,162,125,1,174,189,174,147,180,185,170,149,188,62,225,117,37,130,32,160,110,236,210,85,155,99,240,157,246,190,194,188,50,246,
149,151,228,206,187,239,86,229,78,157,58,37,157,59,223,40,139,126,92,36,195,31,124,64,158,124,250,41,53,167,11,123,105,13,127,240,97,25,251,250,235,74,208,189,56,106,180,12,125,96,168,42,243,235,146,95,
100,196,19,79,200,167,90,251,197,52,33,135,244,198,132,9,242,200,99,143,107,67,147,191,73,149,170,85,213,38,147,169,85,107,200,193,3,89,87,53,198,67,96,121,159,174,169,169,149,165,77,235,54,82,183,110,
93,41,171,189,67,16,19,243,33,66,82,82,50,163,113,222,101,246,105,239,85,196,156,36,36,93,132,225,239,93,59,119,105,187,231,239,240,200,62,249,221,119,163,242,13,241,142,174,85,168,80,65,69,26,145,116,
241,132,191,253,9,40,221,8,248,67,137,199,13,27,100,247,238,221,178,102,205,26,89,176,112,65,76,182,82,136,74,199,89,9,9,144,0,9,144,128,227,8,32,130,21,183,31,45,130,229,202,153,43,151,171,104,177,226,
174,3,251,247,107,123,121,102,166,79,167,124,226,42,83,182,130,58,158,59,79,146,235,254,251,238,119,157,191,112,94,101,56,149,158,238,234,220,185,171,107,220,152,113,238,2,199,142,30,115,93,123,237,117,
42,191,94,166,239,109,253,92,255,156,57,227,206,51,250,249,209,174,39,31,127,202,117,254,252,57,245,217,214,45,91,93,213,170,215,86,249,91,181,106,227,58,114,248,136,59,239,212,255,155,162,229,203,104,
111,254,220,185,46,77,204,185,235,214,219,192,239,120,242,11,166,109,45,218,229,26,54,116,168,75,219,149,220,245,217,180,105,174,85,171,86,169,31,171,39,221,78,216,12,219,209,7,244,37,152,62,51,79,252,
190,211,100,79,246,60,7,120,14,240,28,16,151,101,34,88,45,91,181,150,133,243,51,55,21,125,109,236,56,121,236,201,167,180,200,209,9,183,226,197,36,246,135,180,121,52,207,105,171,92,48,151,6,59,171,235,
59,190,31,62,124,88,58,94,215,89,150,46,253,197,67,33,35,50,118,221,117,215,201,39,83,254,79,146,189,162,57,103,206,156,209,38,137,183,151,95,126,93,172,202,32,111,243,22,87,202,236,89,51,181,57,89,158,
155,207,245,215,118,244,126,255,195,15,124,170,111,43,68,176,34,121,44,104,219,182,141,84,174,148,177,244,24,67,113,181,235,212,118,87,87,168,96,33,247,54,21,254,218,192,80,93,106,106,170,58,140,85,121,
198,21,72,190,202,32,234,116,252,68,230,70,150,107,181,213,153,24,186,68,218,186,109,171,233,19,206,35,97,199,178,36,64,2,36,64,2,36,224,143,64,92,35,2,122,4,171,66,165,42,174,117,107,215,186,52,161,164,
34,85,121,242,230,243,25,45,66,20,233,137,199,158,244,8,190,236,249,251,111,87,139,22,87,185,180,137,238,62,203,224,243,118,237,174,113,237,223,151,25,33,219,243,247,30,87,179,230,45,93,185,114,103,68,
208,244,31,252,127,99,151,110,46,109,14,152,187,13,216,84,174,66,37,159,117,219,33,130,197,39,9,62,77,242,28,224,57,192,115,128,231,0,207,1,211,207,1,211,27,244,16,116,186,192,130,80,41,86,188,164,171,
116,217,242,89,68,143,81,0,225,111,109,149,159,107,226,235,19,148,0,218,185,99,135,171,70,205,58,126,197,143,91,56,105,34,171,122,205,218,174,159,22,45,210,134,5,183,184,180,200,149,223,50,16,89,221,186,
222,228,58,117,250,180,106,227,205,9,111,100,107,19,79,218,248,158,67,228,79,254,60,7,120,14,240,28,224,57,96,181,115,192,50,67,132,161,6,24,177,114,176,81,195,70,106,133,225,142,29,91,131,46,158,148,
148,79,242,104,43,23,211,211,211,178,221,37,62,71,142,156,114,89,147,43,164,186,182,194,228,235,255,253,79,14,31,218,239,183,13,187,15,17,6,13,143,25,73,128,4,72,128,4,72,128,4,130,34,16,119,129,149,75,
91,21,168,207,163,10,202,98,11,102,58,119,246,172,5,173,162,73,36,64,2,36,64,2,36,64,2,241,34,240,255,216,203,217,237,122,121,79,246,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* JucePdAudioProcessorEditor::soundFxMachine_png = (const char*) resource_JucePdAudioProcessorEditor_soundFxMachine_png;
const int JucePdAudioProcessorEditor::soundFxMachine_pngSize = 29493;
