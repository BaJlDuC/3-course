#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace std;

class IShape
{
	unique_ptr<sf::Shape> shape;
public:
	IShape() {}
	virtual void PrintInfo(vector<string> &stream) const = 0;
	virtual string GetShapeType() const = 0;
	virtual vector<int> GetSize() const = 0;
	virtual void DrawShape(sf::RenderWindow &window) const = 0;
};
