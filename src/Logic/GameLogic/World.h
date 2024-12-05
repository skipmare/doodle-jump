#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory> // For std::shared_ptr
#include "Entity.h"
#include "AbstractFactory.h" // Include the factory header
#include "Camera.h"
#include "Random.h"

enum class Difficulty {
    EASY,
    MEDIUM,
    HARD
}; // Enum for difficulty levels

class World {
public:
    World(const std::shared_ptr<AbstractFactory>& factory, float viewWidth, float viewHeight); // Constructor
    ~World() = default; // Destructor

    bool checkCollision(std::shared_ptr<Entity> entity1, std::shared_ptr<Entity> entity2); // Check collision between two entities
    bool checkCollision_player(std::shared_ptr<Entity> entity); // Check collision between player and entity

    void update(float deltaTime); // Update the world

    void setDifficulty(Difficulty difficulty); // Set the difficulty level
    [[nodiscard]] int getScore() const; // Get the current score
    [[nodiscard]] std::shared_ptr<Player> getPlayer() const; // Get the player entity
    [[nodiscard]] std::vector<std::shared_ptr<Entity>> getEntities() const; // Get the entities

    void addEntity(std::shared_ptr<Entity> entity); // Add an entity to the world
    void removeEntity(std::shared_ptr<Entity> entity); // Remove an entity from the world

    void removeRemovableEntities(); // Remove entities which are out of view


private:
    std::shared_ptr<Player> player; // Shared pointer to the player entity
    std::vector<std::shared_ptr<Entity>> entities; // Vector to store entities
    int score; // Current score
    std::shared_ptr<AbstractFactory> factory; // Shared pointer to the factory
    Camera camera; // Camera object
    Random random; // Random object
    Difficulty difficulty = Difficulty::EASY; // Difficulty level

    // Helper method to update the camera based on player position
    void updateCamera();
};

#endif // WORLD_H