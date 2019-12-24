#pragma once
#include "FactoryMethodCreator.h"

class CircleCreator : public Creator
{
private:
	static CircleCreator *singletonCircleCreator;
	CircleCreator() {};
	CircleCreator(const CircleCreator&);
	CircleCreator& operator=(CircleCreator&);
public:
	static CircleCreator* getSingletonCircleCreator();
	SFMLDecorator* createShape(vector<float> &input) const override;
};
