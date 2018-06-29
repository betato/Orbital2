#pragma once

#include <SFML/Graphics.hpp>

#include "Body.h"

class Circle : public Body
{
public:
	Circle(float mass, float restitution, float radius);
	Circle();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
