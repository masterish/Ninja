#include <SFML/Graphics.hpp>
#include <iostream>
#include "PhysicSystem.h"
#include "Player.h"
#include "Map.h"


union lol
{
	int i;
	float f;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	lol lol2;

	lol2.i = 12;

	sf::Clock gameClock;
	gameClock.restart();

	sf::Time elapsedTime(sf::Time::Zero);
	
	PhysicSystem physicSystem;
	Player player;
	player.initialize(physicSystem);

	Map map;
	map.loadMap(physicSystem);

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
			player.update(elapsedTime, map);
			physicSystem.update();
			gameClock.restart();
		}

        window.clear(sf::Color::White);
		map.drawMap(window);
        window.draw(player.getSprite());
        window.display();
    }
	

    return 0;
}
