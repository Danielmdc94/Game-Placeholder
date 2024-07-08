#include "../include/enemy.h"
#include "../include/engine.h"

void Enemy::LoadCharacter()
{
	if (!characterTexture.loadFromFile(SKELETON_WALK_ANIM))
	{
		std::cout << "ERROR::ENEMY::Could not load enemy texture!" << "\n";
	}
	characterSprite.setTexture(characterTexture);
	characterSprite.setTextureRect(sf::IntRect(0, 64 * 2, 64, 64));
}

Enemy::Enemy()
{
	LoadCharacter();
}

Enemy::~Enemy()
{
}

void Enemy::SetPosition(const float x, const float y)
{
}

void Enemy::Move(const float dirX, const float dirY)
{
	sf::Vector2f position = characterSprite.getPosition();
	characterSprite.setPosition(position + sf::Vector2f(dirX, dirY));
}

void Enemy::Update(double deltaTime)
{
	characterSprite.setPosition(sf::Vector2f(300, 300));
}
