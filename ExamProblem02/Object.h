#pragma once

#include "Artifact.h"

class Object : public Artifact
{
public:
	Object(int _index);
};

Object::Object(int _index) : Artifact(_index) { }