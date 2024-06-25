#pragma once

#include "DigitalSound.hpp"

template <typename TSample, typename TDomain>
class Effect : public DigitalSound<TSample, TDomain>
{
public:
	template <typename TTransform>
	Effect(DigitalSound<TSample, TDomain>* sound,
		TTransform transformFunction);

	Effect<TSample, TDomain>* clone() const override;
};

template<typename TSample, typename TDomain>
inline Effect<TSample, TDomain>* Effect<TSample, TDomain>::clone() const
{
	return new Effect<TSample, TDomain>(*this);
}

template <typename TSample, typename TDomain>
template <typename TTransform>
Effect<TSample, TDomain>::Effect(DigitalSound<TSample, TDomain>* sound,
	TTransform transformFunction)
{
	this->samples = new TSample[this->samplesCount];

	for (int i = 0; i < sound->getSamplesCount(); i++)
	{
		TSample newSample = transformFunction(sound->getSamples()[i], i);
		this->setSampleAtIndex(newSample, this->samplesCount++);
		//this->samples[this->samplesCount++] = newSample;
	}
}