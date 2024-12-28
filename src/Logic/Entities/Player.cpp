// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(float x, float y) : Entity(x, y) {
    width = 60; // width in pixels
    height = 80; // height in pixels
    velocityX = 4.0f; // horizontal velocity in pixels per second
    EntityType_var = EntityType::PLAYER; // set entity type to player
    collidable = false; // set player to collidable
}

void Player::update(float deltaTime) {
    // Check if the player is falling or jumping
    if(velocityY>=0) {
        setFalling();
    }else {
        setJumping();
    }

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
    BonusEffectTime -= deltaTime;
    std::cout<<BonusEffectTime<<std::endl;
    // Handle bonus effects
    if (BonusEffect && BonusEffectTime < 0) {
        BonusEffect = false; // Reset bonus effect
        jumpForce = 500.0f; // Reset jump force to normal value
        gravity = 8.0f;
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
    float newX = getX() + (direction * velocityX); // Calculate new x position
    if(direction == -1) {
        isgoingleft = true;
    } else {
        isgoingleft = false;
    }
    // Wrap around logic
    if (newX > 500) {
        newX = 0; // Wrap to the left side
    } else if (newX < 0) {
        newX = 500; // Wrap to the right side
    }

    setPosition(newX, getY()); // Update the player's position
}

void Player::applyBonusEffect(BonusType bonusType) {
    if(bonusType == BonusType::JETPACK) {
        BonusEffect = true;
        gravity = -2.0f; // Set gravity to 0
        BonusEffectTime = 2.0f; // Set bonus effect time
    } else if(bonusType == BonusType::SPRING) {
        BonusEffect = true;
        jumpForce = 1500.0f; // Increase jump force
        gravity= 5.0f; // Decrease gravity
        BonusEffectTime = 1.0f; // Set bonus effect time
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


void Player::setCWP(bool CWP) {
    CollisionWithPlatform = CWP;
}



