#include <ConcreteFactory.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Player.h"
#include "../Logic/Entities/Entity.h"
#include "AbstractFactory.h"
#include "ConcreteFactory.h"

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
            return (std::abs(playerBox.bottom - entityBox.top) < 1.0f && playerBox.right >= entityBox.left && playerBox.left <= entityBox.right && player->isFalling()); // Check for collision
        } else {
            std::cout<<"no collision on land"<<std::endl;
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

    // Create player and platform
    auto player = factory->createPlayer(250, 250);
    auto platform = factory->createPlatform(250, 300, PlatformType::HORIZONTAL);
    auto platform2 = factory->createPlatform(250, 500, PlatformType::HORIZONTAL);
    auto platform3 = factory->createPlatform(250, 700, PlatformType::HORIZONTAL);

    // Create a bonus on top of platform2
    auto bonus = factory->createBonus(250, platform2->getY() - 50, BonusType::JETPACK, platform2);

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
            player->move(-1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player->move(1);
        }

        // Clear the window
        window->clear();
        // Update entities
        player->update(deltaTime);
        platform->update(deltaTime);
        platform2->update(deltaTime);
        platform3->update(deltaTime);
        bonus->update(deltaTime);

        // Check for collision
        if (checkCollision_player(player, platform) || checkCollision_player(player, platform2) || checkCollision_player(player, platform3) || checkCollision_player(player, bonus)) {
            std::cout << "Collision detected! Making player jump." << std::endl;
            player->jump();
        }

        // Display the window contents
        window->display();
    }

    return 0;
}