#pragma once

//#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable
{
public:
	const Shape shape;

	float mass;
	float restitution;

	sf::Vector2f force;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f position;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

protected:
	Body(const Shape shape, float mass, float restitution);

};

enum Shape
{
	CIRCLE,
	RECTANGLE
};
