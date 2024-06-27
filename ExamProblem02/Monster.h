#pragma once

#include <cstring>
#include <iostream>
#include "Artifact.h"

class Monster : public Artifact
{
	char* name;
	int blood, power;

    void copyFrom(const Monster& other);

public:
	Monster(const char* _name, int _blood, int _power);
    Monster(const Monster& other);

    Monster& operator=(const Monster& other) = delete;

	const char* getName() const;
	void setName(const char* _name);

    int getBlood() const;
	void setBlood(int newBlood);

	int getPower() const;
	void setPower(int newPower);

	void draw() const override;
	void interactWithPlayer(Player& player) override; 

    Monster* clone() const override;

    bool isAlive() const override;

	~Monster();
};

void Monster::interactWithPlayer(Player& player)
{
	player.setBlood(player.getBlood() - power);
    setBlood(blood - player.getPower());
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
    if (newPower < 0)
    {
        power = 0;
        return;
    }

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

void Monster::draw() const
{
    std::cout << "m(p:" << power << ",b:" << blood << ")";
}

Monster *Monster::clone() const
{
    return new Monster(*this);
}

void Monster::copyFrom(const Monster& other)
{
    name = new char[strlen(other.name)];
    strcpy(name, other.name);

    blood = other.blood;
    power = other.power;
}

Monster::Monster(const Monster &other)
{
    copyFrom(other);
}

bool Monster::isAlive() const
{
    return blood > 0;
}
