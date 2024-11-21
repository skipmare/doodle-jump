// Player.cpp
#include "Player.h"

Player::Player(float x, float y) : Entity(x, y) {
    width = 40; // width in pixels
    height = 50; // height in pixels
    velocityX = 5.0f; // horizontal velocity in pixels per second
}

void Player::update(float deltaTime) {
    // Apply gravity
    if (isFallingState || isJumpingState) {
        velocityY += gravity; // Increase downward velocity due to gravity
    }

    // Update the player's vertical position
    setPosition(getX(), getY() + velocityY * deltaTime);

    // Check if the player has landed (pseudo-code for collision detection)
    if (getHasCollided()) {
        land(); // Call land method when the player touches the ground
    }
}

void Player::jump() {
    if (!isJumpingState) { // Check if the player is not already jumping
        velocityY = -jumpForce; // Set a negative velocity for jumping
        isJumpingState = true; // Set the jumping state
        isFallingState = false; // Reset falling state
    }
}

void Player::land() {
    isJumpingState = false; // Reset jumping state
    isFallingState = false; // Reset falling state
    velocityY = 0; // Reset vertical velocity
}

void Player::move(int direction) {
    // 1 for right, -1 for left
    setPosition(getX() + (direction * velocityX), getY());
}