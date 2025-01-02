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
#include "iostream"
#include "unordered_set"
#include "functional"

/**
 * @enum Difficulty
 * @brief Enum for difficulty levels in the game.
 *
 * The Difficulty enum represents the three levels of difficulty available in the game.
 */
enum class Difficulty {
    EASY,    ///< Easy difficulty level.
    MEDIUM,  ///< Medium difficulty level.
    HARD     ///< Hard difficulty level.
};

/**
 * @class World
 * @brief Represents the game world, including entities, the player, camera, and collision detection.
 *
 * The World class is responsible for managing the game's entities, checking collisions, updating the game state, and generating the world and its components (such as platforms and background).
 */
class World {
public:
    /**
     * @brief Constructs the World object.
     *
     * Initializes the world with the provided factory and view dimensions.
     *
     * @param factory A shared pointer to the AbstractFactory used for creating entities.
     * @param viewWidth The width of the view (camera).
     * @param viewHeight The height of the view (camera).
     */
    World(const std::shared_ptr<AbstractFactory>& factory, float viewWidth, float viewHeight);

    /**
     * @brief Destructor for the World class.
     *
     * Cleans up any dynamically allocated resources when the world is destroyed.
     */
    ~World() = default;

    /**
     * @brief Checks for a collision between two entities.
     *
     * This method checks if two entities are colliding based on their bounding boxes.
     *
     * @param entity1 The first entity to check.
     * @param entity2 The second entity to check.
     * @return True if a collision is detected, false otherwise.
     */
    static bool checkCollision(const std::shared_ptr<Entity>& entity1, const std::shared_ptr<Entity>& entity2);

    /**
     * @brief Checks for a collision between the player and a given entity.
     *
     * This method checks if the player is colliding with a specific entity.
     *
     * @param entity The entity to check for collision with.
     * @return True if a collision is detected, false otherwise.
     */
    [[nodiscard]] bool checkCollision_player(const std::shared_ptr<Entity>& entity) const;

    /**
     * @brief Updates the world state based on the time delta.
     *
     * This method updates all entities in the world, including the player, camera, and other objects.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void update(float deltaTime);

    /**
     * @brief Sets the difficulty level of the game.
     *
     * This method adjusts the game's difficulty based on the provided level.
     *
     * @param difficulty The difficulty level to set (EASY, MEDIUM, HARD).
     */
    void setDifficulty(Difficulty difficulty);

    /**
     * @brief Gets the current score of the game.
     *
     * @return The current score of the game.
     */
    [[nodiscard]] int getScore() const;

    /**
     * @brief Gets the player entity.
     *
     * @return A shared pointer to the player entity.
     */
    [[nodiscard]] std::shared_ptr<Player> getPlayer() const;

    /**
     * @brief Gets the game over state.
     *
     * @return True if the game is over, false otherwise.
     */
    [[nodiscard]] bool getGameOver() const;

    /**
     * @brief Gets the current difficulty settings based on the selected difficulty level.
     *
     * @return A reference to the current difficulty settings.
     */
    [[nodiscard]] const DifficultySettings& getDifficulty() const;

    /**
     * @brief Removes entities that are out of view.
     *
     * This method removes any entities that are no longer visible within the camera's view.
     */
    void removeRemovableEntities();

    /**
     * @brief Generates the world, including platforms, background, and player.
     *
     * This method initializes and generates the world, including all the entities, platforms, and the player.
     */
    void genWorld();

    /**
     * @brief Checks if the minimum distance between platforms is valid.
     *
     * This method checks if the new platform maintains the minimum required distance from other platforms.
     *
     * @param minDistance The minimum allowed distance between platforms.
     * @param newplat The new platform to check.
     * @return True if the distance is valid, false otherwise.
     */
    [[nodiscard]] bool isValidMinDistance(float minDistance, const std::shared_ptr<Entity>& newplat) const;

    /**
     * @brief Checks if the maximum distance between platforms is valid.
     *
     * This method checks if the new platform maintains the maximum allowed distance from other platforms.
     *
     * @param maxDistance The maximum allowed distance between platforms.
     * @param newplat The new platform to check.
     * @return True if the distance is valid, false otherwise.
     */
    [[nodiscard]] bool isValidMaxDistance(float maxDistance, const std::shared_ptr<Entity>& newplat) const;

