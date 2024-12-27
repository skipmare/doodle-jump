#include "Game.h"
#include <iostream>

Game::Game()
    : window(std::make_shared<sf::RenderWindow>(sf::VideoMode(500, 800), "Doodle Jump by Karan")), // Create the SFML window
      factory(std::make_shared<ConcreteFactory>(window)), // Instantiate the factory
      world(factory, 500, 800), // Initialize the World instance
      stopwatch(Stopwatch::getInstance()) // Get the Stopwatch instance
{
    stopwatch.start(); // Start the stopwatch
}

void Game::run() {
    float targetFrameTime = 1.0f / 60.0f; // 60 FPS
    // Main game loop
    while (window->isOpen()) {
        sf::Event event {};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        handleInput(); // Handle user input

        // Update the world
        float deltaTime = stopwatch.tick(); // Get the time since the last update

        // Clear the window
        window->clear(sf::Color::Black);

        world.update(deltaTime); // Update the world and render the entities

        // Display the contents of the window
        window->display();

        // Control the frame rate
        float elapsedTime = stopwatch.getElapsedTime();

        if (elapsedTime < targetFrameTime) {
            sf::sleep(sf::seconds(targetFrameTime - elapsedTime)); // Sleep to maintain frame rate
        }
    }
}


    void Game::handleInput() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            world.getPlayer().move(-1); // Move player left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            world.PlayerMove(1); // Move player right
        }
    }
