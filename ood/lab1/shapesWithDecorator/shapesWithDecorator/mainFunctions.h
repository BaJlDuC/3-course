#pragma once
#include <iostream>
#include <fstream>
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

using namespace std;

const string RECTANGLE = "RECTANGLE:";
const string CIRCLE = "CIRCLE:";
const string TRIANGLE = "TRIANGLE:";
const string UNKNOWN_FIGURE = "Unknown figure";

void rectangleHandler(ifstream &inputFile, vector<SFMLDecorator*> &shapes)
{
	string point1 = "", point2 = "";
	vector<string> stream;

	inputFile >> point1 >> point2;
	float x1 = stoi(point1.substr(3));
	float y1 = stoi(point1.substr(7));
	float x2 = stoi(point2.substr(3));
	float y2 = stoi(point2.substr(7));
	float height = abs(x2 - x1);
	float width = abs(y2 - y1);
	float centerX = height / 2;
	float centerY = width / 2;

	SFMLDecorator *rectangle = new CRectangle(width, height, centerX, centerY);
	shapes.push_back(rectangle);
}

void triangleHandler(ifstream &inputFile, vector<SFMLDecorator*> &shapes)
{
	string point1 = "", point2 = "", point3 = "";
	vector<float> trianglePoint1, trianglePoint2, trianglePoint3;
	vector<string> stream;

	inputFile >> point1 >> point2 >> point3;
	trianglePoint1.push_back(stoi(point1.substr(3)));
	trianglePoint1.push_back(stoi(point1.substr(7)));
	trianglePoint2.push_back(stoi(point2.substr(3)));
	trianglePoint2.push_back(stoi(point2.substr(7)));
	trianglePoint3.push_back(stoi(point3.substr(3)));
	trianglePoint3.push_back(stoi(point3.substr(7)));

	SFMLDecorator *triangle = new CTriangle(trianglePoint1, trianglePoint2, trianglePoint3);
	shapes.push_back(triangle);
}

void circleHandler(ifstream &inputFile, vector<SFMLDecorator*> &shapes)
{
	string center = "", radius = "";
	vector <string> stream;
	vector<float> centerPoint;

	inputFile >> center >> radius;
	centerPoint.push_back(stoi(center.substr(2)));
	centerPoint.push_back(stoi(center.substr(6)));
	float r = stoi(radius.substr(2));

	SFMLDecorator *circle = new CCircle(centerPoint, r);
	shapes.push_back(circle);
}

void dataHandler(ifstream& inputFile, vector<SFMLDecorator*> &shapes)
{
	string shapeType = "";
	while (!inputFile.eof())
	{
		inputFile >> shapeType;
		if (shapeType == RECTANGLE)
		{
			rectangleHandler(inputFile, shapes);
		}
		else if (shapeType == CIRCLE)
		{
			circleHandler(inputFile, shapes);
		}
		else if (shapeType == TRIANGLE)
		{
			triangleHandler(inputFile, shapes);
		}
		else
		{
			cout << UNKNOWN_FIGURE << endl;
			return;
		}
	}
}
