#pragma once
#include "SFMLDecorator.h"
#include <SFML/Graphics.hpp>

using namespace std;

class CRectangle : public SFMLDecorator
{
protected:
	float width, height;
	string name = "RECTANGLE:";
public:
	CRectangle(float &rectangleWidth, float &rectangleHeight, float &positionX, float &positionY);

	double GetPerimeter() const override;
	double GetSquare() const override;
	string GetName() const override;
};
