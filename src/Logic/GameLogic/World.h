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


private:
    std::unique_ptr<Player> player; // Unique pointer to the player entity
    std::vector<std::unique_ptr<Entity>> entities; // Vector to store entities
    std::vector<std::unique_ptr<Entity>> EntitiesToRender; // Vector to store entities to render
    int score; // Current score
    ConcreteFactory& factory; // Reference to the factory
    Camera camera; // Camera object

    // Helper method to update the camera based on player position
    void updateCamera();
};

#endif // WORLD_H