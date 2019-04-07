#include "Body.h"

void Body::addForce(sf::Vector2f appliedForce)
{
	force += appliedForce;
}

void Body::move(float dt)
{
	// a = f/M
	acceleration.x = force.x / mass;
	acceleration.y = force.y / mass;
	force = sf::Vector2f(0, 0);

	velocity += acceleration * dt;
	position += velocity * dt;
}

Body::Body(const Shape shape, float mass, float restitution) : shape(shape)
{
	this->mass = mass;
	this->restitution = restitution;
}
