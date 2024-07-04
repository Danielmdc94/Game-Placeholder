#ifndef ENGINE_H
# define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <sstream>

# define NAME               "MyProject"
# define WIN_W 				1920
# define WIN_H 				1080

using namespace sf;

class Engine
{
private:
	RenderWindow	window;
	Event			event;

	Time			deltaTime;
	Clock			clock;

	void input(Event event);
	void update(double deltaTimetInSeconds);
	void render();

public:
	Engine();

	void start();
};

#endif