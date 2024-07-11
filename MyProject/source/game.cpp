#include "../include/Game.h"

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
	player.Update(m_elapsed);
	enemy.Update(m_elapsed);
}

void Game::Render()
{
	m_window.BeginDraw();

	m_window.Draw(*player.GetSprite());

	m_window.Draw(*enemy.GetSprite());

	m_window.EndDraw();
}
