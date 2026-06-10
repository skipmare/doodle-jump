/// @file Player.h
/// @brief Defines the Player class, which represents the player character in the game.

#ifndef INC_2024_PROJECT_SKIPMARE_PLAYER_H
#define INC_2024_PROJECT_SKIPMARE_PLAYER_H

#include "Entity.h"

/// @brief Represents the player in the game.
class Player : public Entity {
public:
    // These produce a roughly 210 px apex and 1.08 second full jump: compact but controllable.
    static constexpr float NormalGravity = 1450.0f;
    static constexpr float NormalJumpSpeed = 780.0f;
    static constexpr float MaximumFallSpeed = 1050.0f;
    // Full speed arrives in about 0.14 seconds; release braking is deliberately quicker.
    static constexpr float MaximumMoveSpeed = 400.0f;
    static constexpr float MoveAcceleration = 2800.0f;
    static constexpr float MoveDeceleration = 3600.0f;
    // Matches the visible feet in the sprite instead of treating the nose/body as landing contact.
    static constexpr float LandingFootWidth = 30.0f;
    static constexpr float LandingFootOffset = 7.0f;

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
    /// @param deltaTime Time elapsed since the last update, in seconds.
    void move(int direction, float deltaTime);

    /// @brief Sets horizontal input for the next update (-1, 0, or 1).
    void setMoveDirection(int direction);

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

    /// @brief Gets the player's y-coordinate before the most recent update.
    [[nodiscard]] float getPreviousY() const { return previousY; }

    /// @brief Gets the narrow, direction-aware contact box under the player's visible feet.
    [[nodiscard]] BoundingBox getLandingBox() const;

    /// @brief Gets the player's jump force.
    /// @return The force applied when the player jumps.
    [[nodiscard]] float getJumpForce() const { return jumpForce; }

    /// @brief Gets the player's gravity value.
    /// @return The gravity affecting the player.
    [[nodiscard]] float getGravity() const { return gravity; }

    /// @brief Sets the player to the jumping state.
    void setJumping();

    /// @brief Sets the player to the falling state.
    void setFalling();

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
    void updateHorizontalMovement(float deltaTime);
    void wrapHorizontally();

    bool isJumpingState = false; ///< Indicates whether the player is jumping.
    bool isFallingState = false; ///< Indicates whether the player is falling.
    float gravity = NormalGravity;      ///< Gravity affecting the player in pixels per second squared.
    float jumpForce = NormalJumpSpeed;  ///< Force applied when the player jumps.
    int moveDirection = 0; ///< Current horizontal input direction.
    bool BonusEffect = false;    ///< Indicates whether a bonus effect is active.
    bool isgoingleft = false;    ///< Indicates whether the player is moving left.
    float BonusEffectTime = 0.0f; ///< Time remaining for the bonus effect.
    float previousY = 0.0f; ///< Y-coordinate before the most recent update.
};

#endif // INC_2024_PROJECT_SKIPMARE_PLAYER_H
