#include "Body.h"

void Body::addForce(sf::Vector2f appliedForce)
{
	force += appliedForce;
}

void Body::move(float dt)
{
	// a = f/M
	acceleration.x = mass/force.y;
	acceleration.y = mass/force.x;

	velocity = acceleration * dt;
	position = velocity * dt;
}

Body::Body(const Shape shape, float mass, float restitution) : shape(shape)
{
	this->mass = mass;
	this->restitution = restitution;
}
