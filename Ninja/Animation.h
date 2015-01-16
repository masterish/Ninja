#pragma once
#include "SFML/System.hpp"

class Animation
{
public:
	Animation();
	~Animation();

	auto	update(sf::Time elapsed) -> void;

	auto	getAnimationTotal() const -> int;
	auto	setAnimationTotal(int value) -> void;

	auto	getAnimationIndex() const -> int;
	auto	setAnimationIndex(int value) -> void;

private:
	int animationTotal = 0;
	int animationIndex = 0;
};

