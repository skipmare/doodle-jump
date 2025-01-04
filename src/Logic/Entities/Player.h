/// @file Player.h
/// @brief Defines the Player class, which represents the player character in the game.

#ifndef INC_2024_PROJECT_SKIPMARE_PLAYER_H
#define INC_2024_PROJECT_SKIPMARE_PLAYER_H

#include "Entity.h"

/// @brief Represents the player in the game.
class Player : public Entity {
public:
    /// @brief Constructs a Player object with the specified initial position.
    /// @param x The initial x-coordinate of the player.
    /// @param y The initial y-coordinate of the player.
    Player(float x, float y);

    /// @brief Updates the player's state.
    /// @param deltaTime Time elapsed since the last update, in seconds.
    void update(float deltaTime) override;

    /// @brief Makes the player jump.
    void jump();

    /// @brief Moves the player left or right.
    /// @param direction The direction to move: 1 for right, -1 for left.
    void move(int direction);

    /// @brief Sets whether the player has collided with an object (platform or bonus).
    /// @param collisionBool True if the player has collided, false otherwise.
    void SetHasCollided(bool collisionBool);

    /// @brief Gets the player's horizontal velocity.
    /// @return The player's horizontal velocity.
    [[nodiscard]] float getVelocityX() const { return velocityX; }

    /// @brief Checks if the player is in a jumping state.
    /// @return True if the player is jumping, false otherwise.
    [[nodiscard]] bool isJumping() const { return isJumpingState; }

    /// @brief Checks if the player is in a falling state.
    /// @return True if the player is falling, false otherwise.
    [[nodiscard]] bool isFalling() const { return isFallingState; }

    /// @brief Gets the player's vertical velocity.
    /// @return The player's vertical velocity.
    [[nodiscard]] float getVelocityY() const { return velocityY; }

    /// @brief Gets the player's jump force.
    /// @return The force applied when the player jumps.
    [[nodiscard]] float getJumpForce() const { return jumpForce; }

    /// @brief Gets the player's gravity value.
    /// @return The gravity affecting the player.
    [[nodiscard]] float getGravity() const { return gravity; }

    /// @brief Checks if the player has collided with a platform.
    /// @return True if the player has collided with a platform, false otherwise.
    [[nodiscard]] bool getCollisionWithPlatform() const { return CollisionWithPlatform; }

    /// @brief Sets whether the player has collided with a platform.
    /// @param CWP True if the player has collided with a platform, false otherwise.
    void setCWP(bool CWP);

    /// @brief Sets the player to the jumping state.
    void setJumping();

    /// @brief Sets the player to the falling state.
    void setFalling();

    /// @brief Sets whether the player is moving left.
    /// @param goingleft True if the player is moving left, false otherwise.
    void setisgoingleft(bool goingleft);

    /// @brief Applies a bonus effect to the player.
    /// @param bonusType The type of bonus to apply.
    void applyBonusEffect(BonusType bonusType);

    /// @brief Sets the player's vertical velocity.
    /// @param velocityY The new vertical velocity.
    void setVelocityY(float velocityY) { this->velocityY = velocityY; }

    /**
     * @brief Checks if the player is moving to the left.
     *
     * This method returns the current movement direction of the player.
     * It indicates whether the player is moving left.
     *
     * @return True if the player is moving to the left, false otherwise.
     */
    bool getisgoingleft() const { return isgoingleft; }

private:
    bool isJumpingState = false; ///< Indicates whether the player is jumping.
    bool isFallingState = false; ///< Indicates whether the player is falling.
    float gravity = 8.0f;        ///< Gravity affecting the player.
    float jumpForce = 650.0f;    ///< Force applied when the player jumps.
    bool hasCollided = false;    ///< Indicates whether the player has collided with an object.
    bool BonusEffect = false;    ///< Indicates whether a bonus effect is active.
    bool isgoingleft = false;    ///< Indicates whether the player is moving left.
    bool CollisionWithPlatform = false; ///< Indicates whether the player has collided with a platform.
    float BonusEffectTime = 0.0f; ///< Time remaining for the bonus effect.
};

#endif // INC_2024_PROJECT_SKIPMARE_PLAYER_H
