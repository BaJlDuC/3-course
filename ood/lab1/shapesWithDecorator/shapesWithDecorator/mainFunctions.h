#pragma once
#include <iostream>
#include <fstream>
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CPerimeterDecorator.h"
#include "CSquareDecorator.h"

using namespace std;

const string RECTANGLE = "RECTANGLE:";
const string CIRCLE = "CIRCLE:";
const string TRIANGLE = "TRIANGLE:";

void rectangleHandler(ifstream &inputFile, ofstream &outputFile, sf::RenderWindow &window)
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

	sf::RectangleShape rectangleShape({ height, width });
	rectangleShape.setPosition({ centerX, centerY });

	IShape *rectangle = new CPerimeterDecorator(new CSquareDecorator(new CRectangle(rectangleShape)));
	rectangle->PrintInfo(stream);
	rectangle->DrawShape(window);
	for (vector<string>::iterator it = stream.begin(); it != stream.end(); it++)
	{
		outputFile << *it;
	}
	outputFile << endl;
}

void triangleHandler(ifstream &inputFile, ofstream  &outputFile, sf::RenderWindow &window)
{
	string point1 = "", point2 = "", point3 = "";
	vector<string> stream;

	inputFile >> point1 >> point2 >> point3;
	float x1 = stoi(point1.substr(3));
	float y1 = stoi(point1.substr(7));
	float x2 = stoi(point2.substr(3));
	float y2 = stoi(point2.substr(7));
	float x3 = stoi(point3.substr(3));
	float y3 = stoi(point3.substr(7));

	sf::ConvexShape triangleShape(3);
	triangleShape.setPoint(0, { x1, y1 });
	triangleShape.setPoint(1, { x2, y2 });
	triangleShape.setPoint(2, { x3, y3 });

	IShape *triangle = new CPerimeterDecorator(new CSquareDecorator(new CTriangle(triangleShape)));
	triangle->PrintInfo(stream);
	triangle->DrawShape(window);
	for (vector<string>::iterator it = stream.begin(); it != stream.end(); it++)
	{
		outputFile << *it;
	}
	outputFile << endl;
}

void circleHandler(ifstream &inputFile, ofstream &outputFile, sf::RenderWindow &window)
{
	string center = "", radius = "";
	vector <string> stream;

	inputFile >> center >> radius;
	float x1 = stoi(center.substr(2));
	float y1 = stoi(center.substr(6));
	int r = stoi(radius.substr(2));

	sf::CircleShape circleShape(r);
	circleShape.setPosition({ x1, y1 });

	IShape *circle = new CPerimeterDecorator(new CSquareDecorator(new CCircle(circleShape)));
    circle->PrintInfo(stream);
	circle->DrawShape(window);
	for (vector<string>::iterator it = stream.begin(); it != stream.end(); it++)
	{
		outputFile << *it;
	}
	outputFile << endl;
}

void dataHandler(ifstream& inputFile, ofstream& outputFile, sf::RenderWindow &window)
{
	string shapeType = "";
	while (!inputFile.eof())
	{
		inputFile >> shapeType;
		if (shapeType == RECTANGLE)
		{
			rectangleHandler(inputFile, outputFile, window);
		}
		else if (shapeType == CIRCLE)
		{
			circleHandler(inputFile, outputFile, window);
		}
		else if (shapeType == TRIANGLE)
		{
			triangleHandler(inputFile, outputFile, window);
		}
		else
		{
			cout << "Unknown figure" << endl;
			return;
		}
	}
}
