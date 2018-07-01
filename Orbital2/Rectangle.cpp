#include "Rectangle.h"

Rectangle::Rectangle(float mass, float restitution, sf::Vector2f size) : Body(Shape::RECTANGLE, mass, restitution)
{
	this->size = size;
}

Rectangle::Rectangle() : Rectangle(0, 0, sf::Vector2f(0, 0)) { }

void Rectangle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::RectangleShape drawRect(size);
	states.transform.translate(sf::Vector2f(position.x - size.x / 2, position.y - size.y / 2));
	// Draw vertex array
	target.draw(drawRect, states);

	// Temporary velocity vector
	sf::VertexArray v;
	states.transform.translate(sf::Vector2f(size.x / 2, size.y / 2));
	v.setPrimitiveType(sf::PrimitiveType::Lines);
	v.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red));
	v.append(sf::Vertex(velocity, sf::Color::Red));
	target.draw(v, states);
}

