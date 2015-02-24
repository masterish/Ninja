#include "Collider.h"
#include <SFML/Graphics.hpp>

#include "Transform.h"

Collider::Collider()
{
}


Collider::~Collider()
{
}

auto Collider::initialize(Transform* transform) -> bool
{
	this->transform = transform;

	return true;
}

auto Collider::getPosition() const -> sf::Vector2f
{
	return transform->getPosition();
}

auto Collider::getSize() const -> sf::RectangleShape
{
	return transform->getSize();
}
