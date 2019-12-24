#include "FactoryMethodCircleCreator.h"
#include "CCircle.h"

SFMLDecorator* CircleCreator::createShape(vector<float> &input) const
{
	return new CCircle(input);
}

CircleCreator* CircleCreator::getSingletonCircleCreator()
{
	if (!singletonCircleCreator)
	{
		singletonCircleCreator = new CircleCreator();
	}
	return singletonCircleCreator;
}

CircleCreator* CircleCreator::singletonCircleCreator = 0;