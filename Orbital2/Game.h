#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void input(const sf::Event& events);
	void update();
	void draw();
private:

};
