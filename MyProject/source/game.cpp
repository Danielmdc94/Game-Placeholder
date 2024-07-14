#include "../include/Game.h"

Game::Game() : m_window(WIN_NAME, sf::Vector2u(WIN_W, WIN_H)), m_stateManager(&m_context)
{
	//GetWindow()->GetEventManager()->AddCallback("Move", &Game::MoveSprite, this);
	m_context.m_wind = &m_window;
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

	player.Update(m_elapsed);
	enemy.Update(m_elapsed);
}

void Game::Render()
{
	m_window.BeginDraw();
	m_stateManager.Draw();

	m_window.Draw(*player.GetSprite());
	m_window.Draw(*enemy.GetSprite());

	m_window.EndDraw();
}

void Game::LateUpdate()
{
	m_stateManager.ProcessRequests();
	RestartClock();
}


void Game::MoveSprite(EventDetails* l_details) {
	sf::Vector2i mousepos = GetWindow()->GetEventManager()->GetMousePos(GetWindow()->GetRenderWindow());
	player.GetSprite()->setPosition(mousepos.x, mousepos.y);
	std::cout << "Moving sprite to: " << mousepos.x << ":" << mousepos.y << std::endl;
}