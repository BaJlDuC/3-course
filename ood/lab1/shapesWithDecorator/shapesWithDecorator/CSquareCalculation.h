#pragma once
#include <SFML/Graphics.hpp>
#include "IShape.h"
//#include "mainFunctions.h"
#include <iostream>
#include <sstream>

using namespace std;

class CSquareCalculation : public IShape
{
	unique_ptr<IShape> m_shape;
public:
	CSquareCalculation(IShape* shape) : m_shape(shape) {};

	void PrintInfo(vector<string>& stream) const override;
	string GetShapeType() const override;
	vector<int> GetSize() const override;
	void SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const override;
};