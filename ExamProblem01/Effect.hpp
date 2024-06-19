#pragma once

#include "DigitalSound.hpp"

template <typename TSample, typename TDomain>
class Effect : public DigitalSound<TSample, TDomain>
{
public:
	Effect(DigitalSound<TSample, TDomain>* sound,
		TSample(*transform)(const TSample& sample, unsigned inx));
};

template <typename TSample, typename TDomain>
Effect<TSample, TDomain>::Effect(DigitalSound<TSample, TDomain>* sound,
	TSample(*transform)(const TSample& sample, unsigned inx))
{
	this->samples = new TSample[this->samplesCount];

	for (int i = 0; i < sound->getSamplesCount(); i++)
	{
		TSample newSample = transform(sound->getSamples()[i], i);
		this->setSampleAtIndex(newSample, this->samplesCount++);
		//this->samples[this->samplesCount++] = newSample;
	}
}