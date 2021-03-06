#pragma once
#include "SFMLDecorator.h"
#include <SFML/Graphics.hpp>

using namespace std;

class CCircle : public SFMLDecorator
{
protected:
	vector<float> center;
	float rad;
	string name = "CIRCLE:";
public:

	CCircle(vector<float> &centerPoint, float &radius);

	double GetPerimeter() const override;
	double GetSquare() const override;
	string GetName() const override;
};