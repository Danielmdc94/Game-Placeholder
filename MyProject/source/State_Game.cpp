#include "../include/State_Game.h"

void State_Game::OnCreate()
{
	m_texture.loadFromFile("./assets/ThirdParty/lpc_entry/png/walkcycle/BODY_skeleton.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 64 * 2, 64, 64));
	m_sprite.setPosition(0, 0);
	m_increment = sf::Vector2f(400.0f, 400.0f);

	EventManager* eventManager = m_stateManager->GetContext()->m_eventManager;
	eventManager->AddCallback(StateType::Game, "Key_Escape", &State_Game::MainMenu, this);
	eventManager->AddCallback(StateType::Game, "Key_P", &State_Game::Pause, this);
	eventManager->AddCallback(StateType(0), "Move", &State_Game::MovePlayerToMouse, this);

	//----TEST----//
	sf::Vector2u windowSize = m_stateManager->GetContext()->m_window->GetRenderWindow()->getSize();
	m_bgTexture.loadFromFile("./assets/ThirdParty/LPC_forest/LPC_forest/preview.png");
	m_bgSprite.setTexture(m_bgTexture);
	sf::Vector2u textureSize = m_bgTexture.getSize();
	float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
	float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
	m_bgSprite.setScale(scaleX, scaleY);
	//------------//
}

void State_Game::OnDestroy()
{
	EventManager* eventManager = m_stateManager->GetContext()->m_eventManager;
	eventManager->RemoveCallback(StateType::Game, "Key_Escape");
	eventManager->RemoveCallback(StateType::Game, "Key_P");
}

void State_Game::Update(const sf::Time& l_deltaTime)
{
	//----TEST----//
	player.Update(l_deltaTime);
	enemy.Update(l_deltaTime);
	//------------//
	sf::Vector2u l_windSize = m_stateManager->GetContext()->m_window->GetWindowSize();
	sf::Vector2u l_textSize = m_texture.getSize();

	if ((m_sprite.getPosition().x > l_windSize.x - l_textSize.x && m_increment.x > 0) || (m_sprite.getPosition().x < 0 && m_increment.x < 0))
		m_increment.x = -m_increment.x;
	if ((m_sprite.getPosition().y > l_windSize.y - l_textSize.y && m_increment.y > 0) || (m_sprite.getPosition().y < 0 && m_increment.y < 0))
		m_increment.y = -m_increment.y;

	m_sprite.setPosition(m_sprite.getPosition().x + (m_increment.x * l_deltaTime.asSeconds()), m_sprite.getPosition().y + (m_increment.y * l_deltaTime.asSeconds()));
}

void State_Game::Draw()
{
	sf::RenderWindow* window = m_stateManager->GetContext()->m_window->GetRenderWindow();
	//----TEST----//
	window->draw(m_bgSprite);
	//------------//

	window->draw(m_sprite);

	//----TEST----//
	window->draw(*player.GetSprite());
	window->draw(*enemy.GetSprite());
	//------------//
}

void State_Game::MainMenu(EventDetails* l_details)
{
	m_stateManager->SwitchTo(StateType::MainMenu);
}
void State_Game::Pause(EventDetails* l_details)
{
	m_stateManager->SwitchTo(StateType::Paused);
}

void State_Game::Activate() {}

void State_Game::Deactivate() {}

//----TEST----//
void State_Game::MovePlayerToMouse(EventDetails* l_details)
{
	sf::Vector2i mousePos = l_details->m_mouse;
	player.GetSprite()->setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	std::cout << "Moving sprite to: " << mousePos.x << ":" << mousePos.y << std::endl;
}
//------------//