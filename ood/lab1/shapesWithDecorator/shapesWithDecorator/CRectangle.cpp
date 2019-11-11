#include "CRectangle.h"
#include <iostream>

using namespace std;

CRectangle::CRectangle(sf::RectangleShape rectangle)
{
	rectangleShape = rectangle;

	size.push_back(rectangle.getSize().x);
	size.push_back(rectangle.getSize().y);
}

void CRectangle::PrintInfo(vector<string>& stream) const
{
	stream.push_back("RECTANGLE:");
}

string CRectangle::GetShapeType() const
{
	return "RECTANGLE";
}

vector<int> CRectangle::GetSize() const
{
	return size;
}

void CRectangle::DrawShape(sf::RenderWindow &window) const
{
	window.draw(rectangleShape);
}

//vector<int> CRectangle::GetSize() const
//{
//	return size;
//}
//
//void CRectangle::SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const
//{
//	return;
//}