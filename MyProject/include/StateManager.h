#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>

#include "../include/BaseState.h"
#include "../include/EventManager.h"
#include "../include/window.h"

enum class StateType
{
	Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};

struct SharedContext
{
	SharedContext() :m_wind(nullptr), m_eventManager(nullptr) {}
	GameWindow* m_wind;
	EventManager* m_eventManager;
};

using StateContainer = std::vector<std::pair<StateType, BaseState*>>;

using TypeContainer = std::vector<StateType>;

using StateFactory = std::unordered_map<StateType, std::function<BaseState* (void)>>;

class StateManager
{
public:
	StateManager(SharedContext* l_shared);
	~StateManager();
	void Update(const sf::Time& l_time);
	void Draw();
	void ProcessRequests();
	SharedContext* GetContext();
	bool HasState(const StateType& l_type);
	void SwitchTo(const StateType& l_type);
	void Remove(const StateType& l_type);

private:
	void CreateState(const StateType& l_type);
	void RemoveState(const StateType& l_type);

	template<class T>
	void RegisterState(const StateType& l_type)
	{
		m_stateFactory[l_type] = [this]() -> BaseState* { return new T(this); };
	}

	SharedContext* m_shared;
	StateContainer m_states;
	TypeContainer m_toRemove;
	StateFactory m_stateFactory;
};
