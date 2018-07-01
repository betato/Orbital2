#include "Collision.h"

Collision::Collision(Body* b1, Body* b2)
{
	this->b1 = b1;
	this->b2 = b2;
}

bool Collision::solve()
{
	if (b1->shape == Shape::CIRCLE && b2->shape == Shape::CIRCLE)
	{
		if (!solveCircleCircle())
		{
			return false;
		}
	}
	else if (b1->shape == Shape::RECTANGLE && b2->shape == Shape::RECTANGLE)
	{
		if (!solveRectRect())
		{
			return false;
		}
	}
	else
	{
		if (!solveRectCircle())
		{
			return false;
		}
	}
	// If bodies have collided, apply impulse
	applyImpulse();
	return true;
}

bool Collision::solveCircleCircle()
{
	float a = b1->position.x - b2->position.x;
	float b = b1->position.y - b2->position.y;
	float c = b1->radius + b2->radius;
	float separationSquared = a * a + b * b;
	
	if (c * c > separationSquared) // a^2 + b^2 = c^2
	{
		float distance = std::sqrt(separationSquared);

		if (distance != 0)
		{
			// Get unit normal
			normal = sf::Vector2f(a, b) / distance;
		}
		else
		{
			// Body centers overlapped, choose random unit normal
			normal = sf::Vector2f(1, 0);
		}
		return true;
	}
	return false;
}

bool Collision::solveRectRect()
{
	float xOverlap = (b1->size.x + b2->size.x) / 2 - std::abs(b1->position.x - b2->position.x);
	if (xOverlap > 0)
	{
		float yOverlap = (b1->size.y + b2->size.y) / 2 - std::abs(b1->position.y - b2->position.y);
		if (yOverlap > 0)
		{
			if (yOverlap > xOverlap)
			{
				// Colliding in x axis
				if (b1->position.x > b2->position.x)
				{
					normal = sf::Vector2f(1, 0);
				}
				else
				{
					normal = sf::Vector2f(-1, 0);
				}
			}
			else
			{
				// Colliding in y axis
				if (b1->position.y > b2->position.y)
				{
					normal = sf::Vector2f(0, 1);
				}
				else
				{
					normal = sf::Vector2f(0, -1);
				}
			}
			return true;
		}
	}
	return false;
}

bool Collision::solveRectCircle()
{
	return false;
}

void Collision::applyImpulse()
{
	sf::Vector2f relativeVelocity = b2->velocity - b1->velocity;
	float collisionVelocity = relativeVelocity.x * normal.x + relativeVelocity.y * normal.y;
	float restitution = std::min(b1->restitution, b2->restitution);

	if (collisionVelocity < 0)
	{
		// Bodies already moving apart
		return;
	}

	// Apply change in velocity
	sf::Vector2f vm = -(collisionVelocity * (restitution + 1) / (b1->mass + b2->mass)) * normal;
	b1->velocity -= vm * b2->mass;
	b2->velocity += vm * b1->mass; 
}
