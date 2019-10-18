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
	//sf::RenderWindow window(sf::VideoMode({ 1024, 768 }), "ShapesWindow");
	//window.clear();

	sf::ConvexShape triangle(3);
	triangle.setPointCount(3);;
	/*triangle.setPoint(0, sf::Vector2f{ 400, 600 });
	triangle.setPoint(1, sf::Vector2f{ 400, 200 });
	triangle.setPoint(2, sf::Vector2f{ 800, 200 });*/

	//window.draw(triangle);
	//window.display();
	//sf::sleep(sf::seconds(3));
	

	dataHandler(inputFile, outputFile);
}