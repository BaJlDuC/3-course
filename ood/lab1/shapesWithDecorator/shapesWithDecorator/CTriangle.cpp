#include "CTriangle.h"
#include <iostream>

using namespace std;

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

void CTriangle::SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const
{
	int side1 = sqrt(pow((point2.x, -point1.x), 2) + pow((point2.y - point1.y), 2));
	int side2 = sqrt(pow((point3.x, -point2.x), 2) + pow((point3.y - point2.y), 2));
	int side3 = sqrt(pow((point3.x, -point1.x), 2) + pow((point3.y - point1.y), 2));
	sizePtr->push_back(side1);
	sizePtr->push_back(side2);
	sizePtr->push_back(side3);
	//cout << size.at(0) << ' ' << size.at(1) << ' ' << size.at(2) << endl;
}