/// @file Player.cpp
#include "Player.h"
#include <algorithm>
#include <cmath>

// Definitions keep the constants compatible with the project's older MinGW toolchain.
constexpr float Player::NormalGravity;
constexpr float Player::NormalJumpSpeed;
constexpr float Player::MaximumFallSpeed;
constexpr float Player::MaximumMoveSpeed;
constexpr float Player::MoveAcceleration;
constexpr float Player::MoveDeceleration;
constexpr float Player::LandingFootWidth;
constexpr float Player::LandingFootOffset;

/// @brief Constructs a Player object with specified position.
/// @param x Initial x-coordinate.
/// @param y Initial y-coordinate.
Player::Player(float x, float y) : Entity(x, y), previousY(y) {
    width = 60; ///< Width of the player in pixels.
    height = 80; ///< Height of the player in pixels.
    velocityX = 0.0f; ///< Horizontal velocity starts at rest and accelerates from input.
    EntityType_var = EntityType::PLAYER; ///< Sets entity type to player.
    collidable = false; ///< Indicates whether the player is collidable.
}

/// @brief Updates the player's state based on the elapsed time.
/// @param deltaTime Time elapsed since the last update in seconds.
void Player::update(float deltaTime) {
    previousY = getY();
    updateHorizontalMovement(deltaTime);

    /// Check if the player is falling or jumping.
    if (velocityY >= 0) {
        setFalling();
    } else {
        setJumping();
    }

    /// Apply gravity if the player is falling or jumping.
    if (isFallingState || isJumpingState) {
        const float previousVelocityY = velocityY;
        velocityY = std::min(velocityY + gravity * deltaTime, MaximumFallSpeed);
        setPosition(getX(), getY() + (previousVelocityY + velocityY) * 0.5f * deltaTime);
    }

    BonusEffectTime -= deltaTime;

    /// Handle bonus effects expiration.
    if (BonusEffect && BonusEffectTime < 0) {
        BonusEffect = false; ///< Resets bonus effect.
        jumpForce = NormalJumpSpeed; ///< Resets jump force to normal value.
        gravity = NormalGravity;
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
void Player::move(int direction, float deltaTime) {
    setMoveDirection(direction);
    updateHorizontalMovement(deltaTime);
}

void Player::setMoveDirection(int direction) {
    moveDirection = std::max(-1, std::min(1, direction));
    if (moveDirection != 0) {
        isgoingleft = moveDirection < 0;
    }
}

void Player::updateHorizontalMovement(float deltaTime) {
    const float targetVelocity = moveDirection * MaximumMoveSpeed;
    const bool reversing = moveDirection != 0 && velocityX * moveDirection < 0.0f;
    const float acceleration =
        moveDirection == 0 ? MoveDeceleration : (reversing ? MoveDeceleration : MoveAcceleration);
    const float velocityChange = acceleration * deltaTime;

    const float previousVelocityX = velocityX;
    if (velocityX < targetVelocity) {
        velocityX = std::min(velocityX + velocityChange, targetVelocity);
    } else if (velocityX > targetVelocity) {
        velocityX = std::max(velocityX - velocityChange, targetVelocity);
    }

    setPosition(getX() + (previousVelocityX + velocityX) * 0.5f * deltaTime, getY());
    wrapHorizontally();
}

void Player::wrapHorizontally() {
    const float halfWidth = width / 2.0f;
    if (getX() - halfWidth > 500.0f) {
        setPosition(-halfWidth, getY());
    } else if (getX() + halfWidth < 0.0f) {
        setPosition(500.0f + halfWidth, getY());
    }
}

BoundingBox Player::getLandingBox() const {
    const float footCenterX = getX() + (isgoingleft ? LandingFootOffset : -LandingFootOffset);
    const float halfFootWidth = LandingFootWidth / 2.0f;
    const float bottom = getY() + height / 2.0f;
    return {footCenterX - halfFootWidth, footCenterX + halfFootWidth, bottom - 10.0f, bottom};
}

/// @brief Applies a bonus effect to the player.
/// @param bonusType The type of bonus to apply.
void Player::applyBonusEffect(BonusType bonusType) {
    if (bonusType == BonusType::JETPACK) {
        BonusEffect = true;
        gravity = -180.0f; ///< Sustains upward jetpack movement.
        velocityY = -900.0f;
        setJumping();
        BonusEffectTime = 2.0f; ///< Duration of the jetpack effect.
    } else if (bonusType == BonusType::SPRING) {
        BonusEffect = true;
        jumpForce = 1120.0f; ///< Increases jump force.
        velocityY = -jumpForce;
        setJumping();
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
