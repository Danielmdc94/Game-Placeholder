#pragma once

#ifndef PLAYER_H
# define PLAYER_H
#include <SFML/Graphics.hpp>

#define CHARACTER_WALK_ANIM "./assets/ThirdParty/lpc_entry/png/walkcycle/BODY_male.png"

class Player
{

public:
	Player();
	~Player();

	// Accessors
	sf::Sprite*	GetSprite() { return &this->characterSprite; }

	// Modifiers
	void		SetPosition(const float x, const float y);

	// Update functions
	void		Move(const float dirX, const float dirY);
	void		Update(sf::Time deltaTime);

private:

	sf::Sprite characterSprite;
	sf::Texture characterTexture;

	void		LoadCharacter();
};

#endif