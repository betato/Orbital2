#pragma once

#include "Game.h"

class Application
{
public:
	Application(int frameCap, int updateCap);
	void runLoop();

private:
	int updateRate;
	Game game;
};
