/*
 *  GhostFactLookFeel.cpp
 *  SoundFXMachine
 *
 *  Created by James Russell McClellan on 4/24/11.
 *
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
 
 
 */

#include "GhostFactLookFeel.h"

float
GetAlphaForState(bool isButtonDown, bool isMouseOverButton)
{
    return (isButtonDown ? 1.0 : (isMouseOverButton ? .85 : .7));
}

void GhostFactLookAndFeel::drawButtonBackground (Graphics& g,
                           Button& button,
                           const Colour& backgroundColour,
                           bool isMouseOverButton,
                           bool isButtonDown)
{
    const int width = button.getWidth();
    const int height = button.getHeight();

    const float indent = 2.0f;
    const int cornerSize = jmin (roundToInt (width * 0.2f),
                                 roundToInt (height * 0.2f));
    
    Path p;
    p.addRoundedRectangle (indent, indent,
                           width - indent * 2.0f,
                           height - indent * 2.0f,
                           (float) cornerSize);
    Colour bc (backgroundColour.withAlpha((float)GetAlphaForState(isButtonDown, isMouseOverButton)));
    g.setColour (bc);
    g.fillPath (p);
    g.setColour((bc.withAlpha((float)1.0)));
    g.strokePath (p, PathStrokeType ((isMouseOverButton) ? 2.0f : 1.4f));
}

void GhostFactLookAndFeel::drawLinearSlider (Graphics& g,
                       int x, int y,
                       int width, int height,
                       float sliderPos,
                       float minSliderPos,
                       float maxSliderPos,
                       const Slider::SliderStyle style,
                       Slider& slider)
{
    const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
    
    float indent = 2.0f;
    const int cornerSize = jmin (roundToInt (width * 0.2f),
                                 roundToInt (height * 0.2f));
    
    const float sliderRadius = (float) (getSliderThumbRadius (slider));
    
    float iy, ix, iw, ih = 0;
    if (slider.isHorizontal())
    {
        ix = x - sliderRadius * .5;
        iw = width + sliderRadius;
        iy = y;
        ih = height;
    }
    else 
    {
        ix = x;
        iw = width;
        iy = y - sliderRadius * .5;
        ih = height + sliderRadius;
    }

    Path p;
    p.addRoundedRectangle (ix + indent, iy + indent,
                           iw - indent * 2.0f,
                           ih - indent * 2.0f,
                           (float) cornerSize);
    g.setColour(slider.findColour (Slider::trackColourId).withAlpha(GetAlphaForState(isMouseOver,isMouseOver)));
    g.fillPath(p);
    
    g.setColour(slider.findColour(Slider::thumbColourId).withAlpha(GetAlphaForState(isMouseOver, isMouseOver)));
    Path thumb;
    
    indent = 4.0f;
    if (slider.isHorizontal())
    {
        thumb.addRoundedRectangle(sliderPos - sliderRadius / 2+ indent, y + indent,
                              sliderRadius - indent*2,
                              sliderRadius - indent*2,
                              (float) cornerSize);
    }
    else
    {
        thumb.addRoundedRectangle(x + indent, sliderPos - sliderRadius / 2 + indent,
                                  sliderRadius - indent*2,
                                  sliderRadius - indent*2,
                                  (float) cornerSize);       
    }
    
    g.fillPath(thumb);
}

int GhostFactLookAndFeel::getSliderThumbRadius (Slider& slider)
{
    const int width = slider.getWidth();
    const int height = slider.getHeight();
    return jmin(width,height);
}
