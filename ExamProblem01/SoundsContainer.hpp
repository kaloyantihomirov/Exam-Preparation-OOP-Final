#pragma once

#include "DigitalSound.hpp"

template <typename TSample, typename TDomain>
class SoundsContainer
{
	static const size_t initialCap = 8;

	DigitalSound<TSample, TDomain>** sounds = nullptr;
	size_t size;
	size_t cap;

	void resize(size_t newCap);

	void free();
	void copyFrom(const SoundsContainer& other);

public:
	SoundsContainer();
	SoundsContainer(const SoundsContainer& other);
	SoundsContainer(SoundsContainer&& other);

	SoundsContainer& operator=(const SoundsContainer& other);
	SoundsContainer& operator=(SoundsContainer&& other);

	void addSound(DigitalSound<TSample, TDomain>* sound);
	
	DigitalSound<TSample, TDomain>& operator[](unsigned inx);

	~SoundsContainer();
};

template <typename TSample, typename TDomain>
void SoundsContainer<TSample, TDomain>::copyFrom(const SoundsContainer& other)
{
	sounds = new DigitalSound<TSample, TDomain>* [other.cap];
	cap = other.cap;
	size = other.size;

	for (int i = 0; i < size; i++)
	{
		sounds[i] = other.sounds[i]->clone();
	}

}

template <typename TSample, typename TDomain>
SoundsContainer<TSample, TDomain>::SoundsContainer(const SoundsContainer& other)
{
	copyFrom(other);
}

template <typename TSample, typename TDomain>
SoundsContainer<TSample, TDomain>& SoundsContainer<TSample, TDomain>::operator=(const SoundsContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}




template <typename TSample, typename TDomain>
DigitalSound<TSample, TDomain>& SoundsContainer<TSample, TDomain>::operator[](unsigned inx)
{
	if (ind >= size)
	{
		throw std::invalid_argument("inv indx");
	}

	return *sounds[inx];
}

template<typename TSample, typename TDomain>
void SoundsContainer<TSample, TDomain>::free()
{
	for (int i = 0; i < size; i++)
	{
		delete sounds[i];
	}

	delete[] sounds;
	sounds = nullptr;
	size = 0;
	cap = 0;
}

template<typename TSample, typename TDomain>
inline SoundsContainer<TSample, TDomain>::SoundsContainer()
{
	sounds = new DigitalSound<TSample, TDomain>* [initialCap];
	size = 0;
	cap = initialCap;
}

template<typename TSample, typename TDomain>
inline void SoundsContainer<TSample, TDomain>::addSound(DigitalSound<TSample, TDomain>* sound)
{
	//OWN THE SOUND
	if (size + 1 == cap)
	{
		resize(cap * 2);
	}

	sounds[size++] = sound->clone();
}