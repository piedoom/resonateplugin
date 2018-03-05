/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class Nmp_pluginAudioProcessorEditor  : public AudioProcessorEditor,
	public Slider::Listener
{
public:
    Nmp_pluginAudioProcessorEditor (Nmp_pluginAudioProcessor&);
    ~Nmp_pluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void sliderValueChanged(Slider* slider)  override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Nmp_pluginAudioProcessor& processor;
	
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackVal;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decayVal;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sustainVal;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseVal;


	Slider attackSlider;
	Slider decaySlider;
	Slider sustainSlider;
	Slider releaseSlider;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Nmp_pluginAudioProcessorEditor)
};
