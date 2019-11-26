#include "CTriangle.h"
#include <iostream>

using namespace std;

CTriangle::CTriangle(vector<float> &trianglePoint1, vector<float> &trianglePoint2, vector<float> &trianglePoint3)
{
	float x = trianglePoint2.at(0) - trianglePoint1.at(0);
	float y = trianglePoint2.at(1) - trianglePoint1.at(1);
	side1 = sqrt(pow(x, 2) + pow(y, 2));

    x = trianglePoint3.at(0) - trianglePoint2.at(0);
    y = trianglePoint3.at(1) - trianglePoint2.at(1);
	side2 = sqrt(pow(x, 2) + pow(y, 2));

	x = trianglePoint3.at(0) - trianglePoint1.at(0);
	y = trianglePoint3.at(1) - trianglePoint1.at(1);
	side3 = sqrt(pow(x, 2) + pow(y, 2));

	sf::ConvexShape* triangle = new sf::ConvexShape();
	triangle->setPointCount(3);
	triangle->setPoint(0, { trianglePoint1.at(0), trianglePoint1.at(1) });
	triangle->setPoint(1, { trianglePoint2.at(0), trianglePoint2.at(1) });
	triangle->setPoint(2, { trianglePoint3.at(0), trianglePoint3.at(1) });
	
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
