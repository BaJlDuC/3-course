#include "CCircle.h"
#include <iostream>

using namespace std;

CCircle::CCircle(sf::CircleShape circle)
{
	radius.push_back(circle.getRadius());
}

void CCircle::PrintInfo(vector<string>& stream) const
{
	stream.push_back("CIRCLE:");
}

string CCircle::GetShapeType() const
{
	return "CIRCLE";
}

vector<int> CCircle::GetSize() const
{
	return radius;
}

void CCircle::SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const
{
	return;
}