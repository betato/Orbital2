#include "Application.h"

#include <iostream>

#include "Display.h"

Application::Application(int frameCap, int updateCap)
{
	Display::init(frameCap, 1280, 720, "Window");
	updateRate = updateCap;
}

void Application::runLoop()
{
	sf::Time delta = sf::Time::Zero;
	sf::Time updateTime = sf::microseconds(1000000 / updateRate);
	bool render = false;

	int frameCount = 0;
	int updateCount = 0;

	int fps = 0;
	int ups = 0;

	sf::Clock updateClock;
	sf::Clock counterClock;

	while (Display::isOpen())
	{
		if (counterClock.getElapsedTime() >= sf::seconds(1)) {
			fps = frameCount;
			ups = updateCount;
			frameCount = 0;
			updateCount = 0;

			std::cout << " FPS: " << fps;
			std::cout << " UPS: " << ups << std::endl;

			counterClock.restart();
		}

		while (delta >= updateTime) {
			delta -= updateTime;
			updateCount++;
			render = true;

			// Update
			Display::checkEvents(game);	// Window and game input
			game.update();				// Update
		}

		if (render) {
			frameCount++;

			// Render
			Display::clear();		// Clear
			game.draw();			// Draw
			Display::display();		// Display
		}

		delta += updateClock.restart();
	}
}