#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "PhysicSystem.h"
#include "Map.h"
#include "Transform.h"
#include "Collider.h"

#include <iostream>

Player::Player()
{
	walkLeftTexture.loadFromFile("resources/sprite/hero/Hero_WalkLeft.png");
	walkRightTexture.loadFromFile("resources/sprite/hero/Hero_WalkRight.png");
	standTexture.loadFromFile("resources/sprite/hero/Hero_Stand.png");

	inAir = 0.0f;
	jumpPressedTime = false;

	transform = new Transform();
	transform->setPosition(sf::Vector2f(100, 100));
	transform->setSize(sf::RectangleShape(sf::Vector2f((float)standTexture.getSize().x, (float)standTexture.getSize().y)));

	collider = new Collider();
	collider->initialize(transform);
}


Player::~Player()
{
}

auto Player::setPosition(sf::Vector2f position) -> void
{
	this->transform->setPosition(position);
}

auto Player::setSize(sf::RectangleShape size) -> void
{
	this->transform->setSize(size);
}

auto Player::getAnimation() -> Animation
{
	return animation;
}

auto Player::getSprite() -> sf::Sprite
{
	return sprite;
}

auto Player::initialize(PhysicSystem physic) -> void
{
	physic.subscribe(collider);
}

auto Player::move(sf::Vector2f value) -> void
{
	sprite.move(value);
}

auto Player::update(sf::Time elapsedTime, Map const& map) -> void
{
	if (sprite.getPosition().y < 200 - sprite.getTextureRect().height)
	{
		velocity.y += 1;
		inAir = true;
	}
	else
	{
		sprite.setPosition(sprite.getPosition().x, 200.f - sprite.getTextureRect().height);
		velocity.y = 0;
		inAir = false;
		impulsion = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		animation.setAnimationTotal(5);
		sprite.setTexture(walkLeftTexture);
		sprite.setTextureRect(sf::IntRect(37 * animation.getAnimationIndex(), 0, 37, sprite.getTextureRect().height));

		if (velocity.x > -1)
			velocity += sf::Vector2f(-100 * elapsedTime.asSeconds(), 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		animation.setAnimationTotal(5);
		sprite.setTexture(walkRightTexture);
		sprite.setTextureRect(sf::IntRect(37 * animation.getAnimationIndex(), 0, 37, sprite.getTextureRect().height));

		if (velocity.x < 1)
			velocity += sf::Vector2f(100 * elapsedTime.asSeconds(), 0);
	}
	else
	{
		animation.setAnimationTotal(6);
		sprite.setTexture(standTexture);
		sprite.setTexture(standTexture);
		sprite.setTextureRect(sf::IntRect(37 * animation.getAnimationIndex(), 0, 37, sprite.getTextureRect().height));

		velocity.x = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (impulsion || !inAir))
	{
		jumpPressedTime += elapsedTime.asSeconds();

		if (jumpPressedTime < 0.2f)
			velocity += sf::Vector2f(0, -100 * elapsedTime.asSeconds());
	}
	else
	{
		impulsion = false;
		jumpPressedTime = 0;
	}

	move(velocity);

	animation.update(elapsedTime);
}

/*auto Player::update(sf::Time elapsedTime, Map const& map) -> void
{
	if (sprite.getPosition().y < 200 - sprite.getTextureRect().height)
	{
		velocity.y += 1;
		inAir = true;
	}
	else
	{
		sprite.setPosition(sprite.getPosition().x, 200.f - sprite.getTextureRect().height);
		velocity.y = 0;
		inAir = false;
		impulsion = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		animation.setAnimationTotal(5);
		sprite.setTexture(walkLeftTexture);
		sprite.setTextureRect(sf::IntRect(37 * animation.getAnimationIndex(), 0, 37, sprite.getTextureRect().height));

		if (velocity.x > -1)
			velocity += sf::Vector2f(-100 * elapsedTime.asSeconds(), 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		animation.setAnimationTotal(5);
		sprite.setTexture(walkRightTexture);
		sprite.setTextureRect(sf::IntRect(37 * animation.getAnimationIndex(), 0, 37, sprite.getTextureRect().height));

		if (velocity.x < 1)
			velocity += sf::Vector2f(100 * elapsedTime.asSeconds(), 0);
	}
	else
	{
		animation.setAnimationTotal(6);
		sprite.setTexture(standTexture);
		sprite.setTexture(standTexture);
		sprite.setTextureRect(sf::IntRect(37 * animation.getAnimationIndex(), 0, 37, sprite.getTextureRect().height));

		velocity.x = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (impulsion || !inAir))
	{
		jumpPressedTime += elapsedTime.asSeconds();

		if (jumpPressedTime < 0.2f)
			velocity += sf::Vector2f(0, -100 * elapsedTime.asSeconds());
	}
	else
	{
		impulsion = false;
		jumpPressedTime = 0;
	}

	move(velocity);

	animation.update(elapsedTime);
}*/