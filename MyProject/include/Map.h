#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <map>
#include <array>
#include <fstream>
#include <sstream>

#include "../include/Utilities.h"
#include "../include/SharedContext.h"
#include "../include/BaseState.h"

enum Sheet { Tile_Size = 32, Sheet_Width = 256, Sheet_Height = 256 };

using TileID = unsigned int;

struct TileInfo
{
	TileInfo(SharedContext* l_context, const std::string& l_texture = "", TileID l_id = 0) : m_context(l_context), m_id(0), m_deadly(false)
	{
		TextureManager* textureManager = l_context->m_textureManager;
		if (l_texture == "")
		{
			m_id = l_id; 
			return;
		}
			
		if (!textureManager->RequireResource(l_texture))
			return;
		m_texture = l_texture;
		m_id = l_id;
		m_sprite.setTexture(*textureManager->GetResource(m_texture));
		sf::IntRect tileBoundaries(m_id %
			(Sheet::Sheet_Width / Sheet::Tile_Size) * Sheet::Tile_Size,
			m_id / (Sheet::Sheet_Height / Sheet::Tile_Size) * Sheet::Tile_Size,
			Sheet::Tile_Size, Sheet::Tile_Size);
		m_sprite.setTextureRect(tileBoundaries);
	}

	~TileInfo()
	{
		if (m_texture == "")
			return;
		m_context->m_textureManager->ReleaseResource(m_texture);
	}
	sf::Sprite m_sprite;

	TileID m_id;
	std::string m_name;
	sf::Vector2f m_friction;
	bool m_deadly;

	SharedContext* m_context;
	std::string m_texture;
};

struct Tile
{
	TileInfo* m_properties;
	bool m_warp;
	// Other flags unique to each tile.
};

using TileMap = std::unordered_map<TileID, Tile*>;
using TileSet = std::unordered_map<TileID, TileInfo*>;

class Map
{
public:
	Map(SharedContext* l_context, BaseState* l_currentState);
	~Map();

	Tile* GetTile(unsigned int l_x, unsigned int l_y);
	TileInfo* GetDefaultTile();

	float GetGravity()const { return m_mapGravity; };
	unsigned int GetTileSize()const { return Sheet::Tile_Size; };
	const sf::Vector2u& GetMapSize()const { return m_maxMapSize; };
	const sf::Vector2f& GetPlayerStart()const { return m_playerStart; };

	void LoadMap(const std::string& l_file);
	void LoadNext();
	void Update(float l_dT);
	void Draw();

private:
	unsigned int ConvertCoords(const unsigned int& l_x, const unsigned int& l_y);
	void LoadTiles(const std::string& l_path);
	void PurgeMap();
	void PurgeTileSet();

	TileSet m_tileSet;
	TileMap m_tileMap;
	sf::Sprite m_background;
	TileInfo m_defaultTile;
	sf::Vector2u m_maxMapSize;
	sf::Vector2f m_playerStart;
	unsigned int m_tileCount;
	unsigned int m_tileSetCount;
	float m_mapGravity;
	std::string m_nextMap;
	bool m_loadNextMap;
	std::string m_backgroundTexture;
	BaseState* m_currentState;
	SharedContext* m_context;
};
