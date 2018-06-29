#include "Rectangle.h"

Rectangle::Rectangle(float mass, float restitution, sf::Vector2f size) : Body(Shape::RECTANGLE, mass, restitution)
{
	this->size = size;
}

Rectangle::Rectangle() : Rectangle(0, 0, sf::Vector2f(0, 0)) { }

void Rectangle::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::RectangleShape drawRect(size);
	states.transform.translate(sf::Vector2f(position.x - size.x * 0.5, position.y - size.y * 0.5));
	// Draw vertex array
	target.draw(drawRect, states);
}

