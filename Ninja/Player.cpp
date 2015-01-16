#include "Player.h"
#include <iostream>

Player::Player()
{
	walkLeftTexture.loadFromFile("resources/sprite/hero/Hero_WalkLeft.png");
	walkRightTexture.loadFromFile("resources/sprite/hero/Hero_WalkRight.png");
	standTexture.loadFromFile("resources/sprite/hero/Hero_Stand.png");

	sprite.setPosition(0, 0);
	inAir = 0.0f;
	jumpPressedTime = false;
}


Player::~Player()
{
}

auto Player::getAnimation() -> Animation
{
	return animation;
}

auto Player::getSprite() -> sf::Sprite
{
	return sprite;
}

auto Player::move(sf::Vector2f value) -> void
{
	sprite.move(value);
}

auto Player::update(sf::Time elapsedTime) -> void
{

	if (sprite.getPosition().y < 200 - sprite.getTextureRect().height)
	{
		velocity.y += 1;
		inAir = true;
	}
	else
	{
		sprite.setPosition(sprite.getPosition().x, 200 - sprite.getTextureRect().height);
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