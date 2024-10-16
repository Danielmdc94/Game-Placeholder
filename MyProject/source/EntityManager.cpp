#include "../include/EntityManager.h"

EntityManager::EntityManager(SharedContext* l_context,
	unsigned int l_maxEntities) :m_context(l_context),
	m_maxEntities(l_maxEntities), m_idCounter(0)
{
	LoadEnemyTypes("EnemyList.list");
	RegisterEntity<Player>(EntityType::Player);
	RegisterEntity<Enemy>(EntityType::Enemy);
}

EntityManager::~EntityManager()
{
	Purge();
}
