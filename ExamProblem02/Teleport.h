#pragma once

#include <iostream>
#include "Object.h"
#include "Player.h"

class Teleport : virtual public Object
{
	int uniqueNum;
	int index; // номер на клетката, в която се намира телепортът

public:
	Teleport(int _uniqueNum, int _index);

    Teleport* clone() const override;
	void interactWithPlayer(Player& p) override;
	void draw() const override;
    bool isAlive() const override;
};

void Teleport::draw() const
{
    std::cout << "t(" << uniqueNum << ")";
}

Teleport::Teleport(int _uniqueNum, int _index) : uniqueNum(_uniqueNum), index(_index)
{
}

void Teleport::interactWithPlayer(Player& p)
{
    srand((unsigned int)time(NULL));

    int newRandIndex = rand() % 10;
    while (newRandIndex == index)
    {
        newRandIndex = rand() % 10;
    }

	p.setIndex(newRandIndex);
}

Teleport *Teleport::clone() const
{
    return new Teleport(*this);
}

bool Teleport::isAlive() const
{
    return true;
}
