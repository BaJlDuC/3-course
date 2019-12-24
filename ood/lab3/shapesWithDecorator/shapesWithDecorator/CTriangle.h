#pragma once
#include "SFMLDecorator.h"
#include <SFML/Graphics.hpp>
#include "Visitor.h" 

using namespace std;

class CTriangle : public SFMLDecorator
{
protected:
	vector<float> point1, point2, point3;
    int side1, side2, side3;
	string name = "TRIANGLE:";
public:
	CTriangle(vector<float> &input);
	
	double GetPerimeter() const override;
	double GetSquare() const override;
	string GetName() const override;
	void acceptVisitor(Visitor &visitor, string &result) override;
};