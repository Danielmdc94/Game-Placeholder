#include "../include/State_Paused.h"

void State_Paused::OnCreate()
{
	SetTransparent(true);
	m_font.loadFromFile("./assets/test/font/chary___.ttf");
	m_text.setFont(m_font);
	m_text.setString(sf::String("PAUSED"));
	m_text.setCharacterSize(64);
	m_text.setStyle(sf::Text::Bold);

	sf::Vector2u windowSize = m_stateManager->GetContext()->m_window->GetRenderWindow()->getSize();

	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

	m_rect.setSize(sf::Vector2f(windowSize));
	m_rect.setPosition(0, 0);
	m_rect.setFillColor(sf::Color(0, 0, 0, 150));

	EventManager* eventManager = m_stateManager->GetContext()->m_eventManager;
	eventManager->AddCallback(StateType::Paused, "Key_P", &State_Paused::Unpause, this);
}

void State_Paused::OnDestroy()
{
	EventManager* eventManager = m_stateManager->GetContext()->m_eventManager;
	eventManager->RemoveCallback(StateType::Paused, "Key_P");
}

void State_Paused::Draw()
{
	sf::RenderWindow* wind = m_stateManager->GetContext()->m_window->GetRenderWindow();
	wind->draw(m_rect);
	wind->draw(m_text);
}

void State_Paused::Unpause(EventDetails* l_details)
{
	m_stateManager->SwitchTo(StateType::Game);
}

void State_Paused::Update(const sf::Time& l_deltaTime) {}

void State_Paused::Activate() {}

void State_Paused::Deactivate() {}