#include "Game.h"
#include <algorithm>

/**
 * @class Game
 * @brief Represents the main game loop and game logic.
 *
 * The Game class handles the core game loop, window management, user input, and updates the world.
 * It interacts with other components like the stopwatch, world, and factory to manage game state and render the game.
 */
Game::Game()
    : window(std::make_shared<sf::RenderWindow>(sf::VideoMode(500, 800), "Doodle Jump")), ///< Create the SFML window
      factory(std::make_shared<ConcreteFactory>(window)), ///< Instantiate the factory
      world(factory, 500, 800), ///< Initialize the World instance
      stopwatch(Stopwatch::getInstance()) ///< Get the Stopwatch instance
{
    window->setFramerateLimit(60);
    stopwatch.start(); ///< Start the stopwatch
}

/**
 * @brief Main game loop that runs until the window is closed.
 *
 * This method controls the flow of the game, handling events, user input, updating the world,
 * and rendering the window at a target frame rate of 60 FPS.
 */
void Game::run() {
    // Main game loop
    while (window->isOpen()) {
        sf::Event event {}; ///< Event object to handle window events
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close(); ///< Close the window if the close event is triggered
        }

        if (!window->isOpen()) {
            break;
        }

        // Cap large frame deltas so a pause cannot make the player tunnel through platforms.
        const float deltaTime = std::min(stopwatch.tick(), 1.0f / 30.0f);
        handleInput(); ///< Handle user input

        // Clear the window
        window->clear(sf::Color::Black);

        world.update(deltaTime); ///< Update the world state
        world.render(); ///< Render each entity once after all state changes

        // Display the contents of the window
        window->display();
    }
}

/**
 * @brief Handles user input for controlling the player.
 *
 * This method checks for key presses and moves the player accordingly.
 */
void Game::handleInput() {
    const bool movingLeft =
        sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    const bool movingRight =
        sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    const int direction = movingLeft == movingRight ? 0 : (movingRight ? 1 : -1);
    world.PlayerMove(direction);
}
