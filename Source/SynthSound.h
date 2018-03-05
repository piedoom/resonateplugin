/*
  ==============================================================================

    SynthSound.h
    Created: 10 Feb 2018 12:53:29pm
    Author:  ulija

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound 
{
   public:
	bool appliesToNote(int /*midiNoteNumber*/)
		{
			return true;
		}
	bool appliesToChannel(int /*midiChannel*/ ) 
	{
		return true;
	}



};
