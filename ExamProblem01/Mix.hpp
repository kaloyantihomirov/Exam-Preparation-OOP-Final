#pragma once

#include "cassert"

#include "DigitalSound.hpp"

template <typename TSample, typename TDomain>
class Mix : public DigitalSound<TSample, TDomain>
{
	const TSample& getSamplesSumAtIndex(
		const DigitalSound<TSample, TDomain>* const* sounds,
		size_t soundsCount,
		unsigned ind) const;

	unsigned maxSamplesSize(
		const DigitalSound<TSample, TDomain>* const* sounds,
		size_t soundsCount) const;

public:
	Mix(const DigitalSound<TSample, TDomain>* const* sounds,
		size_t soundsCount);

	Mix<TSample, TDomain>* clone() const override;
};

template<typename TSample, typename TDomain>
inline Mix<TSample, TDomain>* Mix<TSample, TDomain>::clone() const
{
	return new Mix<TSample, TDomain>(*this);
}

template<typename TSample, typename TDomain>
unsigned Mix<TSample, TDomain>::maxSamplesSize(
	const DigitalSound<TSample, TDomain>* const* sounds,
	size_t soundsCount) const
{
	unsigned maxSamplesSize = sounds[0]->getSamplesCount();

	for (int i = 1; i < soundsCount; i++)
	{
		size_t currentSize = sounds[i]->getSamplesCount();

		if (currentSize > maxSamplesSize)
		{
			maxSamplesSize = currentSize;
		}
	}

	return maxSamplesSize;
}

template <typename TSample, typename TDomain>
Mix<TSample, TDomain>::Mix(const DigitalSound<TSample, TDomain>* const* sounds,
	size_t soundsCount)
{
	assert(soundsCount > 0);

	this->samplesCount = maxSamplesSize(sounds, soundsCount);
	this->samples = new TSample[this->samplesCount];

	for (int i = 0; i < this->samplesCount; i++)
	{
		this->setSampleAtIndex(
			getSamplesSumAtIndex(sounds, soundsCount, i) / soundsCount,
			i);
	}
}

template <typename TSample, typename TDomain>
const TSample& Mix<TSample, TDomain>::getSamplesSumAtIndex(
	const DigitalSound<TSample, TDomain>* const* sounds,
	size_t soundsCount,
	unsigned ind) const
{
	TSample sum = TSample();

	for (int i = 0; i < soundsCount; i++)
	{
		if (sounds[i]->getSamplesCount() > ind)
		{
			sum += sounds[i]->getSamples()[ind];
		}
	}

	return sum;
}