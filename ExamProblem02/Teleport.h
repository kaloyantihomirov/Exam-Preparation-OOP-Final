#pragma once

#include "Object.h"
#include "Player.h"

class Teleport : public Object
{
	int uniqueNum;
	int index; // ����� �� ��������, � ����� �� ������ ����������

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