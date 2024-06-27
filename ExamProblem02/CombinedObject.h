#pragma once

#include "BloodGift.h"
#include "Teleport.h"

class CombinedObject : public BloodGift, public Teleport
{
public:
	CombinedObject(int _value, int _uniqueNumber, int _index);

	void draw() const override;

	void interactWithPlayer(Player& p) override;

    CombinedObject* clone() const override;

    bool isAlive() const override;
};

void CombinedObject::draw() const
{
    std::cout << "co[v:" << value << ",i:" << getIndex() << "]";
}

void CombinedObject::interactWithPlayer(Player& p)
{
    BloodGift::interactWithPlayer(p);
	Teleport::interactWithPlayer(p);
}

CombinedObject::CombinedObject(int _value, int _uniqueNumber, int _index) : BloodGift(_value), Teleport(_uniqueNumber, _index)
{
}

CombinedObject *CombinedObject::clone() const
{
    return new CombinedObject(*this);
}

bool CombinedObject::isAlive() const
{
    return Teleport::isAlive();
}
