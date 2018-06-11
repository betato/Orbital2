#include "Circle.h"



Circle::Circle(float mass, float restitution, float radius) : Body(mass, restitution)
{
	this->radius = radius;
}

void Circle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::CircleShape drawCircle(radius);
	states.transform.translate(sf::Vector2f(position.x - radius, -position.y - radius));
	// Draw vertex array
	target.draw(drawCircle, states);
}
