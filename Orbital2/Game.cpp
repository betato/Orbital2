#include "Game.h"

#include <iostream>

#include "Circle.h"
#include "Collision.h"
#include "Display.h"
#include "Rectangle.h"

#define TIMESTEP 0.025f

Game::Game()
{
	bodies.push_back(new Circle(1, 0.5, 8));
	bodies.push_back(new Circle(1, 0.5, 12));

	//bodies.push_back(new Rectangle(1, 0.5, sf::Vector2f(12, 22)));
	//bodies.push_back(new Rectangle(1, 0.5, sf::Vector2f(12, 22)));

	bodies[0]->addForce(sf::Vector2f(600, 600));
	bodies[1]->position = sf::Vector2f(20, 40);
	bodies[1]->addForce(sf::Vector2f(-100, 100));

	//bodies[2]->position = sf::Vector2f(100, 100);
	//bodies[3]->position = sf::Vector2f(90, 110);
	//bodies[3]->addForce(sf::Vector2f(-100, 100));
}

Game::~Game()
{

}

void Game::input(const sf::Event & events)
{
	
}

void Game::update()
{
	// Check Collisions
	for (std::size_t i = 0; i < bodies.size(); i++)
	{
		for (size_t j = i + 1; j < bodies.size(); j++)
		{
			if (bodiesColliding(bodies[i], bodies[j]))
			{
				std::cout << "collision between bodies " << i << " and " << j << std::endl;
			}
		}
	}

	// Move
	for (Body* body : bodies)
	{
		body->move(TIMESTEP);
	}
}

void Game::draw()
{
	for (Body* body : bodies)
	{
		Display::draw(*body);
	}
}

bool Game::bodiesColliding(Body* b1, Body* b2)
{
	if (b1->shape == Shape::CIRCLE && b2->shape == Shape::CIRCLE)
	{
		// Circle-Circle Collision
		float a = b1->position.x - b2->position.x;
		float b = b1->position.y - b2->position.y;
		float c = b1->radius + b2->radius;
		float separationSquared = a * a + b * b;
		// a^2 + b^2 = c^2
		if (c * c > separationSquared)
		{
			float distance = std::sqrt(separationSquared);
			sf::Vector2f normal;
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

			sf::Vector2f relativeVelocity = b2->velocity - b1->velocity;
			float collisionVelocity = relativeVelocity.x * normal.x + relativeVelocity.y * normal.y;
			float restitution = std::min(b1->restitution, b2->restitution);

			if (collisionVelocity < 0)
			{
				// Bodies already moving apart
				return true;
			}

			// Apply change in velocity
			sf::Vector2f vm = -(collisionVelocity * (restitution + 1) / (b1->mass + b2->mass)) * normal;
			b1->velocity -= vm * b2->mass;
			b2->velocity += vm * b1->mass;

			return true;
		}
		return false;
	}
	else if (b1->shape == Shape::RECTANGLE && b2->shape == Shape::RECTANGLE)
	{
		// Rectangle-Rectangle Collision
		return b1->position.x < b2->position.x + b2->size.x &&
			b1->position.x + b1->size.x > b2->position.x &&
			b1->position.y < b2->position.y + b2->size.y &&
			b1->size.x + b1->position.y > b2->position.y;
	}
	else
	{
		// Circle-Rectangle or Rectangle-Circle Collision
		return false;
	}
}
