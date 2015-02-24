#include "Transform.h"
#include <SFML/Graphics.hpp>

Transform::Transform()
{
}


Transform::~Transform()
{
}

auto Transform::getPosition() const -> sf::Vector2f
{
	return position;
}

auto Transform::setPosition(sf::Vector2f position) -> void
{
	this->position = position;
}

auto Transform::getSize() const -> sf::RectangleShape
{
	return rect;
}

auto Transform::setSize(sf::RectangleShape const& size) -> void
{
	this->rect = size;
}
