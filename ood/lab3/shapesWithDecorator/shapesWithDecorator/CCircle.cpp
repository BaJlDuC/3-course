#include "CCircle.h"
#include <iostream>

using namespace std;

CCircle::CCircle(vector<float> &input)
{
	center.push_back(input.at(0));
	center.push_back(input.at(1));
	rad = input.at(2);

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

void CCircle::acceptVisitor(Visitor &visitor, string &result)
{
	result = visitor.getSquarePerimeterToOutput(this);
}