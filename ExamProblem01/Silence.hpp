#pragma once

#include "DigitalSound.hpp"

template <typename TSample, typename TDomain>
class Silence : public DigitalSound<TSample, TDomain>
{
public:
	Silence(size_t _samplesCount);
};

template<typename TSample, typename TDomain>
Silence<TSample, TDomain>::Silence(size_t _samplesCount)
{
	this->samples = new TSample[_samplesCount];

	for (int i = 0; i < _samplesCount; i++)
	{
		this->samples[i] = 0;
	}
}