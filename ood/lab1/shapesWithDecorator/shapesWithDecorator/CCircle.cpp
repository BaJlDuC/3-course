#include "CCircle.h"
#include <iostream>

using namespace std;

CCircle::CCircle(vector<float> &centerPoint, float &radius)
{
	center = centerPoint;
	rad = radius;

	myShape = new sf::CircleShape(rad);
	myShape->setPosition({ center.at(0), center.at(1) });
}

double CCircle::GetPerimeter() const
{
	double perimeter = 2 * 3.14 * rad;
	return perimeter;
}

double CCircle::GetSquare() const
{
	double square = 3.14 * rad * rad;
	return square;
}

string CCircle::GetName() const
{
	return name;
}