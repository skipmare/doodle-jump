#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory> // For std::shared_ptr
#include "Entity.h"
#include "AbstractFactory.h" // Include the factory header
#include "Camera.h"

class World {
public:
    World(std::shared_ptr<AbstractFactory> factory, float viewWidth, float viewHeight); // Constructor
    ~World() = default; // Destructor

    bool checkCollision(std::shared_ptr<Entity> entity1, std::shared_ptr<Entity> entity2); // Check collision between two entities

private:
    std::shared_ptr<Player> player; // Shared pointer to the player entity
    std::vector<std::shared_ptr<Entity>> entities; // Vector to store entities
    std::vector<std::shared_ptr<Entity>> entitiesToRender; // Vector to store entities to render
    int score; // Current score
    std::shared_ptr<AbstractFactory> factory; // Shared pointer to the factory
    Camera camera; // Camera object

    // Helper method to update the camera based on player position
    void updateCamera();
};

#endif // WORLD_H