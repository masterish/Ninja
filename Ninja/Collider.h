#pragma once
#include <SFML/Graphics.hpp>

class Transform;

class Collider
{
public:
	Collider() = default;
	Collider();
	~Collider();

	auto initialize(Transform* transform) -> bool;

	auto getPosition() const -> sf::Vector2f;
	auto getSize() const -> sf::RectangleShape;

private:
	Transform* transform;
};

