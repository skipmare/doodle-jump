#include <ConcreteFactory.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Player.h"
#include "../Logic/Entities/Entity.h"
#include "AbstractFactory.h"
#include "ConcreteFactory.h"
#include "World.h"

bool checkCollision(const std::shared_ptr<Entity>& entity1, const std::shared_ptr<Entity>& entity2) {
    auto box1 = entity1->getBoundingBox();
    auto box2 = entity2->getBoundingBox();
    return (box1.right >= box2.left && box1.left <= box2.right &&
        box1.bottom >= box2.top && box1.top <= box2.bottom);
}

bool checkCollision_player(std::shared_ptr<Player> player, std::shared_ptr<Entity> entity) {
    if (!entity) return false; // Handle null pointer.

    if (entity->getCollidable()) {
        if (entity->getCollisionOnLand()) {
            BoundingBox playerBox = player->getBoundingBox(); // Get bounding box of player
            BoundingBox entityBox = entity->getBoundingBox(); // Get bounding box of entity
            return (std::abs(playerBox.bottom - entityBox.top) < 3.0f && playerBox.right >= entityBox.left && playerBox.left <= entityBox.right && player->isFalling()); // Check for collision
        } else {
            return checkCollision(player, entity); // Check collision between player and entity
        }
    }
    return false; // Return false if the entity is not collidable
}

int main() {
    // Create an SFML window
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(500, 800), "Game Window");

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