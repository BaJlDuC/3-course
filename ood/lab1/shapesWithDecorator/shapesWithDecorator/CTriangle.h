#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>

using namespace std;

class CTriangle : public IShape
{
	//unique_ptr<sf::ConvexShape> triangleShape;
	sf::ConvexShape triangleShape;
protected:
	vector<int> size;
public:
	CTriangle(sf::ConvexShape triangle);
	void PrintInfo(vector<string>& stream) const override;
	string GetShapeType() const override;
	vector<int> GetSize() const override;
	void DrawShape(sf::RenderWindow &window) const override;
};