    /**
     * @brief Generates new platforms in the world.
     *
     * This method generates platforms at random positions within a given vertical range.
     *
     * @param fromy The starting Y-coordinate for platform generation.
     * @param toy The ending Y-coordinate for platform generation.
     */
    void genPlats(float fromy, float toy);

    /**
     * @brief Updates the player entity based on the time delta.
     *
     * This method updates the player's position, state, and other properties based on the elapsed time.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void updatePlayer(float deltaTime) const;

    /**
     * @brief Updates all entities in the world.
     *
     * This method updates the position and state of all entities in the world.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void updateEntities(float deltaTime);

    /**
     * @brief Checks for collisions between all entities in the world.
     *
     * This method checks if any entities are colliding with each other.
     */
    void checkCollisions();

    /**
     * @brief Generates new platforms if needed.
     *
     * This method generates new platforms based on the current state of the world.
     */
    void generateNewPlatforms();

    /**
     * @brief Updates the camera's position based on the player's Y-coordinate.
     *
     * This method adjusts the camera to follow the player's movements.
     */
    void updateCamera();

    /**
     * @brief Sets the game over state.
     *
     * This method sets whether the game is over or not.
     *
     * @param gameOver True if the game is over, false otherwise.
     */
    void setGameOver(bool gameOver);

    /**
     * @brief Checks if the game is over based on the player's position.
     *
     * This method checks if the player's position indicates the game should end.
     */
    void checkGameOver();

    /**
     * @brief Generates bonus platforms.
     *
     * This method generates bonus platforms that provide rewards or special abilities to the player.
     *
     * @param entity The platform entity that may spawn a bonus.
     */
    void genBonus(const std::shared_ptr<Platform>& entity);

    /**
     * @brief Updates bonus platforms based on the time delta.
     *
     * This method updates the state of all bonus platforms.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void updateBonuses(float deltaTime);

    /**
     * @brief Generates background tiles for the world.
     *
     * This method generates the background tiles within the specified vertical range.
     *
     * @param from_y The starting Y-coordinate for background generation.
     * @param to_y The ending Y-coordinate for background generation.
     */
    void generateBackground(float from_y, float to_y);

    /**
     * @brief Updates the background tiles based on the time delta.
     *
     * This method updates the state of all background tiles.
     *
     * @param deltaTime The time elapsed since the last update.
     */
    void updateBackground(float deltaTime);

    /**
     * @brief Generates new background tiles.
     *
     * This method generates new background tiles when needed based on the current state of the world.
     */
    void generateNewTiles();

    /**
     * @brief Checks for collisions between the player and bonus platforms.
     *
     * This method checks if the player has collided with any bonus platforms.
     */
    void CheckBonusCollision();

    /**
     * @brief Checks the current difficulty level and adjusts it based on the player's score.
     *
     * This method updates the difficulty level based on the player's performance.
     */
    void CheckDifficulty();

    /**
     * @brief Moves the player in the specified direction.
     *
     * This method moves the player left or right based on the provided direction.
     *
     * @param direction The direction to move the player (positive for right, negative for left).
     */
    void PlayerMove(int direction) const;

private:
    std::shared_ptr<Player> player; ///< Shared pointer to the player entity.
    std::vector<std::shared_ptr<Platform>> entities; ///< List of platforms and other entities in the world.
    std::vector<std::shared_ptr<Entity>> background; ///< List of background tiles.
    std::vector<std::shared_ptr<Bonus>> bonuses; ///< List of bonus entities.
    std::shared_ptr<Score> score; ///< Current score object.
    std::shared_ptr<AbstractFactory> factory; ///< Factory used to create entities.
    Camera camera; ///< Camera object for managing the view.
    int ActivePlatforms = 0; ///< Number of active platforms in the world.
    bool isGameOver = false; ///< Game over state.
    Difficulty difficulty = Difficulty::EASY; ///< Default difficulty level.
};

#endif // WORLD_H
