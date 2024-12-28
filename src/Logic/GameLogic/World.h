#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory> // For std::shared_ptr
#include "Entity.h"
#include "AbstractFactory.h" // Include the factory header
#include "Camera.h"
#include "Random.h"
#include "../DifficultySettings/EASY.h"
#include "../DifficultySettings/MEDIUM.h"
#include "../DifficultySettings/HARD.h"

enum class Difficulty {
    EASY,
    MEDIUM,
    HARD
}; // Enum for difficulty levels

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

    [[nodiscard]] bool getGameOver() const; // Get the game over state
    [[nodiscard]] const DifficultySettings& getDifficulty() const; // Get the difficulty level

    void removeRemovableEntities(); // Remove entities which are out of view
    void genWorld(); // Generate the world

    bool isValidMinDistance(float minDistance, const std::shared_ptr<Entity>& newplat) const; // Check if the distance between platforms is valid
    bool isValidMaxDistance(float maxDistance, const std::shared_ptr<Entity>& newplat) const; // Check if the distance between platforms is valid

    void genPlats(float chanceStatic, float chanceVertical, float chanceHorizontal, float chanceDisappearing, float minDistance,float maxDistance, float fromy, float toy); // Initialize the world
    void updatePlayer(float deltaTime) const; // Update the player
    void updateEntities(float deltaTime); // Update all entities
    void checkCollisions(); // Check for collisions
    void generateNewPlatforms(); // Generate new platforms
    void updateCamera(); // Update the camera
    void setGameOver(bool gameOver); // Set the game over state
    void checkGameOver(); // Check if the game is over

    void genBonus(const std::shared_ptr<Platform> &entity); // Generate bonus platforms
    void updateBonuses(float deltaTime); // Update bonus platforms

    void generateBackground(float from_y, float to_y); // Generate the background tiles for the world
    void updateBackground(float deltaTime); // Update the background tiles
    void generateNewTiles(); // Generate new background tiles

    void CheckBonusCollision(); // Check for bonus collisions
    void CheckDifficulty(); // Check the difficulty level

    void PlayerMove(int direction) const; // Move the player

private:
    std::shared_ptr<Player> player; // Shared pointer to the player entity
    std::vector<std::shared_ptr<Platform>> entities; // Vector to store entities
    std::vector<std::shared_ptr<Entity>> background;
    std::vector<std::shared_ptr<Bonus>> bonuses; // Vector to store bonus entities
    std::shared_ptr<Score> score; // Current score
    std::shared_ptr<AbstractFactory> factory; // Shared pointer to the factory
    Camera camera; // Camera object
    int ActivePlatforms = 0;
    bool isGameOver = false;
    Difficulty difficulty = Difficulty::EASY; // Default difficulty level


};

#endif // WORLD_H