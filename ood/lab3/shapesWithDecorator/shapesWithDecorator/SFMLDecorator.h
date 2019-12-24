#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;

class SFMLDecorator
{
public:
	sf::Shape *myShape;
	SFMLDecorator() {}
	SFMLDecorator(sf::Shape* shape): myShape(shape) {}

	virtual double GetPerimeter() const = 0;
	virtual double GetSquare() const = 0;
	virtual string GetName() const = 0;
	virtual void acceptVisitor(class Visitor &visitor, string &result) = 0;
};
