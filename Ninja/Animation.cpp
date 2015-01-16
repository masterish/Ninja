#include "Animation.h"
#include <iostream>

Animation::Animation()
{
}


Animation::~Animation()
{
}

auto	Animation::update(sf::Time /*elapsed*/) -> void
{
	animationIndex++;

	if (animationIndex >= getAnimationTotal())
	{
		animationIndex = 0;
	}
}

auto	Animation::getAnimationTotal() const -> int
{
	return animationTotal;
}

auto	Animation::setAnimationTotal(int value) -> void
{
	animationTotal = value;
}

auto	Animation::getAnimationIndex() const -> int
{
	return animationIndex;
}