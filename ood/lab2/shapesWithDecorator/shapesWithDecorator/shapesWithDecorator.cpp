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
	vector<sf::Shape*> SfmlShapes;
	float dX = 0;
	float dY = 0;
	bool isMove = false;
	int changedId = 0;
	sf::Shape *myShapePtr;

	dataHandler(inputFile, shapes);
	for (int i = 0; i < shapes.size(); i++)
	{
		outputFile << shapes.at(i)->GetName() << " P=" << shapes.at(i)->GetPerimeter() << "; S=" << shapes.at(i)->GetSquare() << endl;
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
			SfmlShapes[changedId]->setPosition({mousePos.x - dX, mousePos.y - dY});
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