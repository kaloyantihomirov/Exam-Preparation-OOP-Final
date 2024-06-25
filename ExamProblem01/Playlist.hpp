#pragma once

#include <fstream>
#include <sstream>

#include "DigitalSound.hpp"
#include "SoundFromFile.hpp"
#include "Effect.hpp"
#include "TransformByCoefficient.hpp"
#include "SoundsContainer.hpp"
#include "Silence.hpp"

static unsigned countChars(char charToLook, std::istream& in)
{
	size_t pos = in.tellg();

	in.seekg(0, std::ios::beg);

	unsigned occurrences = 0;
	char ch;
	while (in.get(ch))
	{
		if (ch == charToLook)
		{
			occurrences++;
		}
	}

	in.seekg(pos);
	in.clear();
	return occurrences;
}

class Playlist
{
	SoundsContainer<float, int> sc;

public:
	Playlist(const char* fileName);

	const DigitalSound<float, int>& operator[](unsigned ind) const;

	DigitalSound<float, int>& operator[](unsigned inx);
};

inline Playlist::Playlist(const char* fileName)
{
	std::ifstream in(fileName);

	if (!in.is_open())
	{
		throw std::invalid_argument("Cannot open the file with the provided name");
	}

	char line[1000];
	while (in.getline(line, 1000))
	{
		std::stringstream ss(line);
		unsigned intervalsCount = countChars(' ', ss);

		if (intervalsCount == 0)
		{
			size_t samplesCount;
			in >> samplesCount;

			Silence<float, int> silence(samplesCount);

			sc.addSound(&silence);
		}
		else if (intervalsCount == 1)
		{
			char fileName[1000];
			ss.getline(fileName, 1000, ' ');

			float coeff;
			ss >> coeff;

			SoundFromFile<float, int> sff(fileName);

			TransformByCoefficient<float> tbc(coeff);

			Effect<float, int> eff(&sff,tbc);

			sc.addSound(&eff);

			//add effect to sounds
		}
		else if (intervalsCount == 2)
		{

		}
	}
}