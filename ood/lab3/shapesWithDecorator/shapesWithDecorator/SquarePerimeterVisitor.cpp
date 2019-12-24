#include "SquarePerimeterVisitor.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

string SquarePerimeterVisitor::getSquarePerimeterToOutput(CCircle *circle) const 
{
	string output = "CIRCLE: P=" + to_string(circle->GetPerimeter()) + "; S=" + to_string(circle->GetSquare());
	return output;
}

string SquarePerimeterVisitor::getSquarePerimeterToOutput(CRectangle *rectangle) const 
{
	string output = "RECTANGLE: P=" + to_string(rectangle->GetPerimeter()) + "; S=" + to_string(rectangle->GetSquare());
	return output;
}

string SquarePerimeterVisitor::getSquarePerimeterToOutput(CTriangle *triangle) const 
{
	string output = "TRIANGLE: P=" + to_string(triangle->GetPerimeter()) + "; S=" + to_string(triangle->GetSquare());
	return output;
}