/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-10 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

#include "juce_StandaloneFilterWindow.h"
#include "JuceHeader.h"
#include "JucePluginCharacteristics.h"

//==============================================================================
/** Somewhere in the codebase of your plugin, you need to implement this function
    and make it create an instance of the filter subclass that you're building.
*/
extern AudioProcessor* JUCE_CALLTYPE createPluginFilter();


//==============================================================================
StandaloneFilterWindow::StandaloneFilterWindow (const String& title,
                                                const Colour& backgroundColour)
    : DocumentWindow (title, backgroundColour,
                      DocumentWindow::minimiseButton
                       | DocumentWindow::closeButton),
      optionsButton ("options")
{
    setTitleBarButtonsRequired (DocumentWindow::minimiseButton | DocumentWindow::closeButton, false);

    Component::addAndMakeVisible (&optionsButton);
    optionsButton.addListener (this);
    optionsButton.setTriggeredOnMouseDown (true);

    JUCE_TRY
    {
        filter = createPluginFilter();

        if (filter != 0)
        {
            filter->setPlayConfigDetails (JucePlugin_MaxNumInputChannels,
                                          JucePlugin_MaxNumOutputChannels,
                                          44100, 512);

            PropertySet* const globalSettings = getGlobalSettings();

            deviceManager = new AudioFilterStreamingDeviceManager();
            deviceManager->setFilter (filter);

            XmlElement* savedState = 0;

            if (globalSettings != 0)
                savedState = globalSettings->getXmlValue ("audioSetup");

            deviceManager->initialise (filter->getNumInputChannels(),
                                       filter->getNumOutputChannels(),
                                       savedState,
                                       true);

            delete savedState;

            if (globalSettings != 0)
            {
                MemoryBlock data;

                if (data.fromBase64Encoding (globalSettings->getValue ("filterState"))
                     && data.getSize() > 0)
                {
                    filter->setStateInformation (data.getData(), data.getSize());
                }
            }

            setContentComponent (filter->createEditorIfNeeded(), true, true);

            const int x = globalSettings->getIntValue ("windowX", -100);
            const int y = globalSettings->getIntValue ("windowY", -100);

            if (x != -100 && y != -100)
                setBoundsConstrained (Rectangle<int> (x, y, getWidth(), getHeight()));
            else
                centreWithSize (getWidth(), getHeight());
        }
    }
    JUCE_CATCH_ALL

    if (deviceManager == 0)
    {
        jassertfalse    // Your filter didn't create correctly! In a standalone app that's not too great.
        JUCEApplication::quit();
    }
}

StandaloneFilterWindow::~StandaloneFilterWindow()
{
    PropertySet* const globalSettings = getGlobalSettings();

    globalSettings->setValue ("windowX", getX());
    globalSettings->setValue ("windowY", getY());

    if (globalSettings != 0 && deviceManager != 0)
    {
        XmlElement* const xml = deviceManager->createStateXml();
        globalSettings->setValue ("audioSetup", xml);
        delete xml;
    }

    deviceManager = 0;

    if (globalSettings != 0 && filter != 0)
    {
        MemoryBlock data;
        filter->getStateInformation (data);

        globalSettings->setValue ("filterState", data.toBase64Encoding());
    }

    deleteFilter();
}

//==============================================================================
void StandaloneFilterWindow::deleteFilter()
{
    if (deviceManager != 0)
        deviceManager->setFilter (0);

    if (filter != 0 && getContentComponent() != 0)
    {
        filter->editorBeingDeleted (dynamic_cast <AudioProcessorEditor*> (getContentComponent()));
        setContentComponent (0, true);
    }

    filter = 0;
}

void StandaloneFilterWindow::resetFilter()
{
    deleteFilter();

    filter = createPluginFilter();

    if (filter != 0)
    {
        if (deviceManager != 0)
            deviceManager->setFilter (filter);

        setContentComponent (filter->createEditorIfNeeded(), true, true);
    }

    PropertySet* const globalSettings = getGlobalSettings();

    if (globalSettings != 0)
        globalSettings->removeValue ("filterState");
}

