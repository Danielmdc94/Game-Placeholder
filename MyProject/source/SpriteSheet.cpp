#include "../include/SpriteSheet.h"
#include "../include/Utilities.h"

#include <sstream>
#include <fstream>
#include <iostream>

SpriteSheet::SpriteSheet(TextureManager* l_textMgr):m_textureManager(l_textMgr), m_animationCurrent(nullptr), m_spriteScale(1.f, 1.f), m_direction(Direction::Right) {}

SpriteSheet::~SpriteSheet() { ReleaseSheet(); }

void SpriteSheet::ReleaseSheet()
{
	m_textureManager->ReleaseResource(m_texture);
	m_animationCurrent = nullptr;
	while (m_animations.begin() != m_animations.end())
	{
		delete m_animations.begin()->second;
		m_animations.erase(m_animations.begin());
	}
}

void SpriteSheet::SetSpriteSize(const sf::Vector2i& l_size)
{
	m_spriteSize = l_size;
	m_sprite.setOrigin(m_spriteSize.x / 2.f, m_spriteSize.y);
}

void SpriteSheet::SetSpritePosition(const sf::Vector2f& l_pos)
{
	m_sprite.setPosition(l_pos);
}

void SpriteSheet::SetDirection(const Direction& l_dir)
{
	if (l_dir == m_direction)
		return;
	m_direction = l_dir;
	m_animationCurrent->CropSprite();
}

void SpriteSheet::CropSprite(const sf::IntRect& l_rect)
{
	m_sprite.setTextureRect(l_rect);
}

bool SpriteSheet::SetAnimation(const std::string& l_name, const bool& l_play, const bool& l_loop)
{
	auto itr = m_animations.find(l_name);
	if (itr == m_animations.end())
		return false;
	if (itr->second == m_animationCurrent)
		return false;
	if (m_animationCurrent)
		m_animationCurrent->Stop();
	m_animationCurrent = itr->second;
	m_animationCurrent->SetLooping(l_loop);
	if (l_play)
		m_animationCurrent->Play();
	m_animationCurrent->CropSprite();
	return true;
}

void SpriteSheet::Update(const float& l_deltaTime)
{
	m_animationCurrent->Update(l_deltaTime);
}

void SpriteSheet::Draw(sf::RenderWindow* l_window)
{
	l_window->draw(m_sprite);
}

bool SpriteSheet::LoadSheet(const std::string& l_file)
{
	std::ifstream sheet;
	sheet.open(Utils::GetResourceDirectory() + l_file);
	if (sheet.is_open())
	{
		ReleaseSheet();
		std::string line;
		while (std::getline(sheet, line))
		{
			if (line[0] == '|')
				continue;
			std::stringstream keystream(line);
			std::string type;
			keystream >> type;
			if (type == "Texture")
			{
				if (m_texture != "")
				{
					std::cerr << "! Duplicate texture entries in: " << l_file << std::endl;
					continue;
				}
				std::string texture;
				keystream >> texture;
				if (!m_textureManager->RequireResource(texture))
				{
					std::cerr << "! Could not set up the texture: " << texture << std::endl;
					continue;
				}
				m_texture = texture;
				m_sprite.setTexture(*m_textureManager->GetResource(m_texture));
			}
			else if (type == "Size")
			{
				keystream >> m_spriteSize.x >> m_spriteSize.y;
				SetSpriteSize(m_spriteSize);
			}
			else if (type == "Scale")
			{
				keystream >> m_spriteScale.x >> m_spriteScale.y;
				m_sprite.setScale(m_spriteScale);
			}
			else if (type == "AnimationType")
			{
				keystream >> m_animType;
			}
			else if (type == "Animation")
			{
				std::string name;
				keystream >> name;
				if (m_animations.find(name) != m_animations.end())
				{
					std::cerr << "! Duplicate animation(" << name << ") in: " << l_file << std::endl;
					continue;
				}
				Anim_Base* anim = nullptr;
				if (m_animType == "Directional")
					anim = new Anim_Directional();
				else
				{
					std::cerr << "! Unknown animation type: " << m_animType << std::endl;
					continue;
				}
				keystream >> *anim;
				anim->SetSpriteSheet(this);
				anim->SetName(name);
				anim->Reset();
				m_animations.emplace(name, anim);
				if (m_animationCurrent)
					continue;
				m_animationCurrent = anim;
				m_animationCurrent->Play();
			}
		}
		sheet.close();
		return true;
	}
	std::cerr << "! Failed loading spritesheet: " << l_file << std::endl;
	return false;
}
