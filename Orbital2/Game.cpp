#include "Game.h"

#include <iostream>

#include "Display.h"

#define TIMESTEP 1

Game::Game()
{
	bodies.push_back(new Circle(1, 0.5, 10));
}

Game::~Game()
{

}

void Game::input(const sf::Event & events)
{
	
}

void Game::update()
{
	for (Body* body : bodies)
	{
		// Collide
		switch (body->shape)
		{
		case Shape::CIRCLE :
			
			break;
		case Shape::RECTANGLE:

			break;
		}
		Display::draw(*body);

		// Move
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
