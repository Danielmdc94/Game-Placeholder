#ifndef GAME_H
# define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

#include "../include/Window.h"
#include "../include/Player.h"
#include "../include/Enemy.h"

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

	// Accessors
	GameWindow* GetWindow() { return &m_window; };
	sf::Time GetElapsed() { return m_elapsed; };

	void RestartClock() { m_elapsed = m_clock.restart(); };

	Player player;
	Enemy enemy;

	void MoveSprite(EventDetails* l_details);

private:
	GameWindow m_window;
	sf::Clock m_clock;
	sf::Time m_elapsed;
};

#endif