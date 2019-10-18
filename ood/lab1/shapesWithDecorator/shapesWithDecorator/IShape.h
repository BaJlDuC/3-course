#pragma once
#include <SFML/Graphics.hpp>
//#include "mainFunctions.h"
#include <sstream>

using namespace std;

struct Point
{
	int x = 0, y = 0;
};

class IShape
{
public:
	virtual void PrintInfo(vector<string>& stream) const = 0;
	virtual string GetShapeType() const = 0;
	virtual vector<int> GetSize() const = 0;
	virtual void SetTrianglePoint(struct Point& point1, struct Point& point2, struct Point& point3) const = 0;
};
