#pragma once

//#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

enum Shape
{
	CIRCLE,
	RECTANGLE
};

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

	void addForce(sf::Vector2f appliedForce);
	void move(float dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

protected:
	Body(const Shape shape, float mass, float restitution);

};
