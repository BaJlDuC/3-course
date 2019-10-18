#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class CRectangle : public IShape
{
public:
	vector<int> size;
	
	CRectangle(sf::RectangleShape rectangle);

	void PrintInfo(vector<string>& stream) const override;
	string GetShapeType() const override;
	vector<int> GetSize() const override;
	void SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const override;
};
