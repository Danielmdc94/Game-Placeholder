#pragma once

#include "../include/Window.h"
#include "../include/EventManager.h"
#include "../include/TextureManager.h"
#include "../include/EntityManager.h"
//#include "../include/DebugOverlay.h"

class Map;
struct SharedContext
{
	SharedContext() :
		m_window(nullptr),
		m_eventManager(nullptr),
		m_textureManager(nullptr),
		m_entityManager(nullptr),
		m_gameMap(nullptr) {}

	GameWindow* m_window;
	EventManager* m_eventManager;
	TextureManager* m_textureManager;
	EntityManager* m_entityManager;
	Map* m_gameMap;
	//DebugOverlay m_debugOverlay;
};