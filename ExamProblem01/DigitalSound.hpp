#pragma once

#include "iostream"
#include "cassert"
#include "stdexcept"

template <typename TSample, typename TDomain>
class DigitalSound
{
protected:
	TSample* samples;
	size_t samplesCount;
	TDomain M;

	void setSampleAtIndex(const TSample& sample, unsigned ind);

public:
	DigitalSound(const TDomain& _M = 1);

	size_t getSamplesCount() const;
	const TSample* getSamples() const;

	void printForDebug() const;

	virtual void save(const char * fileName);

	virtual const TSample& operator[](unsigned ind) const;

	virtual ~DigitalSound();
};

template<typename TSample, typename TDomain>
void DigitalSound<TSample, TDomain>::printForDebug() const
{
	std::cout << "Samples count: " << this->samplesCount << std::endl;

	for (int i = 0; i < samplesCount; i++)
	{
		std::cout << "sample count[" << i << "]=" << this->samples[i] << std::endl;
	}
}

template<typename TSample, typename TDomain>
void DigitalSound<TSample, TDomain>::save(const char* fileName)
{
	std::ofstream out(fileName, std::ios::binary);

	if (!out.is_open())
	{
		return;
	}

	for (int i = 0; i < getSamplesCount(); i++)
	{
		out.write((const char*)&this->samples[i], sizeof(this->samples[i]));
	}

	out.close();
}

//clipping
template <typename TSample, typename TDomain>
void DigitalSound<TSample, TDomain>::setSampleAtIndex(const TSample& sample,
	unsigned ind)
{
	assert(ind < samplesCount);

	if (sample >= -M && sample <= M)
	{
		this->samples[ind] = sample;
	}
	else if (sample <= 0)
	{
		this->samples[ind] = -M;
	}
	else
	{
		this->samples[ind] = M;
	}
}

template <typename TSample, typename TDomain>
const TSample* DigitalSound<TSample, TDomain>::getSamples() const
{
	return samples;
}

template <typename TSample, typename TDomain>
size_t DigitalSound<TSample, TDomain>::getSamplesCount() const
{
	return samplesCount;
}

template <typename TSample, typename TDomain>
DigitalSound<TSample, TDomain>::DigitalSound(const TDomain& _M)
{
	samples = nullptr;
	samplesCount = 0;
	M = _M;
}

template <typename TSample, typename TDomain>
DigitalSound<TSample, TDomain>::~DigitalSound()
{
	delete[] samples;
	samplesCount = 0;
}

template <typename TSample, typename TDomain>
const TSample& DigitalSound<TSample, TDomain>::operator[](unsigned inx) const
{
	if (inx >= samplesCount)
	{
		throw std::invalid_argument("Index out of bounds!");
	}

	return samples[inx];
}