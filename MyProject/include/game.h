#ifndef GAME_H
# define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

#include "../include/window.h"
#include "../include/player.h"
#include "../include/enemy.h"

# define WIN_NAME   "MyRPG"
# define WIN_W 		1920
# define WIN_H 		1080
# define FPS		60

class Game
{
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void Render();
	GameWindow* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();

	Player player;
	Enemy enemy;

private:
	GameWindow m_window;
	sf::Clock m_clock;
	sf::Time m_elapsed;
};

#endif