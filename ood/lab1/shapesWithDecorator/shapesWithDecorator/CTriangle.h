#pragma once
#include "SFMLDecorator.h"
#include <SFML/Graphics.hpp>

using namespace std;

class CTriangle : public SFMLDecorator
{
protected:
	vector<float> point1, point2, point3;
    int side1, side2, side3;
	string name = "TRIANGLE:";
public:
	CTriangle(vector<float> &trianglePoint1, vector<float> &trianglePoint2, vector<float> &trianglePoint3);
	
	double GetPerimeter() const override;
	double GetSquare() const override;
	string GetName() const override;
};