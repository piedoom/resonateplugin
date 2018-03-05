/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Nmp_pluginAudioProcessorEditor::Nmp_pluginAudioProcessorEditor (Nmp_pluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	attackSlider.setRange(0.1,5000.0f);
	attackSlider.setValue(0.1f);
	attackSlider.setTextBoxStyle(Slider::TextBoxBelow,true,20.0,10.0);
	attackSlider.addListener(this);
	addAndMakeVisible(&attackSlider);

	decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	decaySlider.setRange(1.0, 2000.0f);
	decaySlider.setValue(1.0f);
	decaySlider.setTextBoxStyle(Slider::TextBoxBelow,true,20.0,10.0);
	decaySlider.addListener(this);
	addAndMakeVisible(&decaySlider);

	sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	sustainSlider.setRange(0.0, 1.0f);
	sustainSlider.setValue(0.8f);
	sustainSlider.setTextBoxStyle(Slider::TextBoxBelow,true,20.0,10.0);
	sustainSlider.addListener(this);
	addAndMakeVisible(&sustainSlider);

	releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	releaseSlider.setRange(0.1, 5000.0f);
	releaseSlider.setValue(0.1f);
	releaseSlider.setTextBoxStyle(Slider::TextBoxBelow,true,20.0,10.0);
	releaseSlider.addListener(this);
	addAndMakeVisible(&releaseSlider);


	

	attackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "atttack", attackSlider);
	decayVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay", decaySlider);
	sustainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain", sustainSlider);
	releaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);
	
}

Nmp_pluginAudioProcessorEditor::~Nmp_pluginAudioProcessorEditor()
{
}

//==============================================================================
void Nmp_pluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
	//g.drawFittedText(bpm, getLocalBounds(), Justification::centred, 1);
}

void Nmp_pluginAudioProcessorEditor::resized()
{
	attackSlider.setBounds(10,10,40,100);
	decaySlider.setBounds(60, 10, 40, 100);
	sustainSlider.setBounds(110, 10, 40, 100);
	releaseSlider.setBounds(160, 10, 40, 100);
	
}

void Nmp_pluginAudioProcessorEditor::sliderValueChanged(Slider* slider) {

	if (slider == &attackSlider) {
		processor.attackTime = attackSlider.getValue();

	}
	if (slider == &decaySlider) {
		processor.decayTime = decaySlider.getValue();

	}
	if (slider == &sustainSlider) {
		processor.sustainTime = sustainSlider.getValue();

	}

	if (slider == &releaseSlider) {
		processor.releaseTime = releaseSlider.getValue();

	}

	

	

}