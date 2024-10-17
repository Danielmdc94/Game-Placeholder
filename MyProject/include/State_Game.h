#pragma once

#include "../include/BaseState.h"
#include "../include/EventManager.h"
#include "../include/StateManager.h"
#include "../include/Map.h"

class State_Game : public BaseState
{
public:
	State_Game(StateManager* l_stateManager) : BaseState(l_stateManager) {}
	void OnCreate() override;
	void OnDestroy() override;
	void Activate() override;
	void Deactivate() override;
	void Update(const sf::Time& l_deltaTime) override;
	void Draw() override;

	void MainMenu(EventDetails* l_details);
	void Pause(EventDetails* l_details);

private:
	Map* m_gameMap;
};
