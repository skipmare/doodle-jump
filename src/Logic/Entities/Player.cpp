/// @file Player.cpp
#include "Player.h"
#include <iostream>

/// @brief Constructs a Player object with specified position.
/// @param x Initial x-coordinate.
/// @param y Initial y-coordinate.
Player::Player(float x, float y) : Entity(x, y) {
    width = 60; ///< Width of the player in pixels.
    height = 80; ///< Height of the player in pixels.
    velocityX = 3.0f; ///< Horizontal velocity in pixels per second.
    EntityType_var = EntityType::PLAYER; ///< Sets entity type to player.
    collidable = false; ///< Indicates whether the player is collidable.
}

/// @brief Updates the player's state based on the elapsed time.
/// @param deltaTime Time elapsed since the last update in seconds.
void Player::update(float deltaTime) {
    /// Check if the player is falling or jumping.
    if (velocityY >= 0) {
        setFalling();
    } else {
        setJumping();
    }

    /// Apply gravity if the player is falling or jumping.
    if (isFallingState || isJumpingState) {
        velocityY += gravity; ///< Increases downward velocity due to gravity.
    }

    /// Update the player's vertical position.
    setPosition(getX(), getY() + velocityY * deltaTime);

    /// Check if the player has collided with a platform or bonus.
    if (getHasCollided()) {
        jump(); ///< Sets player to jumping state.
        setJumping(); ///< Sets player to jumping state.
        SetHasCollided(false); ///< Resets collision state.
    }

    BonusEffectTime -= deltaTime;

    /// Handle bonus effects expiration.
    if (BonusEffect && BonusEffectTime < 0) {
        BonusEffect = false; ///< Resets bonus effect.
        jumpForce = 650.0f; ///< Resets jump force to normal value.
        gravity = 8.0f;
    }
}

/// @brief Makes the player jump.
void Player::jump() {
    if (!isJumpingState) { ///< Checks if the player is not already jumping (mid-air).
        velocityY = -jumpForce; ///< Sets a negative velocity for jumping.
        isJumpingState = true; ///< Sets the jumping state.
        isFallingState = false; ///< Resets the falling state.
    }
}

/// @brief Moves the player left or right.
/// @param direction Direction of movement (1 for right, -1 for left).
void Player::move(int direction) {
    float newX = getX() + (direction * velocityX); ///< Calculates the new x position.

    if (direction == -1) {
        isgoingleft = true;
    } else {
        isgoingleft = false;
    }

    /// Wrap-around logic for screen edges.
    if (newX > 500) {
        newX = 0; ///< Wraps to the left side.
    } else if (newX < 0) {
        newX = 500; ///< Wraps to the right side.
    }

    setPosition(newX, getY()); ///< Updates the player's position.
}

/// @brief Applies a bonus effect to the player.
/// @param bonusType The type of bonus to apply.
void Player::applyBonusEffect(BonusType bonusType) {
    if (bonusType == BonusType::JETPACK) {
        BonusEffect = true;
        gravity = -2.0f; ///< Sets gravity for the jetpack effect.
        BonusEffectTime = 2.0f; ///< Duration of the jetpack effect.
    } else if (bonusType == BonusType::SPRING) {
        BonusEffect = true;
        jumpForce = 1300.0f; ///< Increases jump force.
        BonusEffectTime = 0.5f; ///< Duration of the spring effect.
    }
}

/// @brief Sets the player to the falling state.
void Player::setFalling() {
    isFallingState = true;
    isJumpingState = false;
}

/// @brief Sets the player to the jumping state.
void Player::setJumping() {
    isJumpingState = true;
    isFallingState = false;
}

/// @brief Sets the player's collision state.
/// @param collisionBool True if the player has collided, false otherwise.
void Player::SetHasCollided(bool collisionBool) {
    hasCollided = collisionBool;
}

/// @brief Sets the player's collision with platform state.
/// @param CWP True if the player has collided with a platform, false otherwise.
void Player::setCWP(bool CWP) {
    CollisionWithPlatform = CWP;
}