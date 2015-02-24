#include "Tile.h"
#include "Collider.h"
#include "Transform.h"

Tile::Tile(sf::Vector2f position, sf::RectangleShape size)
{
	transform = new Transform();
	transform->setPosition(position);
	transform->setSize(size);

	collider = new Collider();
	collider->initialize(transform);
}


Tile::~Tile()
{
}
