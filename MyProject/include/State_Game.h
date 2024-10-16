#pragma once

#include "../include/BaseState.h"
#include "../include/EventManager.h"
#include "../include/StateManager.h"

class State_Game : public BaseState
{
public:
	State_Game(StateManager* l_stateManager) : BaseState(l_stateManager) {}
	void OnCreate() override;
	void OnDestroy() override;
	void Activate() override;
	void Deactivate() override;
	void Update(const sf::Time& l_time) override;
	void Draw() override;

	void MainMenu(EventDetails* l_details);
	void Pause(EventDetails* l_details);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_increment;
};
