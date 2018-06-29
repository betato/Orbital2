#include "Body.h"

Body::Body(const Shape shape, float mass, float restitution) : shape(shape)
{
	this->mass = mass;
	this->restitution = restitution;
}
