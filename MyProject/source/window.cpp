#include "../include/Window.h"

GameWindow::GameWindow(const std::string& l_title, const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}

GameWindow::~GameWindow()
{
	Destroy();
}

void GameWindow::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	m_isFocused = true;
	m_eventManager.AddCallback(StateType(0), "Fullscreen_toggle", &GameWindow::ToggleFullscreen, this);
	m_eventManager.AddCallback(StateType(0), "Window_close", &GameWindow::Close, this);
	Create();
}

void GameWindow::Create()
{
	sf::Uint32 style;
	if (m_isFullscreen)
		style = sf::Style::Fullscreen;
	else
		style = sf::Style::Default;
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
	m_window.setFramerateLimit(60);
}

void GameWindow::Destroy()
{
	m_window.close();
}

void GameWindow::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::LostFocus)
		{
			m_isFocused = false;
			m_eventManager.SetFocus(false);
		}
		else if (event.type == sf::Event::GainedFocus)
		{
			m_isFocused = true;
			m_eventManager.SetFocus(true);
		}
		m_eventManager.HandleEvent(event);
	}
	m_eventManager.Update();
}

void GameWindow::ToggleFullscreen(EventDetails* l_details)
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void GameWindow::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void GameWindow::EndDraw()
{
	m_window.display();
}

bool GameWindow::IsDone()
{
	return m_isDone;
}

bool GameWindow::IsFullscreen()
{
	return m_isFullscreen;
}

sf::Vector2u GameWindow::GetWindowSize()
{
	return m_windowSize;
}

void GameWindow::Draw(sf::Drawable& l_drawable)
{
	m_window.draw(l_drawable);
}

sf::FloatRect GameWindow::GetViewSpace()
{
	sf::Vector2f viewCenter = m_window.getView().getCenter();
	sf::Vector2f viewSize = m_window.getView().getSize();
	sf::Vector2f viewSizeHalf(viewSize.x / 2, viewSize.y / 2);
	sf::FloatRect viewSpace(viewCenter - viewSizeHalf, viewSize);
	return viewSpace;
}