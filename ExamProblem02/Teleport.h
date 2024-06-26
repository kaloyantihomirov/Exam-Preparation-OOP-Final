#pragma once

#include "Object.h"
#include "Player.h"

class Teleport : public Object
{
	int uniqueNum;
	int index; // номер на клетката, в която се намира телепортът

public:
	Teleport(int _uniqueNum, int _index);

	void interactWithPlayer(Player& p) override;
	void draw() const override;
};

void Teleport::draw()
{

}

Teleport::Teleport(int _uniqueNum, int _index) : uniqueNum(_uniqueNum), index(_index)
{
}

void Teleport::interactWithPlayer(Player& p)
{
	int newRandIndex = rand() % 100;
	p.setIndex(newRandIndex);
}