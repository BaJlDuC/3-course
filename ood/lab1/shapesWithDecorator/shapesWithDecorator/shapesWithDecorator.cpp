#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "mainFunctions.h"

using namespace std;

int main()
{
	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	sf::RenderWindow window(sf::VideoMode({ 1366, 768 }), "ShapesWindow");
	window.clear();
	vector<SFMLDecorator*> shapes;

	dataHandler(inputFile, shapes);
	for (int i = 0; i < shapes.size(); i++)
	{
		outputFile << shapes.at(i)->GetName() << " P=" << shapes.at(i)->GetPerimeter() << "; S=" << shapes.at(i)->GetSquare() << endl;
		sf::Shape *myShapePtr = shapes.at(i)->myShape;
		window.draw(*myShapePtr);
	}

	window.display();
	sf::sleep(sf::seconds(5));
}