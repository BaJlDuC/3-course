#include "CCircle.h"
#include <iostream>

using namespace std;

CCircle::CCircle(sf::CircleShape circle)
{
	circleShape = circle;
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

void CCircle::DrawShape(sf::RenderWindow &window) const
{
	window.draw(circleShape);
}

//unique_ptr<sf::CircleShape> CCircle::GetSfmlShape() const
//{
//	return circleShape;
//}
//vector<int> CCircle::GetSize() const
//{
//	return radius;
//}
//
//void CCircle::SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const
//{
//	return;
//}