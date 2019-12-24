#include "FactoryMethodTriangleCreator.h"
#include "CTriangle.h"

SFMLDecorator* TriangleCreator::createShape(vector<float> &input) const
{
	return new CTriangle(input);
}

TriangleCreator* TriangleCreator::getSingletonTriangleCreator()
{
	if (!singletonTriangleCreator)
	{
		singletonTriangleCreator = new TriangleCreator();
	}
	return singletonTriangleCreator;
}

TriangleCreator* TriangleCreator::singletonTriangleCreator = 0;