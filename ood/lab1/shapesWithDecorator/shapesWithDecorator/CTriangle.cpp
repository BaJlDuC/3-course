#include "CTriangle.h"
#include <iostream>

using namespace std;

CTriangle::CTriangle(sf::ConvexShape triangle)
{
	triangleShape = triangle;

	int x = triangle.getPoint(1).x - triangle.getPoint(0).x;
	int y = triangle.getPoint(1).y - triangle.getPoint(0).y;
	int side1 = sqrt(pow(x, 2) + pow(y, 2));

    x = triangle.getPoint(2).x - triangle.getPoint(1).x;
    y = triangle.getPoint(2).y - triangle.getPoint(1).y;
	int side2 = sqrt(pow(x, 2) + pow(y, 2));

	x = triangle.getPoint(2).x - triangle.getPoint(0).x;
	y = triangle.getPoint(2).y - triangle.getPoint(0).y;
	int side3 = sqrt(pow(x, 2) + pow(y, 2));
	
	size.push_back(side1);
	size.push_back(side2);
	size.push_back(side3);
}

void CTriangle::PrintInfo(vector<string>& stream) const
{
	stream.push_back("TRIANGLE:");
}

string CTriangle::GetShapeType() const
{
	return "TRIANGLE";
}

vector<int> CTriangle::GetSize() const
{
	return size;
}

void CTriangle::DrawShape(sf::RenderWindow &window) const
{
	window.draw(triangleShape);
}

//vector<int> CTriangle::GetSize() const
//{
//	return size;
//}
//
//void CTriangle::SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const
//{
//	int side1 = sqrt(pow((point2.x, -point1.x), 2) + pow((point2.y - point1.y), 2));
//	int side2 = sqrt(pow((point3.x, -point2.x), 2) + pow((point3.y - point2.y), 2));
//	int side3 = sqrt(pow((point3.x, -point1.x), 2) + pow((point3.y - point1.y), 2));
//	sizePtr->push_back(side1);
//	sizePtr->push_back(side2);
//	sizePtr->push_back(side3);
//	//cout << size.at(0) << ' ' << size.at(1) << ' ' << size.at(2) << endl;
//}