#pragma once

#include "Player.h"

class Artifact
{
public:
	virtual void draw() const = 0;

	virtual void interactWithPlayer(Player& p) = 0;

    virtual Artifact* clone() const = 0;

    virtual bool isAlive() const;

    virtual ~Artifact() = default;
};

bool Artifact::isAlive() const
{
    return true;
}

