#pragma once

#ifndef WINDOW_H
# define WINDOW_H

#include <SFML/Graphics.hpp>
#include "../include/EventManager.h"

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

	bool IsFocused() { return m_isFocused; };
	EventManager* GetEventManager() { return &m_eventManager; };
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

#endif