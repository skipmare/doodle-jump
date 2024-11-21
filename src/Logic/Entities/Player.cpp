// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(float x, float y) : Entity(x, y) {
    width = 40; // width in pixels
    height = 50; // height in pixels
    velocityX = 5.0f; // horizontal velocity in pixels per second
    EntityType = EntityType::PLAYER; // set entity type to player
}

void Player::update(float deltaTime) {
    // Apply gravity
    if (isFallingState || isJumpingState) {
        velocityY += gravity; // Increase downward velocity due to gravity
        if(velocityY >= 0) {
            setFalling();
        }else {
            setJumping();
        }
    }

    // Update the player's vertical position
    setPosition(getX(), getY() + velocityY * deltaTime);

    // Check if the player has landed (pseudo-code for collision detection)
    if (getHasCollided()) {
        //do something
    }
}

void Player::jump() {
    if (!isJumpingState) { // Check if the player is not already jumping (mid-air)
        velocityY = -jumpForce; // Set a negative velocity for jumping
        isJumpingState = true; // Set the jumping state
        isFallingState = false; // Reset falling state
    }
}

// method to move player to left or right
void Player::move(int direction) {
    // 1 for right, -1 for left
    setPosition(getX() + (direction * velocityX), getY());
}

void Player::applyBonusEffect(BonusType bonusType) {
    BonusEffect = true;
    if(bonusType == BonusType::JETPACK) {


    } else if(bonusType == BonusType::SPRING) {
        // Apply spring effect
    }
}

// set player to falling state
void Player::setFalling() {
    isFallingState = true;
    isJumpingState = false;
}

// set player to jumping state
void Player::setJumping() {
    isJumpingState = true;
    isFallingState = false;
}

