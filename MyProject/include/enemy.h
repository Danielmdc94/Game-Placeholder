#pragma once

#include "../include/Character.h"

class Enemy : public Character
{
public:
	Enemy(EntityManager* l_entityMgr);
	~Enemy();

	void OnEntityCollision(EntityBase* l_collider, bool l_attack);
	void Update(float l_deltaTime);

private:
	sf::Vector2f m_destination;
	bool m_hasDestination;
};