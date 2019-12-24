#pragma once
#include "SFMLDecorator.h"

class Creator
{
public:
	virtual SFMLDecorator* createShape(vector<float> &input) const = 0;
};