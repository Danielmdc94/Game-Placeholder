#include "../include/State_GameOver.h"
#include "../include/StateManager.h"

State_GameOver::State_GameOver(StateManager* l_stateManager)
	: BaseState(l_stateManager) {}

State_GameOver::~State_GameOver() {}

void State_GameOver::OnCreate()
{
	m_elapsed = 0;
	m_font.loadFromFile(Utils::GetResourceDirectory() + "Media/Fonts/arial.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(16);
	m_text.setString("You beat the game! Congratulations!");
	m_text.setFillColor(sf::Color::White);
	m_text.setOrigin(m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2);
	m_text.setPosition(400, 300);

	m_stateManager->Remove(StateType::Game);
}

void State_GameOver::OnDestroy() {}

void State_GameOver::Activate() {}
void State_GameOver::Deactivate() {}

void State_GameOver::Update(const sf::Time& l_time)
{
	m_elapsed += l_time.asSeconds();
	if (m_elapsed >= 5.0f)
	{
		m_stateManager->Remove(StateType::GameOver);
		m_stateManager->SwitchTo(StateType::MainMenu);
	}
}

void State_GameOver::Draw()
{
	sf::RenderWindow* window = m_stateManager->GetContext()->m_window->GetRenderWindow();
	window->draw(m_text);
}