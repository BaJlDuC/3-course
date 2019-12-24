#pragma once
#include "Visitor.h"

using namespace std;

class SquarePerimeterVisitor : public Visitor
{
public:
	string getSquarePerimeterToOutput(CCircle *circle) const override;
	string getSquarePerimeterToOutput(CRectangle *rectangle) const override;
	string getSquarePerimeterToOutput(CTriangle *triangle) const override;
};