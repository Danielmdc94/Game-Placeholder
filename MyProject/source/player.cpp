#include "../include/player.h"
#include "../include/engine.h"

void Player::LoadCharacter()
{
	if (!characterTexture.loadFromFile(CHARACTER_WALK_ANIM))
	{
		std::cout << "ERROR::PLAYER::Could not load player texture!" << "\n";
	}
	characterSprite.setTexture(characterTexture);
	characterSprite.setTextureRect(sf::IntRect(0, 64 * 3, 64, 64));
}

Player::Player()
{
	LoadCharacter();
}

Player::~Player()
{
}

void Player::SetPosition(const float x, const float y)
{
}

void Player::Move(const float dirX, const float dirY)
{
}

void Player::Update(double deltaTime)
{
}
