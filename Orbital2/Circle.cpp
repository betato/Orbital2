#include "Circle.h"

Circle::Circle(float mass, float restitution, float radius) : Body(Shape::CIRCLE, mass, restitution)
{
	this->radius = radius;
}

Circle::Circle() : Circle(0, 0, 0) { }

void Circle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::CircleShape drawCircle(radius);
	states.transform.translate(sf::Vector2f(position.x - radius, position.y - radius));
	// Draw vertex array
	target.draw(drawCircle, states);

	// Temporary velocity vector
	sf::VertexArray v;
	states.transform.translate(sf::Vector2f(radius, radius));
	v.setPrimitiveType(sf::PrimitiveType::Lines);
	v.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red));
	v.append(sf::Vertex(velocity, sf::Color::Red));
	target.draw(v, states);
}
