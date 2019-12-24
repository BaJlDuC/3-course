#pragma once
#include "FactoryMethodCreator.h"

class RectangleCreator : public Creator
{
private:
	static RectangleCreator *singletonRectangleCreator;
	RectangleCreator() {};
	RectangleCreator(const RectangleCreator&);
	RectangleCreator& operator=(RectangleCreator&);
public:
	static RectangleCreator* getSingletonRectangleCreator();
	SFMLDecorator* createShape(vector<float> &input) const override;
};
