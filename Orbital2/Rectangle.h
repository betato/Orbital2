#pragma once

#include "Body.h"

class Rectangle : public Body 
{
public:
	Rectangle(float mass, float restitution, sf::Vector2f size);
	Rectangle();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

