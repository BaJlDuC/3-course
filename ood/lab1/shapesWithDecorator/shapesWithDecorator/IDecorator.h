#pragma once
//#include "SFMLDecorator.h"
#include <vector>

using namespace std;

class IDecorator : public IShape
{
	IShape *shape;
public:
	IDecorator(IShape *s);
	void PrintInfo(vector<string>& stream) const;
	string GetShapeType() const;
	vector<int> GetSize() const;
	void DrawShape(sf::RenderWindow &window) const;
};
