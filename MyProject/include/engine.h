#ifndef ENGINE_H
# define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

# define NAME       "MyRPG"
# define WIN_W 		1920
# define WIN_H 		1080
# define FPS		60

using namespace sf;

class Engine
{
private:
	RenderWindow	window;
	Event			event;
	ContextSettings settings;

	Time			deltaTime;
	Clock			clock;

	void Input(Event event);
	void Update(double deltaTimetInSeconds);
	void Render();

public:
	Engine();

	void Start();
};

#endif