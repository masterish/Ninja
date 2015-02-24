#pragma once
#include <SFML/Graphics.hpp>

class Transform
{
public:
	Transform();
	~Transform();

	auto setPosition(sf::Vector2f position) -> void;
	auto setSize(sf::RectangleShape const& rect) -> void;

	auto getPosition() const -> sf::Vector2f;
	auto getSize() const -> sf::RectangleShape;

private:
	sf::Vector2f position;
	sf::RectangleShape rect;
};

