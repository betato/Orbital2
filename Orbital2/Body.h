#pragma once

//#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable
{
public:
	float mass;
	float restitution;

	sf::Vector2f force;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f position;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

protected:
	Body(float mass, float restitution);

};
