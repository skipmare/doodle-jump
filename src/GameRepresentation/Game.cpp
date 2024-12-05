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
    Stopwatch::getInstance().start();
    float targetFrameTime = 1.0f / 60.0f; // 60 FPS
    // Main game loop
    while (window->isOpen()) {
        sf::Event event {};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Handle user input and update the world
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            // Move player left (you may need to access the player instance)
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            // Move player right (you may need to access the player instance)
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            // Make the player jump (you may need to access the player instance)
        }

        // Update the world
        float deltaTime = stopwatch.tick(); // Get the time since the last update

        // Clear the window
        window->clear(sf::Color::Black);

        //world.update(deltaTime); // Update the world and render the entities

        // Display the contents of the window
        window->display();

        // Control the frame rate
        float elapsedTime = stopwatch.getElapsedTime();

        if (elapsedTime < targetFrameTime) {
            sf::sleep(sf::seconds(targetFrameTime - elapsedTime)); // Sleep to maintain frame rate
        }
    }
}