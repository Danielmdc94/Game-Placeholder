#include "../include/State_Intro.h"

void State_Intro::OnCreate()
{
	m_timePassed = 0.0f;
	sf::Vector2u windowSize = m_stateManager->GetContext()->m_window->GetRenderWindow()->getSize();

	TextureManager* textureManager = m_stateManager->GetContext()->m_textureManager;

	textureManager->RequireResource("Bg1");
	m_bgSprite.setTexture(*textureManager->GetResource("Bg1"));
	m_bgSprite.setOrigin(textureManager->GetResource("Bg1")->getSize().x / 2.0f, textureManager->GetResource("Bg1")->getSize().y / 2.0f);
	m_introSprite.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

	textureManager->RequireResource("Intro");
	m_introSprite.setTexture(*textureManager->GetResource("Intro"));
	m_introSprite.setOrigin(textureManager->GetResource("Intro")->getSize().x / 2.0f, textureManager->GetResource("Intro")->getSize().y / 2.0f);
	m_introSprite.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

	//----TEST----//
	sf::Vector2u textureSize = textureManager->GetResource("Bg1")->getSize();
	float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
	float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
	m_bgSprite.setScale(scaleX, scaleY);
	//------------//

	m_font.loadFromFile(Utils::GetResourceDirectory() + "Media/Fonts/chary___.ttf");
	m_text.setFont(m_font);
	m_text.setString({ "Press SPACE to continue" });
	m_text.setCharacterSize(24);
	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

	EventManager* eventManager = m_stateManager->GetContext()->m_eventManager;
	eventManager->AddCallback(StateType::Intro, "Intro_Continue", &State_Intro::Continue, this);
}

void State_Intro::OnDestroy()
{
	EventManager* eventManager = m_stateManager->GetContext()->m_eventManager;
	eventManager->RemoveCallback(StateType::Intro, "Intro_Continue");
}

void State_Intro::Update(const sf::Time& l_deltaTime)
{
	if (m_timePassed < 5.0f)
	{
		m_timePassed += l_deltaTime.asSeconds();
		m_introSprite.setPosition(m_introSprite.getPosition().x, m_introSprite.getPosition().y + (48 * l_deltaTime.asSeconds()));
	}
}

void State_Intro::Draw()
{
	sf::RenderWindow* window = m_stateManager->GetContext()->m_window->GetRenderWindow();
	//----TEST----//
	window->draw(m_bgSprite);
	//------------//
	window->draw(m_introSprite);
	if (m_timePassed >= 5.0f)
		window->draw(m_text);
}

void State_Intro::Continue(EventDetails* l_details)
{
	if (m_timePassed >= 5.0f)
	{
		m_stateManager->SwitchTo(StateType::MainMenu);
		m_stateManager->Remove(StateType::Intro);
	}
}

void State_Intro::Activate() {}

void State_Intro::Deactivate() {}
