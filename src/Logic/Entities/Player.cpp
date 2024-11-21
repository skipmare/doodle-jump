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
    // Check if the player is falling or jumping
    if(velocityY>=0) {
        setFalling();
    }else {
        setJumping();
    }
    std::cout<<"velocityY: "<<velocityY<<std::endl;

    // Apply gravity
    if (isFallingState || isJumpingState) {
        velocityY += gravity; // Increase downward velocity due to gravity
    }

    // Update the player's vertical position
    setPosition(getX(), getY() + velocityY * deltaTime);

    //check if player has collided with a platform or bonus (World does this and sets the collision state)
    if (getHasCollided()) {
        // Reset states when landing
        jump(); // Set player to jumping state
        setJumping(); // Set player to jumping state
        SetHasCollided(false); // Reset collision state
    }

    // Handle bonus effects
    if (BonusEffect && isFalling()) {
        BonusEffect = false; // Reset bonus effect
        jumpForce = 250.0f; // Reset jump force to normal value
    }
}

void Player::jump() {
    if (!isJumpingState) { // Check if the player is not already jumping (mid-air)
        std::cout << "Jumping!" << std::endl; // Print a message
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
        jumpForce = 500.0f; // Increase jump force
    } else if(bonusType == BonusType::SPRING) {
        jumpForce = 750.0f; // Increase jump force
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

void Player::SetHasCollided(bool collisionBool) {
    hasCollided = collisionBool;
}
