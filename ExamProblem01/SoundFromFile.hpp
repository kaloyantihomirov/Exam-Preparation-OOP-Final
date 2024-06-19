#pragma once

#include "fstream"

#include "DigitalSound.hpp"

static size_t getFileSize(std::ifstream& in)
{
	if (!in.is_open())
	{
		return 0;
	}

	size_t currentPos = in.tellg();

	in.seekg(0, std::ios::end);
	size_t length = in.tellg();

	in.seekg(currentPos);
	return length;
}

template <typename TSample, typename TDomain>
class SoundFromFile : public DigitalSound<TSample, TDomain>
{

public:
	SoundFromFile(const char* fileName);
};

template <typename TSample, typename TDomain>
SoundFromFile<TSample, TDomain>::SoundFromFile(const char * fileName)
{
	std::ifstream in(fileName, std::ios::binary);

	if (!in.is_open())
	{
		return;
	}

	size_t fileSize = getFileSize(in);
	size_t samplesCount = fileSize / sizeof(TSample);

	this->samples = new TSample[samplesCount];

	TSample sound;
	while (in.read((char*)&sound, sizeof(sound)))
	{
		this->setSampleAtIndex(sound, this->samplesCount++);
		//this->samples[this->samplesCount++] = sound;
	}
}
