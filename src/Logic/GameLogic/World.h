#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory> // For std::unique_ptr
#include "Entity.h"
#include "ConcreteFactory.h" // Include the factory header
#include "Camera.h"

class World {
public:
    World (ConcreteFactory& factory, float viewWidth, float viewHeight); // Constructor

    void generateBGtiles(); // Method to generate background tiles
    void update(float deltaTime); // Update method
    void render(); // Render method



private:
    std::shared_ptr<Player> player; // Unique pointer to the player entity
    std::vector<std::shared_ptr<Entity>> entities; // Vector to store entities
    std::vector<std::shared_ptr<Entity>> EntitiesToRender; // Vector to store entities to render
    int score; // Current score
    ConcreteFactory& factory; // Reference to the factory
    Camera camera; // Camera object

    // Helper method to update the camera based on player position
    void updateCamera();
};

#endif // WORLD_H