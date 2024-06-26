#pragma once

#include <iostream>
#include "Gift.h"

class BloodGift : public Gift
{
public:
	BloodGift(int _value);

	void interactWithPlayer(Player& p) override;
	void draw() const;
};

void BloodGift::draw() const
{
	std::cout << "I am a blood gift with value " << value << ".\n";
}

BloodGift::BloodGift(int _value) : Gift(_value) {}

void BloodGift::interactWithPlayer(Player& p)
{
	p.increaseBlood(value);
}
