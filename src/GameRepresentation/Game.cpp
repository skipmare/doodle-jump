#include "Game.h"
#include <iostream>

/**
 * @class Game
 * @brief Represents the main game loop and game logic.
 *
 * The Game class handles the core game loop, window management, user input, and updates the world.
 * It interacts with other components like the stopwatch, world, and factory to manage game state and render the game.
 */
Game::Game()
    : window(std::make_shared<sf::RenderWindow>(sf::VideoMode(500, 800), "Doodle Jump by Karan")), ///< Create the SFML window
      factory(std::make_shared<ConcreteFactory>(window)), ///< Instantiate the factory
      world(factory, 500, 800), ///< Initialize the World instance
      stopwatch(Stopwatch::getInstance()) ///< Get the Stopwatch instance
{
    stopwatch.start(); ///< Start the stopwatch
}

/**
 * @brief Main game loop that runs until the window is closed.
 *
 * This method controls the flow of the game, handling events, user input, updating the world,
 * and rendering the window at a target frame rate of 60 FPS.
 */
void Game::run() {
    float targetFrameTime = 1.0f / 60.0f; ///< Target frame time for 60 FPS
    // Main game loop
    while (window->isOpen()) {
        sf::Event event {}; ///< Event object to handle window events
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close(); ///< Close the window if the close event is triggered
        }

        handleInput(); ///< Handle user input

        // Update the world
        float deltaTime = stopwatch.tick(); ///< Get the time elapsed since the last update

        // Clear the window
        window->clear(sf::Color::Black);

        world.update(deltaTime); ///< Update the world and render the entities

        // Display the contents of the window
        window->display();

        // Control the frame rate
        float elapsedTime = stopwatch.getElapsedTime();

        if (elapsedTime < targetFrameTime) {
            sf::sleep(sf::seconds(targetFrameTime - elapsedTime)); ///< Sleep to maintain the target frame rate
        }
    }
}

/**
 * @brief Handles user input for controlling the player.
 *
 * This method checks for key presses and moves the player accordingly.
 */
void Game::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        world.PlayerMove(-1); ///< Move player left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        world.PlayerMove(1); ///< Move player right
    }
}
