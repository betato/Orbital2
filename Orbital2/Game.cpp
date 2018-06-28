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

}

void Game::draw()
{
	Display::draw(*bodies[0]);
}
