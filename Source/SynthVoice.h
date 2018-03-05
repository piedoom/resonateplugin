/*
  ==============================================================================

    SynthVoice.h
    Created: 10 Feb 2018 12:53:46pm
    Author:  ulija

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "Maximilian.h"
using namespace std;

class SynthVoice : public SynthesiserVoice
{
	double bpm;
   public:  
	  

	   bool canPlaySound(SynthesiserSound* sound) 
	   {
		   return dynamic_cast<SynthesiserSound*>(sound) != nullptr;
	   }

	   void getParam(float* attack, float* release, float* decay, float* sustain) {

		   env1.setAttack(double(*attack));
		   env1.setDecay(double(*decay));
		   env1.setSustain(double(*sustain));
		   env1.setRelease(double(*release));

	   }
	
	   //=====================================================

	   void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int 
	                  currentPitchWheelPosition) 
	   {
		   env1.trigger = 1;
		   level = velocity;
		   frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		   
		   //cout << midiNoteNumber << endl;

	   }
	   //=====================================================

	   void stopNote(float velocity, bool allowTailOff) 
	   {
		   env1.trigger = 0;
		   allowTailOff = true;

		   if (velocity == 0) 
		   {
			   clearCurrentNote();

		   }

		   //level = 0;
	   }

	   //=====================================================

	   void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	   {
		   
		
		   
		   
		  clo1.setTempo(400);
		  double Tempo = clo1.bpm;
		   

		   for(int sample = 0; sample < numSamples; ++sample)
		   {



			   double theWave = osc1.sinewave(frequency);
			   double theSound = env1.adsr(theWave, env1.trigger) * Tempo;
			  

			   for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) 
			   {
				   outputBuffer.addSample(channel, startSample, theSound);


			   }

			   ++startSample;


		   }

	   }

	   //=====================================================

	   void pitchWheelMoved(int newPitchWheelValue) 
	   {



	   }

	   //=====================================================

	   void controllerMoved(int controllerNumber, int newControllervalue) 
	   {

	   }

	   //=====================================================


private:
	double level;
	double frequency;
	maxiOsc osc1;
	maxiEnv env1;
	maxiClock clo1;
	maxiFilter filter1;


};
