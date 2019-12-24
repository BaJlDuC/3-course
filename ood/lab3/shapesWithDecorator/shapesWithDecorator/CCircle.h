#pragma once
#include "SFMLDecorator.h"
#include <SFML/Graphics.hpp>
#include "Visitor.h" //??????????????

using namespace std;

class CCircle : public SFMLDecorator
{
protected:
	vector<float> center;
	float rad;
	string name = "CIRCLE:";
public:

	CCircle(vector<float> &input);

	double GetPerimeter() const override;
	double GetSquare() const override;
	string GetName() const override;
	void acceptVisitor(Visitor &visitor, string &result) override;
};