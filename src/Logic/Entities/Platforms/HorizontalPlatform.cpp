//
// Created by Skip on 15/11/2024.
//

#include "HorizontalPlatform.h"

// Constructor
HorizontalPlatform::HorizontalPlatform(float x, float y) : Platform(x, y) {
    type = PlatformType::HORIZONTAL;
    velocityX = 55.0f;
}

// Destructor
HorizontalPlatform::~HorizontalPlatform() = default;

// Updates the platform
void HorizontalPlatform::update(float deltaTime) {
    float newX = x + velocityX * deltaTime; // Calculate new position

    // Check if the platform is going out of the screen width
    if (newX - width / 2 < 0) {
        x = width / 2;
        velocityX = -velocityX; // Reverse direction
    } else if (newX + width / 2 > 500) {
        x = 500 - width / 2;
        velocityX = -velocityX; // Reverse direction
    } else {
        x = newX;
    }
}


