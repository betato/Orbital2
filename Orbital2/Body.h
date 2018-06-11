#pragma once

#include <SFML/System/Vector2.hpp>

class Body
{
public:
	float mass;
	float restitution;

	sf::Vector2f force;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f position;

protected:
	Body(float mass, float restitution);

};
