#include "Map.h"
#include "PhysicSystem.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

Map::Map()
{
}


Map::~Map()
{
}

void Map::drawMap(sf::RenderWindow& window)
{
	sf::RectangleShape solidTileTexture(sf::Vector2f(10, 10));
	solidTileTexture.setFillColor(sf::Color::Black);

	sf::RectangleShape tileTexture(sf::Vector2f(10, 10));
	tileTexture.setFillColor(sf::Color::White);

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (tiles[j][i])
			{
				solidTileTexture.setPosition(i * 10.f, j * 10.f);
				window.draw(solidTileTexture);
			}
			else
			{
				tileTexture.setPosition(i * 10.f, j * 10.f);
				window.draw(tileTexture);
			}
		}
	}
}

void Map::loadMap(PhysicSystem physic)
{
	std::ifstream file("resources/map/map.txt");
	
	if (file.is_open())
	{
		int x = 0, y = 0;
		int type;

		while (file >> type)
		{	
			Tile tile(sf::Vector2f(y*32,x*32), sf::RectangleShape(sf::Vector2f(32,32)));
			tile.type = type;
			tiles[x][y] = tile;
			physic.subscribe(tiles[x][y].collider);

			if (y == 49)
			{
				y = 0;
				x++;
			}
			else
			{
				y++;
			}
		}
	}
	else
	{
		std::cout << "Not open." << std::endl;
	}
}