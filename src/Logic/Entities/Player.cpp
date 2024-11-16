//
// Created by karan on 14/11/2024.
//

#include "Player.h"

#include <Platforms/Platform.h>

Player::Player(float x, float y) : Entity(x, y) {
    width = 40; // width in pixels
    height = 50; // height in pixels
    velocityY = 10; // vertical velocity
    velocityX = 8; // horizontal velocity
}

void Player::update(float deltaTime) {
    // Update the player; complex because needs user input
}

void Player::jump() {
    // Jump the player
}