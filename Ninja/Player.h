#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Collider;
class Transform;
class PhysicSystem;
class Map;

class Player
{
	public:
		Player();
		~Player();

		auto	getAnimation() -> Animation;
		auto	getSprite() -> sf::Sprite;

		auto	setPosition(sf::Vector2f position) -> void;
		auto	setSize(sf::RectangleShape size) -> void;

		auto	initialize(PhysicSystem physic) -> void;
		auto	move(sf::Vector2f value) -> void;
		auto	update(sf::Time elapsedTime, Map const&) -> void;

	private:
		sf::Vector2f velocity;

		float jumpPressedTime;
		bool inAir;
		bool impulsion;

		Collider* collider;
		Transform* transform;
		Animation animation;

		sf::Sprite sprite;
		sf::Texture standTexture;
		sf::Texture walkLeftTexture;
		sf::Texture walkRightTexture;
};

