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

struct EASY {
    float ChanceBonus = 0.15f;         // Slight chance of bonus platforms
    float ChanceStatic = 1.0f;        // High chance of static platforms for stability
    float ChanceHorizontal = 0.1f;     // A few moving horizontal platforms
    float ChanceVertical = 0.05f;      // Rare vertical platforms
    float ChanceDisappearing = 0.15f;  // Some disappearing platforms to keep things dynamic
    float minDistance = 110.0f;        // Minimum distance between platforms
    float maxDistance = 260.0f;        // Maximum distance between platforms
};

struct MEDIUM {
    float ChanceBonus = 0.1f;          // Decreased chance for bonuses
    float ChanceStatic = 0.45f;        // Moderate chance of static platforms
    float ChanceHorizontal = 0.2f;     // Moderate chance of horizontal platforms
    float ChanceVertical = 0.1f;       // Slightly more vertical platforms
    float ChanceDisappearing = 0.15f;  // Some disappearing platforms for challenge
    float minDistance = 50.0f;        // Minimum distance between platforms
    float maxDistance = 300.0f;        // Maximum distance between platforms
};

struct HARD {
    float ChanceBonus = 0.05f;         // Very rare bonuses to increase challenge
    float ChanceStatic = 0.3f;         // Low chance of static platforms
    float ChanceHorizontal = 0.25f;    // Higher chance of horizontal platforms
    float ChanceVertical = 0.2f;      // Increased chance of vertical platforms
    float ChanceDisappearing = 0.3f;   // High chance of disappearing platforms
    float minDistance = 50.0f;        // Minimum distance between platforms
    float maxDistance = 300.0f;        // Maximum distance between platforms
};



class World {
public:
    World(const std::shared_ptr<AbstractFactory>& factory, float viewWidth, float viewHeight); // Constructor
    ~World() = default; // Destructor

    static bool checkCollision(const std::shared_ptr<Entity>& entity1, const std::shared_ptr<Entity>& entity2) ; // Check collision between two entities
    bool checkCollision_player(const std::shared_ptr<Entity>& entity) const; // Check collision between player and entity

    void update(float deltaTime); // Update the world

    void setDifficulty(Difficulty difficulty); // Set the difficulty level
    [[nodiscard]] int getScore() const; // Get the current score
    [[nodiscard]] std::shared_ptr<Player> getPlayer() const; // Get the player entity
    [[nodiscard]] std::vector<std::shared_ptr<Platform>> getEntities() const; // Get the entities
    [[nodiscard]] Camera& getCamera(); // Get the camera object

    [[nodiscard]] Player& getPlayer(); // Get the player reference
    [[nodiscard]] float getPlayerNormalizedY() const; // Get the player's normalized Y position

    void addEntity(std::shared_ptr<Entity> entity); // Add an entity to the world
    void removeEntity(std::shared_ptr<Entity> entity); // Remove an entity from the world

    void removeRemovableEntities(); // Remove entities which are out of view
    void genWorld(); // Generate the world

    bool isValidMinDistance(float minDistance, const std::shared_ptr<Entity>& newplat) const; // Check if the distance between platforms is valid
    bool isValidMaxDistance(float maxDistance, const std::shared_ptr<Entity>& newplat) const; // Check if the distance between platforms is valid

    void genPlats(float chanceStatic, float chanceVertical, float chanceHorizontal, float chanceDisappearing, float minDistance,float maxDistance, float fromy, float toy); // Initialize the world
    void updatePlayer(float deltaTime); // Update the player
    void updateEntities(float deltaTime); // Update all entities
    void checkCollisions(); // Check for collisions
    void generateNewPlatforms(); // Generate new platforms
    void updateCamera(); // Update the camera
    void setGameOver(bool gameOver); // Set the game over state
    [[nodiscard]] bool getGameOver() const; // Get the game over state
    void checkGameOver(); // Check if the game is over

    void generateBackground(float from_y, float to_y); // Generate the background tiles for the world
    void updateBackground(float deltaTime); // Update the background tiles
    void generateNewTiles(); // Generate new background tiles

private:
    std::shared_ptr<Player> player; // Shared pointer to the player entity
    std::vector<std::shared_ptr<Platform>> entities; // Vector to store entities
    std::vector<std::shared_ptr<Entity>> background;
    std::shared_ptr<Score> score; // Current score
    std::shared_ptr<AbstractFactory> factory; // Shared pointer to the factory
    Camera camera; // Camera object
    Difficulty difficulty = Difficulty::EASY; // Difficulty level
    int ActivePlatforms = 0;
    bool isGameOver = false;


};

#endif // WORLD_H