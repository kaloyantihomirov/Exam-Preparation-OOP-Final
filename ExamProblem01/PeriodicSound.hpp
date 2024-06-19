#pragma once

#include "fstream"

#include "DigitalSound.hpp"

template <typename TSample, typename TDomain>
class PeriodicSound : public DigitalSound<TSample, TDomain>
{
public:
	PeriodicSound(TSample* arr, size_t arrSize, size_t repeatTimes);
};

template <typename TSample, typename TDomain>
PeriodicSound<TSample, TDomain>::PeriodicSound(TSample* arr,
	size_t arrSize, 
	size_t repeatTimes)
{
	//10 15 13 5
	this->samples = new TSample[arrSize * repeatTimes];
	std::cout << arrSize * repeatTimes << std::endl;

	for (size_t times = 0; times < repeatTimes; times++)
	{
		for (size_t i = 0; i < arrSize; i++)
		{
			this->setSampleAtIndex(arr[i], this->samplesCount++);
		}
	}
}
