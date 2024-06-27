#pragma once

#include "BloodGift.h"
#include "Teleport.h"

class CombinedObject : public Gift, public Teleport
{
public:
	CombinedObject(int _value, int _uniqueNumber, int _index);

	void draw() const override;

	void interactWithPlayer(Player& p) override;

    CombinedObject* clone() const override;

};

void CombinedObject::draw() const
{
	std::cout << "I am a combined object:\n";
	Gift::draw();
	Teleport::draw();
}

void CombinedObject::interactWithPlayer(Player& p)
{
	Gift::interactWithPlayer(p);
	Teleport::interactWithPlayer(p);
}

CombinedObject::CombinedObject(int _value, int _uniqueNumber, int _index) : Gift(_value), Teleport(_uniqueNumber, _index)
{

}

CombinedObject *CombinedObject::clone() const
{
    return new CombinedObject(*this);
}
