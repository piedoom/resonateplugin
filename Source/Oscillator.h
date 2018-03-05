/*
  ==============================================================================

    Oscillator.h
    Created: 21 Feb 2018 11:17:33am
    Author:  ulija

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Oscillator    : public Component
{
public:
    Oscillator();
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
