#include "Game.h"

#include <iostream>

#include "Display.h"

#define TIMESTEP 0.025

Game::Game()
{
	bodies.push_back(new Circle(1, 0.5, 8));
	bodies.push_back(new Circle(1, 0.5, 12));
	bodies[0]->addForce(sf::Vector2f(-200, 200));
	bodies[1]->position = sf::Vector2f(20, -40);
	bodies[1]->addForce(sf::Vector2f(100, 100));

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
			if (bodiesColliding(*bodies[i], *bodies[j]))
			{
				std::cout << "!!! collision !!!" << std::endl;
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

bool Game::bodiesColliding(Body& b1, Body& b2)
{
	if (b1.shape == Shape::CIRCLE && b2.shape == Shape::CIRCLE)
	{
		// Circle/Circle Collision
		float a = b1.position.y - b2.position.y;
		float b = b1.position.x - b2.position.x;
		float c = b1.radius + b2.radius;
		return c * c > a * a + b * b;
	}
	else if (b1.shape == Shape::RECTANGLE && b2.shape == Shape::RECTANGLE)
	{
		// Rectangle/Rectangle Collision
		return b1.position.x < b2.position.x + b2.width &&
			b1.position.x + b1.width > b2.position.x &&
			b1.position.y < b2.position.y + b2.height &&
			b1.height + b1.position.y > b2.position.y;
	}
	else
	{
		// Circle/Rectangle or Rectangle/Circle Collision

	}
}
