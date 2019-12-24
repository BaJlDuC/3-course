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
	vector<SFMLDecorator*> shapes;

	dataHandler(inputFile, shapes);
	eventHandler(shapes, window, outputFile);
}