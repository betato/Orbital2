#include "Game.h"

#include <iostream>

#include "Display.h"

#define TIMESTEP 0.025

Game::Game()
{
	bodies.push_back(new Circle(1, 0.5, 10));
	bodies[0]->addForce(sf::Vector2f(-2, 2));
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
		for (size_t j = i; j < bodies.size(); j++)
		{
			if (bodies[i]->shape == Shape::CIRCLE && bodies[j]->shape == Shape::CIRCLE)
			{

			}
			else if (bodies[i]->shape == Shape::RECTANGLE && bodies[j]->shape == Shape::RECTANGLE)
			{

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
