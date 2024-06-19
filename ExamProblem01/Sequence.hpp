#pragma once

#include "cassert"

#include "DigitalSound.hpp"

template <typename TSample, typename TDomain>
class Sequence : public DigitalSound<TSample, TDomain>
{
public:
	Sequence(const DigitalSound<TSample, TDomain>* const * sounds, 
		size_t soundsCount);
};

template <typename TSample, typename TDomain>
Sequence<TSample, TDomain>::Sequence(const DigitalSound<TSample, TDomain>* const* sounds,
	size_t soundsCount)
{
	assert(soundsCount > 0);

	TSample sequenceSamplesCount = TSample();

	for (int i = 0; i < soundsCount; i++)
	{
		sequenceSamplesCount += sounds[i]->getSamplesCount();
	}

	this->samples = new TSample[sequenceSamplesCount];

	for (int i = 0; i < soundsCount; i++)
	{
		for (int j = 0; j < sounds[i]->getSamplesCount(); j++)
		{
			this->setSampleAtIndex(sounds[i]->getSamples()[j], this->samplesCount++);
		}
	}
}