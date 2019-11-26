#include "CRectangle.h"
#include <iostream>

using namespace std;

CRectangle::CRectangle(float &rectangleWidth, float &rectangleHeight, float &positionX, float &positionY)
{
	width = rectangleWidth;
	height = rectangleHeight;

	myShape = new sf::RectangleShape({ width, height });
	myShape->setPosition({ positionX, positionY });
}

double CRectangle::GetPerimeter() const
{
	double perimeter = (width + height) * 2;
	return perimeter;
}
double CRectangle::GetSquare() const
{
	double square = width * height;
	return square;
}

string CRectangle::GetName() const
{
	return name;
}