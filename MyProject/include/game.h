#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <sstream>

#include "../include/Window.h"
#include "../include/EventManager.h"
#include "../include/StateManager.h"
#include "../include/TextureManager.h"
#include "../include/EntityManager.h"

# define WIN_NAME   "MyRPG"
# define WIN_W 		1920
# define WIN_H 		1080
# define FPS		60

class Game
{
public:
	Game();
	~Game();

	void Update();
	void Render();
	void LateUpdate();

	GameWindow* GetWindow() { return &m_window; };
	sf::Time GetElapsed() { return m_elapsed; };

	void RestartClock() { m_elapsed = m_clock.restart(); };

private:
	SharedContext m_context;
	GameWindow m_window;
	StateManager m_stateManager;
	TextureManager m_textureManager;
	EntityManager m_entityManager;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};
