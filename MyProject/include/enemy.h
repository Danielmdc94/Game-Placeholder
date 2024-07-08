#pragma once

#ifndef ENEMY_H
# define ENEMY_H
#include <SFML/Graphics.hpp>
#include <cmath>

#define SKELETON_WALK_ANIM		"./assets/ThirdParty/lpc_entry/png/walkcycle/BODY_skeleton.png"

class Enemy
{
private:

	sf::Sprite	characterSprite;
	sf::Texture	characterTexture;

	sf::Vector2f increment = sf::Vector2f(2.f, 2.f);

	void		LoadCharacter();

public:
	Enemy();
	~Enemy();

	// Accessors
	sf::Sprite	GetSprite() { return this->characterSprite; }

	// Modifiers
	void		SetPosition(const float x, const float y);

	// Update functions
	void		Move(const float dirX, const float dirY);
	void		Update(double deltaTime);
};

#endif