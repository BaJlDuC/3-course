#pragma once
#include <SFML/Graphics.hpp>
#include "IShape.h"
//#include "mainFunctions.h"
#include <iostream>

using namespace std;

class CPerimeterCalculation : public IShape
{
	unique_ptr<IShape> m_shape;
public:
	CPerimeterCalculation(IShape* shape) : m_shape(shape) {}

	void PrintInfo(vector<string>& stream) const override;
	string GetShapeType() const override;
	vector<int> GetSize() const override;
	void SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const override;
};