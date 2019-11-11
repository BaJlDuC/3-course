#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>

using namespace std;

class CCircle : public IShape
{
	//unique_ptr<sf::CircleShape> circleShape;
	sf::CircleShape circleShape;
protected:
	vector<int> radius;
public:

	CCircle(sf::CircleShape circle);
	void PrintInfo(vector<string>& stream) const override;
	string GetShapeType() const override;
	vector<int> GetSize() const override;
	void DrawShape(sf::RenderWindow &window) const override;
};