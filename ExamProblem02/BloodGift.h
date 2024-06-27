#pragma once

#include <iostream>
#include "Gift.h"

class BloodGift : public Gift
{
public:
	BloodGift(int _value);

	void interactWithPlayer(Player& p) override;
	void draw() const;
    BloodGift* clone() const override;
    bool isAlive() const override;
};

void BloodGift::draw() const
{
    std::cout << "bg(" << value << ")";
}

BloodGift::BloodGift(int _value) : Gift(_value) {}

void BloodGift::interactWithPlayer(Player& p)
{
    int playerBlood = p.getBlood();

    p.setBlood(p.getBlood() + value);
    value -= p.getBlood() - playerBlood;

	//p.increaseBlood(value);
}

BloodGift *BloodGift::clone() const
{
    return new BloodGift(*this);
}

bool BloodGift::isAlive() const
{
    return value > 0;
}
