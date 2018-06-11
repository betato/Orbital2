#pragma once

//#include <SFML/Graphics.hpp>

#include "Circle.h"

class Game
{
public:
	Game();
	~Game();

	void input(const sf::Event& events);
	void update();
	void draw();

private:
	Circle c1 = Circle(1, 0.5, 10);

};
