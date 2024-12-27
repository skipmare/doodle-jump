#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory> // For std::unique_ptr
#include "ConcreteFactory.h" // Include your factory header
#include "World.h" // Include the World header
#include "Stopwatch.h" // Include the Stopwatch header
#include "Camera.h" // Include the Camera header

class Game {
public:
    Game(); // Constructor
    void run(); // Main game loop
    ~Game() = default; // Destructor

    void handleInput(); // Handle user input

private:
    std::shared_ptr<sf::RenderWindow> window; // SFML window
    std::shared_ptr<ConcreteFactory> factory; // Pointer to the entity factory
    World world; // Instance of the World class
    Stopwatch& stopwatch; // Reference to the Stopwatch instance

    void update(float deltaTime); // Update method
    void render(); // Render method
};

#endif // GAME_H