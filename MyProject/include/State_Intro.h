#pragma once

#include "../include/BaseState.h"
#include "../include/EventManager.h"
#include "../include/StateManager.h"

class State_Intro : public BaseState
{
public:
	State_Intro(StateManager* l_stateManager) : BaseState(l_stateManager) {}
	void OnCreate() override;
	void OnDestroy() override;
	void Activate() override;
	void Deactivate() override;
	void Update(const sf::Time& l_time) override;
	void Draw() override;

	void Continue(EventDetails* l_details);

private:
	//----TEST----//
	sf::Sprite m_bgSprite;
	sf::Texture m_bgTexture;
	//------------//
	sf::Texture m_introTexture;
	sf::Sprite m_introSprite;
	sf::Font m_font;
	sf::Text m_text;
	float m_timePassed = 0;
};
