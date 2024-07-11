#include "../include/player.h"
#include "../include/game.h"

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

void Player::Update(sf::Time deltaTime)
{
	float speed = 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		speed = 2.5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		Move(0, -speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		Move(-speed, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		Move(0, speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		Move(speed, 0);
}
