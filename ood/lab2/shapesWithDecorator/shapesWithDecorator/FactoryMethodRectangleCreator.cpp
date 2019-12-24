#include "FactoryMethodRectangleCreator.h"
#include "CRectangle.h"

SFMLDecorator* RectangleCreator::createShape(vector<float> &input) const
{
	return new CRectangle(input);
}

RectangleCreator* RectangleCreator::getSingletonRectangleCreator()
{
	if (!singletonRectangleCreator)
	{
		singletonRectangleCreator = new RectangleCreator();
	}
	return singletonRectangleCreator;
}

RectangleCreator* RectangleCreator::singletonRectangleCreator = 0;