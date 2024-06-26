#pragma once

#include "Player.h"

class Artifact
{
protected:
	int index;
public:
	Artifact(int _index);
	virtual void draw() const = 0;

	virtual void interactWithPlayer(Player& p) = 0;
};

Artifact::Artifact(int _index) : index(_index)
{

}