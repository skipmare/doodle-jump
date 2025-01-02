#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory> // For std::unique_ptr
#include "ConcreteFactory.h" // Include your factory header
#include "World.h" // Include the World header
#include "Stopwatch.h" // Include the Stopwatch header
#include "Camera.h" // Include the Camera header

/**
 * @class Game
 * @brief Represents the core game logic and controls the main game loop.
 *
 * The Game class manages the main game loop, input handling, world updates,
 * and rendering. It also interacts with other components like the stopwatch,
 * world, and factory to manage game state and display.
 */
class Game {
public:
    /**
     * @brief Constructs the Game object and initializes its components.
     */
    Game(); // Constructor

    /**
     * @brief Main game loop that runs until the window is closed.
     *
     * This method handles events, input, updates the world, and renders the
     * game to the window.
     */
    void run(); // Main game loop

    /**
     * @brief Destructor for the Game class.
     *
     * Cleans up any resources or memory used by the game.
     */
    ~Game() = default; // Destructor

    /**
     * @brief Handles user input for controlling the player.
     *
     * This method checks for key presses and moves the player accordingly.
     */
    void handleInput(); // Handle user input

private:
    std::shared_ptr<sf::RenderWindow> window; ///< Pointer to the SFML window
    std::shared_ptr<ConcreteFactory> factory; ///< Pointer to the entity factory
    World world; ///< Instance of the World class
    Stopwatch& stopwatch; ///< Reference to the Stopwatch instance

    /**
     * @brief Updates the game state.
     *
     * This method updates the game world and any relevant entities, based on
     * the elapsed time since the last update.
     *
     * @param deltaTime The time elapsed since the last update, used for smooth
     *                  updates and frame rate independence.
     */
    void update(float deltaTime); // Update method

    /**
     * @brief Renders the game world to the window.
     *
     * This method draws the updated game world to the screen.
     */
    void render(); // Render method
};

#endif // GAME_H
