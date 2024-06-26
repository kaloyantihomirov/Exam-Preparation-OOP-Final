#pragma once
#include <stdexcept>

class Player
{
	char* name;
	const int maxBlood;
    int blood, power, index;

public:
	Player(const char* _name, int _initialBlood, int _maxBlood, int _power, int _index);
	//power [20; 100] -> setPower

	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;

	const char* getName() const;
	void setName(const char* _name);

	int getBlood() const;
	void setBlood(int newBloodVal);

	int getMaxBlood() const;
	
	void increaseBlood(int& by);

	int getPower() const;
	void setPower(int newPower);

	void setIndex(int newIndex);

	~Player();
};

void Player::setBlood(int newBloodVal)
{
	if (newBloodVal < 0)
	{
		blood = 0;
		return; 
	}

	if (newBloodVal > maxBlood)
	{
		blood = maxBlood;
		return;
	}

	blood = newBloodVal;
}

void Player::setName(const char* _name)
{
	if (!_name)
		throw std::invalid_argument("inv name");

	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

const char* Player::getName() const
{
	return name;
}

int Player::getBlood() const
{
	return blood;
}

int Player::getMaxBlood() const
{
	return maxBlood;
}

void Player::increaseBlood(int& by)
{
	int currentBlood = blood;
	blood += by;

	if (blood > maxBlood)
	{
		blood = maxBlood;
		by -= maxBlood - currentBlood;
	}
}

int Player::getPower() const
{
	return power;
}

void Player::setPower(int newPower)
{
	if (newPower < 20 || newPower > 100)
	{
		delete[] name; //thats why we use smart pointers!
		throw std::invalid_argument("inv power");
	}

	power = newPower;
}

Player::Player(const char* _name, int _initialBlood, int _maxBlood, int _power, int _index) : blood(_initialBlood), maxBlood(_maxBlood), index(_index)
{
	setName(_name);
	setPower(_power);
}

void Player::setIndex(int _newIndex)
{
	index = _newIndex;
}

Player::~Player()
{
	delete[] name;
	name = nullptr;
}