#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>

class PhysicSystem;

class Map
{
public:
	Map();
	~Map();

	enum TileType { SOLID, NONE };

	Tile tiles[50][50];
	sf::Texture tilesTexture;
	sf::Sprite tile;

	void loadMap(PhysicSystem physic);
	void drawMap(sf::RenderWindow& window);
};

