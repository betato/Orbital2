#pragma once

//#include <SFML/Graphics.hpp>

#include "Body.h"

class Game
{
public:
	Game();
	~Game();

	void input(const sf::Event& events);
	void update();
	void draw();

private:
	std::vector<Body*> bodies;
};
