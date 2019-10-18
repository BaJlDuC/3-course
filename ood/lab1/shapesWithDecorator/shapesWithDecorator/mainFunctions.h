#pragma once
#include <iostream>
#include <fstream>
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CPerimeterCalculation.h"
#include "CSquareCalculation.h"

using namespace std;

const string RECTANGLE = "RECTANGLE:";
const string CIRCLE = "CIRCLE:";
const string TRIANGLE = "TRIANGLE:";

struct Rectangle
{
	Point point1, point2;
};

struct Circle
{
	Point center;
	int radius;
};

struct Triangle
{
	Point point1, point2, point3;
};

void rectangleHandler(ifstream& inputFile, ofstream& outputFile)
{
	Rectangle rectangleStruct;
	string point;

	inputFile >> point;
	for (int i = 0; i < point.size(); i++)
	{
		if (point[i] == '=')
		{
			rectangleStruct.point1.x = stoi(point.substr(i + 1));
		}
		else if (point[i] == ',')
		{

			rectangleStruct.point1.y = stoi(point.substr(i + 1));
		}
	}

	inputFile >> point;
	for (int i = 0; i < point.size(); i++)
	{
		if (point[i] == '=')
		{
			rectangleStruct.point2.x = stoi(point.substr(i + 1));
		}
		else if (point[i] == ',')
		{

			rectangleStruct.point2.y = stoi(point.substr(i + 1));
		}
	}
	int side1 = rectangleStruct.point2.x - rectangleStruct.point1.x;
	int side2 = rectangleStruct.point2.y - rectangleStruct.point1.y;

	float side1f = (int)side1;
	float side2f = (int)side2;

	CSquareCalculation rectangle(new CPerimeterCalculation(new CRectangle(sf::RectangleShape({ side1f, side2f }))));

	vector<string> output;
	rectangle.PrintInfo(output);
	for (vector<string>::reverse_iterator it = output.rbegin(); it != output.rend(); it++)
	{
		outputFile << *it;
	}
	outputFile << endl;
}

void triangleHandler(ifstream& inputFile, ofstream& outputFile)
{
	Triangle triangleStruct;
	string point;

	inputFile >> point;
	for (int i = 0; i < point.size(); i++)
	{
		if (point[i] == '=')
		{
			triangleStruct.point1.x = stoi(point.substr(i + 1));
		}
		else if (point[i] == ',')
		{

			triangleStruct.point1.y = stoi(point.substr(i + 1));
		}
	}

	inputFile >> point;
	for (int i = 0; i < point.size(); i++)
	{
		if (point[i] == '=')
		{
			triangleStruct.point2.x = stoi(point.substr(i + 1));
		}
		else if (point[i] == ',')
		{

			triangleStruct.point2.y = stoi(point.substr(i + 1));
		}
	}

	inputFile >> point;
	for (int i = 0; i < point.size(); i++)
	{
		if (point[i] == '=')
		{
			triangleStruct.point3.x = stoi(point.substr(i + 1));
		}
		else if (point[i] == ',')
		{

			triangleStruct.point3.y = stoi(point.substr(i + 1));
		}
	}

	CSquareCalculation triangle(new CPerimeterCalculation(new CTriangle(sf::ConvexShape(3))));
	triangle.SetTrianglePoint(triangleStruct.point1, triangleStruct.point2, triangleStruct.point3);

	vector<string> output;
	triangle.PrintInfo(output);

	for (vector<string>::reverse_iterator it = output.rbegin(); it != output.rend(); it++)
	{
		outputFile << *it;
	}
	outputFile << endl;
}

void circleHandler(ifstream& inputFile, ofstream& outputFile)
{
	Circle circleStruct;
	string point;

	inputFile >> point;
	//circleStruct.center = point;
	inputFile >> point;

	for (int i = 0; i < point.size(); i++)
	{
		if (point[i] == '=')
		{
			circleStruct.radius = stoi(point.substr(i + 1));
		}
	}

	CSquareCalculation circle(new CPerimeterCalculation(new CCircle(sf::CircleShape(circleStruct.radius))));
	vector<string> output;
	circle.PrintInfo(output);
	
	for (vector<string>::reverse_iterator it = output.rbegin(); it != output.rend(); it++)
	{
		outputFile << *it;
	}
	outputFile << endl;
}

void dataHandler(ifstream& inputFile, ofstream& outputFile)
{
	if (!inputFile)
	{
		cout << "Input file not found" << endl;
		return;
	}

	string point, shapeType;
	while (!inputFile.eof())
	{
		inputFile >> shapeType;
		if (shapeType == RECTANGLE)
		{
			rectangleHandler(inputFile, outputFile);
		}
		else if (shapeType == CIRCLE)
		{
			circleHandler(inputFile, outputFile);
		}
		else if (shapeType == TRIANGLE)
		{
			triangleHandler(inputFile, outputFile);
		}
		else
		{
			cout << "Unknown figure" << endl;
			return;
		}
	}
}
