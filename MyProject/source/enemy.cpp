#include "../include/Enemy.h"
#include "../include/Game.h"

void Enemy::LoadCharacter()
{
	if (!characterTexture.loadFromFile(SKELETON_WALK_ANIM))
	{
		std::cout << "ERROR::ENEMY::Could not load enemy texture!" << "\n";
	}
	characterSprite.setTexture(characterTexture);
	characterSprite.setTextureRect(sf::IntRect(0, 64 * 2, 64, 64));
	characterSprite.setOrigin(static_cast<float>(characterSprite.getTextureRect().width / 2), static_cast<float>(characterSprite.getTextureRect().height / 2));
	characterSprite.setPosition(sf::Vector2f(WIN_W / 2, WIN_H / 2));
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

void Enemy::Update(sf::Time deltaTime)
{
	if ((characterSprite.getPosition().x + (characterSprite.getTextureRect().width / 2) > WIN_W && increment.x > 0) || (characterSprite.getPosition().x - (characterSprite.getTextureRect().width / 2) < 0 && increment.x < 0))
		increment.x = -increment.x;
	if ((characterSprite.getPosition().y + (characterSprite.getTextureRect().height / 2) > WIN_H && increment.y > 0) || (characterSprite.getPosition().y - (characterSprite.getTextureRect().height / 2) < 0 && increment.y < 0))
		increment.y = -increment.y;
	characterSprite.setPosition(characterSprite.getPosition() + increment);
}
