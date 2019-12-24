#pragma once
#include "FactoryMethodCreator.h"

class TriangleCreator : public Creator
{
private:
	static TriangleCreator *singletonTriangleCreator;
	TriangleCreator() {};
	TriangleCreator(const TriangleCreator&);
	TriangleCreator& operator=(TriangleCreator&);
public:
	static TriangleCreator* getSingletonTriangleCreator();
	SFMLDecorator* createShape(vector<float> &input) const override;
};
