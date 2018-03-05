/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Nmp_pluginAudioProcessor::Nmp_pluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	),attackTime(0.1f),tree(*this, nullptr)
#endif
{
	NormalisableRange<float> attackParam(0.1f,5000.0f);
	NormalisableRange<float> decayParam(1.0f, 2000.0f);
	NormalisableRange<float> sustainParam(0.0f, 1.0f);
	NormalisableRange<float> releaseParam(0.1f, 5000.0f);
	
	

	tree.createAndAddParameter("attack","Attack","Attack",attackParam,0.1f,nullptr,nullptr);
	tree.createAndAddParameter("decay", "Decay", "Decay", decayParam, 1.0f, nullptr, nullptr);
	tree.createAndAddParameter("sustain", "Sustain", "Sustain", sustainParam, 0.0f, nullptr, nullptr);
    tree.createAndAddParameter("release", "Release", "Release", releaseParam, 0.1f, nullptr, nullptr);
	

	mySynth.clearVoices();

	for (int i = 0; i < 10; i++) 
	{
		mySynth.addVoice(new SynthVoice());

	}

	mySynth.clearSounds();
	mySynth.addSound(new SynthSound());




}

Nmp_pluginAudioProcessor::~Nmp_pluginAudioProcessor()
{
}

//==============================================================================
const String Nmp_pluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Nmp_pluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Nmp_pluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Nmp_pluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Nmp_pluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Nmp_pluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Nmp_pluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Nmp_pluginAudioProcessor::setCurrentProgram (int index)
{
}

const String Nmp_pluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void Nmp_pluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Nmp_pluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

	ignoreUnused(samplesPerBlock);
	lastSampleRate = sampleRate;
	mySynth.setCurrentPlaybackSampleRate(lastSampleRate);


}

void Nmp_pluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Nmp_pluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Nmp_pluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	//clearBuffer();

	for (int i = 0;i < mySynth.getNumVoices(); i++) 
	{
		if (myVoice  = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))) 
		{
			myVoice->getParam(tree.getRawParameterValue("attack"), tree.getRawParameterValue("release"),
				tree.getRawParameterValue("decay"), tree.getRawParameterValue("sustain"));

		}

	}

	buffer.clear();

	mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());




}

//==============================================================================
bool Nmp_pluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Nmp_pluginAudioProcessor::createEditor()
{
    return new Nmp_pluginAudioProcessorEditor (*this);
}

//==============================================================================
void Nmp_pluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Nmp_pluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Nmp_pluginAudioProcessor();
}
