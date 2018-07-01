#include "Game.h"

#include <iostream>

#include "Circle.h"
#include "Collision.h"
#include "Display.h"
#include "Rectangle.h"

#define TIMESTEP 0.025f

Game::Game()
{
	//bodies.push_back(new Circle(1, 0.5, 8));
	//bodies.push_back(new Circle(1, 0.5, 12));

	for (int i = 0; i < 60; i++)
	{
		float size = (rand() % 100) / 10 + 2;
		bodies.push_back(new Circle(3.14 * size * size, 1, size));
		bodies[i]->velocity = sf::Vector2f((rand() % 100) - 50, (rand() % 100) - 50);
		bodies[i]->position = sf::Vector2f(rand() % 600, rand() % 600);
	}

	for (int i = 60; i < 120; i++)
	{
		float width = (rand() % 200) / 10 + 8;
		float height = (rand() % 200) / 10 + 8;
		bodies.push_back(new Rectangle(width * height, 1, sf::Vector2f(width, height)));
		bodies[i]->velocity = sf::Vector2f((rand() % 100) - 50, (rand() % 100) - 50);
		bodies[i]->position = sf::Vector2f(rand() % 600, rand() % 600);
	}

	//bodies.push_back(new Rectangle(1, 1, sf::Vector2f(20, 7)));
	//bodies.push_back(new Rectangle(3, 1, sf::Vector2f(15, 34)));

	//bodies[0]->addForce(sf::Vector2f(600, 600));
	//bodies[1]->position = sf::Vector2f(20, 40);
	//bodies[1]->addForce(sf::Vector2f(-100, 100));

	//bodies[0]->position = sf::Vector2f(100, 100);
	//bodies[1]->position = sf::Vector2f(100, 160);
	//bodies[0]->velocity = sf::Vector2f(0, 40);
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
			Collision collision(bodies[i], bodies[j]);
			if (collision.solve())
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
