#include "Rectangle.h"

Rectangle::Rectangle(float mass, float restitution, sf::Vector2f size) : Body(Shape::RECTANGLE, mass, restitution)
{
	this->size = size;
}

Rectangle::Rectangle() : Rectangle(0, 0, sf::Vector2f(0, 0)) { }

void Rectangle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::RectangleShape drawRect(size);
	states.transform.translate(sf::Vector2f(position.x - size.x * 0.5f, position.y - size.y * 0.5f));
	// Draw vertex array
	target.draw(drawRect, states);

	// Temporary velocity vector
	sf::VertexArray v;
	states.transform.translate(sf::Vector2f(size.x * 0.5f, size.y * 0.5f));
	v.setPrimitiveType(sf::PrimitiveType::Lines);
	v.append(sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red));
	v.append(sf::Vertex(velocity, sf::Color::Red));
	target.draw(v, states);
}

