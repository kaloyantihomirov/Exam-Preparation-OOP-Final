#pragma once

#include "Object.h"

class Gift : public Object
{
protected:
	int value;
public:
	Gift(int _value);
};

Gift::Gift(int _value) : value(_value)
{

}