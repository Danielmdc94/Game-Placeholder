#include "../include/game.h"

Game::Game() : m_window(WIN_NAME, sf::Vector2u(WIN_W, WIN_H))
{

}

Game::~Game()
{

}

void Game::HandleInput()
{

}

void Game::Update()
{
	m_window.Update();
}

void Game::Render()
{
	m_window.BeginDraw();

	m_window.Draw(*player.GetSprite());

	m_window.Draw(*enemy.GetSprite());

	m_window.EndDraw();
}

GameWindow* Game::GetWindow()
{
	return &m_window;
}

sf::Time Game::GetElapsed()
{
	return m_elapsed;
}

void Game::RestartClock()
{
	m_elapsed = m_clock.restart();
}
