#include "../include/Game.h"

Game::Game() : m_window(WIN_NAME, sf::Vector2u(WIN_W, WIN_H)), m_stateManager(&m_context)
{
	m_context.m_window = &m_window;
	m_context.m_eventManager = m_window.GetEventManager();
	m_stateManager.SwitchTo(StateType::Intro);
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
	m_stateManager.Update(m_elapsed);
}

void Game::Render()
{
	m_window.BeginDraw();
	m_stateManager.Draw();
	m_window.EndDraw();
} 

void Game::LateUpdate()
{
	m_stateManager.ProcessRequests();
	RestartClock();
}
