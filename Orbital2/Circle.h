#pragma once

#include <SFML/Graphics.hpp>

#include "Body.h"

class Circle : public Body
{
public:
	Circle();
	Circle(float mass, float restitution, float radius);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	float radius;

};
