#pragma once
#include <iostream>
#include <fstream>
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "FactoryMethodCircleCreator.h"
#include "FactoryMethodRectangleCreator.h"
#include "FactoryMethodTriangleCreator.h"
#include "SquarePerimeterVisitor.h"

using namespace std;

const string RECTANGLE = "RECTANGLE:";
const string CIRCLE = "CIRCLE:";
const string TRIANGLE = "TRIANGLE:";
const string UNKNOWN_FIGURE = "Unknown figure";



sf::Shape* createConcreteSfmlFigures(SFMLDecorator* myShapeDecor, sf::Shape* SfmlShape)
{
	if (myShapeDecor->GetName() == "TRIANGLE:")
	{
		sf::ConvexShape *triangle = new sf::ConvexShape(3);
		triangle->setPoint(0, { SfmlShape->getPoint(0) });
		triangle->setPoint(1, { SfmlShape->getPoint(1) });
		triangle->setPoint(2, { SfmlShape->getPoint(2) });
		triangle->setPosition({ SfmlShape->getPosition() });
		triangle->setFillColor(SfmlShape->getFillColor());

		sf::Shape *triangleShape = triangle;
		return triangleShape;
	}
	else if (myShapeDecor->GetName() == "RECTANGLE:")
	{
		sf::RectangleShape *rectangle = new sf::RectangleShape();
		rectangle->setSize({ SfmlShape->getGlobalBounds().height,SfmlShape->getGlobalBounds().width });
		rectangle->setPosition({ SfmlShape->getPosition() });
		rectangle->setFillColor(SfmlShape->getFillColor());

		sf::Shape *rectangleShape = rectangle;
		return rectangleShape;
	}
	else 
	{
		sf::CircleShape *circle = new sf::CircleShape();
		circle->setRadius(SfmlShape->getGlobalBounds().height / 2);
		circle->setPosition({SfmlShape->getPosition() });
		circle->setFillColor(SfmlShape->getFillColor());

		sf::Shape *circleShape = circle;
		return circleShape;
	}
}

void eventHandler(vector<SFMLDecorator*> &shapes, sf::RenderWindow &window, ofstream &outputFile)
{
	vector<sf::Shape*> SfmlShapes;
	float dX = 0;
	float dY = 0;
	bool isMove = false;
	int changedId = 0;
	sf::Shape *myShapePtr;

	SquarePerimeterVisitor squareAndPerimeter;
	string result = "";
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes.at(i)->acceptVisitor(squareAndPerimeter, result);
		outputFile << result << endl;
		SfmlShapes.push_back(shapes[i]->myShape);
	}

	while (window.isOpen())
	{
		sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
			{
				for (int i = 0; i < shapes.size(); i++)
				{
					if (SfmlShapes[i]->getGlobalBounds().contains(mousePos))
					{
						changedId = i;
						myShapePtr = SfmlShapes[i];
						cout << "Clicked on " << shapes[i]->GetName() << endl;
						dX = mousePos.x - SfmlShapes[i]->getPosition().x;
						dY = mousePos.y - SfmlShapes[i]->getPosition().y;
						isMove = true;
					}
				}
				break;
			}
			case sf::Event::MouseButtonReleased:
				SfmlShapes[changedId]->setFillColor(sf::Color::White);
				isMove = false;
				break;
			default:
				break;
			}
		}
		if (isMove)
		{
			SfmlShapes[changedId]->setFillColor(sf::Color::Green);
			SfmlShapes[changedId]->setPosition({ mousePos.x - dX, mousePos.y - dY });
		}

		window.clear();
		for (int i = 0; i < shapes.size(); i++)
		{
			sf::Shape *myShapePtr = createConcreteSfmlFigures(shapes[i], SfmlShapes[i]);
			window.draw(*myShapePtr);
		}
		window.display();
	}
}

void rectangleHandler(ifstream &inputFile, vector<SFMLDecorator*> &shapes)
{
	string point1 = "", point2 = "";
	vector<string> stream;
	vector<float> input;

	inputFile >> point1 >> point2;
	float x1 = stoi(point1.substr(3));
	float y1 = stoi(point1.substr(7));
	float x2 = stoi(point2.substr(3));
	float y2 = stoi(point2.substr(7));
	float height = abs(x2 - x1);
	float width = abs(y2 - y1);
	float positionX = 0;
	float positionY = 0;
	if (x1 > x2)
	{
		positionX = x2;
	}
	else
	{
		positionX = x1;
	}
	if (y1 > y2)
	{
		positionY = y2;
	}
	else
	{
		positionY = y1;
	}
	input.push_back(width);
	input.push_back(height);
	input.push_back(positionX);
	input.push_back(positionY);

	RectangleCreator *rectangleFactory = RectangleCreator::getSingletonRectangleCreator();
	shapes.push_back(rectangleFactory->createShape(input));
}

void triangleHandler(ifstream &inputFile, vector<SFMLDecorator*> &shapes)
{
	string point1 = "", point2 = "", point3 = "";
	vector<float> trianglePoint1, trianglePoint2, trianglePoint3;
	vector<string> stream;
	vector<float> input;

	inputFile >> point1 >> point2 >> point3;
	input.push_back(stoi(point1.substr(3)));
	input.push_back(stoi(point1.substr(7)));
	input.push_back(stoi(point2.substr(3)));
	input.push_back(stoi(point2.substr(7)));
	input.push_back(stoi(point3.substr(3)));
	input.push_back(stoi(point3.substr(7)));

	TriangleCreator *triangleFactory = TriangleCreator::getSingletonTriangleCreator();
	shapes.push_back(triangleFactory->createShape(input));
}

void circleHandler(ifstream &inputFile, vector<SFMLDecorator*> &shapes)
{
	string center = "", radius = "";
	vector <string> stream;
	vector<float> input;

	inputFile >> center >> radius;
	input.push_back(stoi(center.substr(2)));
	input.push_back(stoi(center.substr(6)));
	float r = stoi(radius.substr(2));
	input.push_back(r);

	CircleCreator* circleFactory = CircleCreator::getSingletonCircleCreator();
	shapes.push_back(circleFactory->createShape(input));
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
