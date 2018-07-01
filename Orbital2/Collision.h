#pragma once

#include <SFML/Graphics.hpp>

#include "Body.h"

class Collision
{
public:
	Collision(Body* b1, Body* b2);

	Body* b1;
	Body* b2;

	sf::Vector2f normal;

	bool solve();

private:
	bool solveCircleCircle();
	bool solveRectRect();
	bool solveRectCircle();
	void applyImpulse();
};
