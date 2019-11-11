#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>

using namespace std;

class CRectangle : public IShape
{
	//unique_ptr<sf::RectangleShape> rectangleShape;
	sf::RectangleShape rectangleShape;
protected:
	vector<int> size;
public:
	//vector<int> size;
	
	CRectangle(sf::RectangleShape rectangle);
	void PrintInfo(vector<string>& stream) const override;
	string GetShapeType() const override;
	vector<int> GetSize() const override;
	void DrawShape(sf::RenderWindow &window) const override;
};
