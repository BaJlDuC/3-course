#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class CTriangle : public IShape
{
public:
	vector<int> size;
	vector<int> *sizePtr = &size;

	CTriangle(sf::ConvexShape triangle) {}

	void PrintInfo(vector<string>& stream) const override;
	string GetShapeType() const override;
	vector<int> GetSize() const override;
	void SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const override;
};