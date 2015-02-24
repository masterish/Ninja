#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Transform;
class Collider;

class Tile
{
public:
	Tile() = default;
	Tile(sf::Vector2f position, sf::RectangleShape size);
	~Tile();

	int type;

	Collider* collider;
	Transform* transform;
};

