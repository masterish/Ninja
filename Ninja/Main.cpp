#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	sf::Clock gameClock;
	gameClock.restart();

	sf::Time elapsedTime(sf::Time::Zero);

	Player player;

    while (window.isOpen())
    {
		elapsedTime = gameClock.getElapsedTime();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		if (elapsedTime.asSeconds() >= 0.016f)
		{
			player.update(elapsedTime);

			gameClock.restart();
		}

        window.clear(sf::Color::White);
        window.draw(player.getSprite());
        window.display();
    }

    return 0;
}