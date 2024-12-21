#include <ConcreteFactory.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Player.h"
#include "../Logic/Entities/Entity.h"
#include "AbstractFactory.h"
#include "ConcreteFactory.h"
#include "World.h"

int main() {
    // Create an SFML window
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(500, 800), "Doodle Jump by Karan (Prototype)");

    // Create the factory with the window
    auto factory = std::make_shared<ConcreteFactory>(window);

    // Create the world
    World world(factory, 500, 800);

    // Create a clock to measure elapsed time
    sf::Clock clock;

    // Main loop
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }
        // Get the elapsed time
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        // Handle player input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            world.getPlayer().move(-1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            world.getPlayer().move(1);
        }

        world.update(deltaTime);

        // Display the window contents
        window->display();
        window->clear();

    }

    return 0;
}