//==============================================================================
void StandaloneFilterWindow::saveState()
{
    PropertySet* const globalSettings = getGlobalSettings();

    FileChooser fc (TRANS("Save current state"),
                    globalSettings != 0 ? File (globalSettings->getValue ("lastStateFile"))
                                        : File::nonexistent);

    if (fc.browseForFileToSave (true))
    {
        MemoryBlock data;
        filter->getStateInformation (data);

        if (! fc.getResult().replaceWithData (data.getData(), data.getSize()))
        {
            AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                         TRANS("Error whilst saving"),
                                         TRANS("Couldn't write to the specified file!"));
        }
    }
}

void StandaloneFilterWindow::loadState()
{
    PropertySet* const globalSettings = getGlobalSettings();

    FileChooser fc (TRANS("Load a saved state"),
                    globalSettings != 0 ? File (globalSettings->getValue ("lastStateFile"))
                                        : File::nonexistent);

    if (fc.browseForFileToOpen())
    {
        MemoryBlock data;

        if (fc.getResult().loadFileAsData (data))
        {
            filter->setStateInformation (data.getData(), data.getSize());
        }
        else
        {
            AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                         TRANS("Error whilst loading"),
                                         TRANS("Couldn't read from the specified file!"));
        }
    }
}

//==============================================================================
PropertySet* StandaloneFilterWindow::getGlobalSettings()
{
    /* If you want this class to store the plugin's settings, you can set up an
       ApplicationProperties object and use this method as it is, or override this
       method to return your own custom PropertySet.

       If using this method without changing it, you'll probably need to call
       ApplicationProperties::setStorageParameters() in your plugin's constructor to
       tell it where to save the file.
    */
    return ApplicationProperties::getInstance()->getUserSettings();
}

void StandaloneFilterWindow::showAudioSettingsDialog()
{
    AudioDeviceSelectorComponent selectorComp (*deviceManager,
                                               filter->getNumInputChannels(),
                                               filter->getNumInputChannels(),
                                               filter->getNumOutputChannels(),
                                               filter->getNumOutputChannels(),
                                               true, false, true, false);

    selectorComp.setSize (500, 450);

    DialogWindow::showModalDialog (TRANS("Audio Settings"), &selectorComp, this, Colours::lightgrey, true, false, false);
}

//==============================================================================
void StandaloneFilterWindow::closeButtonPressed()
{
    JUCEApplication::quit();
}

void StandaloneFilterWindow::resized()
{
    DocumentWindow::resized();

    optionsButton.setBounds (8, 6, 60, getTitleBarHeight() - 8);
}

void StandaloneFilterWindow::buttonClicked (Button*)
{
    if (filter == 0)
        return;

    PopupMenu m;
    m.addItem (1, TRANS("Audio Settings..."));
    m.addSeparator();
    m.addItem (2, TRANS("Save current state..."));
    m.addItem (3, TRANS("Load a saved state..."));
    m.addSeparator();
    m.addItem (4, TRANS("Reset to default state"));

    switch (m.showAt (&optionsButton))
    {
    case 1:
        showAudioSettingsDialog();
        break;

    case 2:
        saveState();
        break;

    case 3:
        loadState();
        break;

    case 4:
        resetFilter();
        break;

    default:
        break;
    }
}

class MyJUCEApp  : public JUCEApplication
{
public:
    MyJUCEApp()
    {
    }
    
    ~MyJUCEApp()
    {
    }
    
    void initialise (const String& commandLine)
    {
        ApplicationProperties::getInstance()->setStorageParameters(JucePlugin_Name, ".prf", JucePlugin_Manufacturer, 1000, PropertiesFile::storeAsXML);
        myMainWindow = new StandaloneFilterWindow(JucePlugin_Name, Colour(0,0,0));
        myMainWindow->setVisible (true);
    }
    
    void shutdown()
    {
        myMainWindow = 0;
    }
    
    const String getApplicationName()
    {
        return JucePlugin_Name;
    }
    
    const String getApplicationVersion()
    {
        return "1.0";
    }
    
private:
    ScopedPointer <StandaloneFilterWindow> myMainWindow;
};

START_JUCE_APPLICATION(MyJUCEApp)