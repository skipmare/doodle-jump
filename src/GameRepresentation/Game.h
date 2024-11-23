#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory> // For std::unique_ptr
#include "ConcreteFactory.h" // Include your factory header
#include "World.h"
#include "Stopwatch.h" // Include the Stopwatch header

class Game {
public:
    Game(); // Constructor
    void run(); // Main game loop
    ~Game() = default; // Destructor

private:
    sf::RenderWindow window; // SFML window
    std::unique_ptr<ConcreteFactory> factory; // Pointer to the entity factory
    World world; // Instance of the World class
    Stopwatch& stopwatch; // Reference to the Stopwatch instance
};

#endif // GAME_H