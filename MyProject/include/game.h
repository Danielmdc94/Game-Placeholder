#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

#include "../include/Window.h"
#include "../include/StateManager.h"

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
	void LateUpdate();

	GameWindow* GetWindow() { return &m_window; };
	sf::Time GetElapsed() { return m_elapsed; };

	void RestartClock() { m_elapsed = m_clock.restart(); };

private:
	GameWindow m_window;
	StateManager m_stateManager;
	SharedContext m_context;
	sf::Clock m_clock;
	sf::Time m_elapsed;
};
