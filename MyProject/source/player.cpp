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
	float speed = 1.f;
	if (Keyboard::isKeyPressed(Keyboard::LShift))
		speed = 2.5;
	if (Keyboard::isKeyPressed(Keyboard::W))
		Move(0, -speed);
	if (Keyboard::isKeyPressed(Keyboard::A))
		Move(-speed, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))
		Move(0, speed);
	if (Keyboard::isKeyPressed(Keyboard::D))
		Move(speed, 0);
}
