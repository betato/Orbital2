#include "Game.h"

#include <iostream>

#include "Display.h"

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
		switch (body->shape)
		{
		case Shape::CIRCLE :
			
			break;
		}
		Display::draw(*body);
	}
}

void Game::draw()
{
	for (Body* body : bodies)
	{
		Display::draw(*body);
	}
}
