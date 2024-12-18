#pragma once

#include "BaseState.h"
#include <SFML/Graphics.hpp>

class State_GameOver : public BaseState
{
public:
	State_GameOver(StateManager* l_stateManager);
	~State_GameOver();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();
private:
	sf::Font m_font;
	sf::Text m_text;
	float m_elapsed;
};