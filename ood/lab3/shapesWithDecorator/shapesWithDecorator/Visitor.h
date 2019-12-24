#pragma once
#include <string>

using namespace std;

class Visitor
{
public:
	virtual string getSquarePerimeterToOutput(class CCircle *circle) const = 0;
	virtual string getSquarePerimeterToOutput(class CRectangle *rectangle) const = 0;
	virtual string getSquarePerimeterToOutput(class CTriangle *triangle) const = 0;
};