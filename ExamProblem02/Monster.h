#pragma once

#include "Artifact.h"

class Monster : public Artifact
{
	char* name;
	int blood, power;

public:
	Monster(const char* _name, int _blood, int _power);

	const char* getName() const;
	void setName(const char* _name);

	void setBlood(int newBlood);
	int getBlood() const;

	int getPower() const;
	void setPower(int newPower);

	void draw() const override;
	void interactWithPlayer(Player& player) override; 

	~Monster();
};

void Monster::interactWithPlayer(Player& player)
{
	//При взаимодействие с чудовище кръвта на играча се намалява със силата на чудовището, както и кръвта на чудовището също се намалява със силата на играча. Ако кръвта на чудовището се изчерпи, то се премахва от играта. Ако кръвта на играча се изчерпи – той губи играта.

	player.setBlood(player.getBlood() - power);
	blood -= player.getPower();


}

void Monster::setBlood(int newBlood)
{
	if (newBlood < 0)
	{
		blood = 0;
		return;
	}

	blood = newBlood;
}

void Monster::setName(const char* _name)
{
	if (!_name)
		throw std::invalid_argument("inv name");

	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

const char* Monster::getName() const
{
	return name;
}

int Monster::getBlood() const
{
	return blood;
}

int Monster::getPower() const
{
	return power;
}

void Monster::setPower(int newPower)
{
	power = newPower;
}

Monster::Monster(const char* _name, int _power, int _blood) 
{
	setName(_name);
	setPower(_power);
	setBlood(_blood);
}

Monster::~Monster()
{
	delete[] name;
	name = nullptr;
}