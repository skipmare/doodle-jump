//
// Created by karan on 14/11/2024.
//

#include "Player.h"

#include <Platforms/Platform.h>

Player::Player(int x, int y) : Entity(x, y) {
    width = 3;
    height = 3;
}

Player::~Player() {}

void Player::update(float deltaTime) {
    // Update the player
}

