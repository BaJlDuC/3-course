#include "CTriangle.h"
#include <iostream>

using namespace std;

CTriangle::CTriangle(vector<float> &input)
{
	float x = input.at(2) - input.at(0);
	float y = input.at(3) - input.at(1);
	side1 = sqrt(pow(x, 2) + pow(y, 2));

    x = input.at(4) - input.at(2);
    y = input.at(5) - input.at(3);
	side2 = sqrt(pow(x, 2) + pow(y, 2));

	x = input.at(4) - input.at(0);
	y = input.at(5) - input.at(1);
	side3 = sqrt(pow(x, 2) + pow(y, 2));

	sf::ConvexShape* triangle = new sf::ConvexShape();
	triangle->setPointCount(3);
	triangle->setPoint(0, { input.at(0), input.at(1) });
	triangle->setPoint(1, { input.at(2), input.at(3) });
	triangle->setPoint(2, { input.at(4), input.at(5) });

	myShape = triangle;
}

double CTriangle::GetPerimeter() const
{
	double perimeter = side1 + side2 + side3;
	return perimeter;
}
double CTriangle::GetSquare() const
{
	int p = (side1 + side2 + side3) / 2;
	double square = sqrt(p * (p - side1) * (p - side2) * (p - side3));
	return square;
}

string CTriangle::GetName() const
{
	return name;
}
