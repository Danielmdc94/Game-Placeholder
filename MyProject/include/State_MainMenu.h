#pragma once

#include "../include/BaseState.h"
#include "../include/EventManager.h"
#include "../include/StateManager.h"

class State_MainMenu : public BaseState
{
public:
	State_MainMenu(StateManager* l_stateManager) : BaseState(l_stateManager) {}
	void OnCreate() override;
	void OnDestroy() override;
	void Activate() override;
	void Deactivate() override;
	void Update(const sf::Time& l_time) override;
	void Draw() override;

	void MouseClick(EventDetails* l_details);

private:
	sf::Text m_text;
	sf::Font m_font;

	sf::Vector2f m_buttonSize;
	sf::Vector2f m_buttonPos;
	unsigned int m_buttonPadding = 0;

	sf::RectangleShape m_rects[3];
	sf::Text m_labels[3];
};
