#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
	public:
		Player();
		~Player();

		auto	getAnimation() -> Animation;
		auto	getSprite() -> sf::Sprite;

		auto	move(sf::Vector2f value) -> void;
		auto	update(sf::Time elapsedTime) -> void;

	private:
		sf::Vector2f velocity;
		float jumpPressedTime;
		bool inAir;
		bool impulsion;

		Animation animation;
		sf::Sprite sprite;
		sf::Texture standTexture;
		sf::Texture walkLeftTexture;
		sf::Texture walkRightTexture;
};

