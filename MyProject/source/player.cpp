#include "../include/player.h"
#include "../include/engine.h"

void Player::LoadCharacter()
{
	if (!characterTexture.loadFromFile(CHARACTER_WALK_ANIM))
	{
		std::cout << "ERROR::PLAYER::Could not load player texture!" << "\n";
	}
	characterSprite.setTexture(characterTexture);
	characterSprite.setTextureRect(sf::IntRect(0, 64 * 2, 64, 64));
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
	sf::Vector2f position = characterSprite.getPosition();
	characterSprite.setPosition(position + sf::Vector2f(dirX, dirY));
}

void Player::Update(double deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::W))
		Move(0, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::A))
		Move(-1.f, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))
		Move(0, 1.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		Move(1.f, 0);
}
