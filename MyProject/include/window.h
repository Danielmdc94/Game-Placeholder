#pragma once

#include <SFML/Graphics.hpp>
#include "../include/EventManager.h"
#include "../include/StateManager.h"

class GameWindow
{
public:
	GameWindow(const std::string& l_title, const sf::Vector2u& l_size);
	~GameWindow();

	void BeginDraw();
	void EndDraw();
	void Update();

	bool IsDone();
	bool IsFullscreen();

	sf::Vector2u GetWindowSize();
	void Draw(sf::Drawable& l_drawable);

	sf::FloatRect GetViewSpace();

	bool IsFocused() { return m_isFocused; };
	EventManager* GetEventManager() { return &m_eventManager; };
	sf::RenderWindow* GetRenderWindow() { return &m_window; };
	void ToggleFullscreen(EventDetails* l_details);
	void Close(EventDetails* l_details = nullptr) { m_isDone = true; };

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Create();
	void Destroy();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;

	bool m_isDone;
	bool m_isFullscreen;

	EventManager m_eventManager;
	bool m_isFocused;
};
