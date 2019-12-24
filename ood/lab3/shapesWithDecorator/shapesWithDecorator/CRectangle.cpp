#include "CRectangle.h"
#include <iostream>

using namespace std;

CRectangle::CRectangle(vector<float> &input)
{
	width = input.at(0);
	height = input.at(1);

	myShape = new sf::RectangleShape({ width, height });
	myShape->setPosition({ input.at(2), input.at(3) });
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

void CRectangle::acceptVisitor(Visitor &visitor, string &result)
{
	result = visitor.getSquarePerimeterToOutput(this);
}