//
// Created by Skip on 15/11/2024.
//

#include "VerticalPlatform.h"

// Constructor
VerticalPlatform::VerticalPlatform(float x, float y) : Platform(x, y) {
    velocityY = 30.0f;
    type = PlatformType::VERTICAL;
    initialY = y;
}

// Destructor
VerticalPlatform::~VerticalPlatform() = default;

// Updates the platform
void VerticalPlatform::update(float deltaTime) {
    float newY = y + velocityY * deltaTime; // Calculate new position
    float Maxupwards = initialY + 50;
    float Maxdownwards = initialY - 50;

    // Check if the platform is going out of the screen bounds
    if (newY < 0) {
        y = 0;
        velocityY = -velocityY; // Reverse direction
    } else if (newY > 800) {
        y = 800;
        velocityY = -velocityY; // Reverse direction
    } else if (newY > Maxupwards) {
        y = Maxupwards;
        velocityY = -velocityY; // Reverse direction
    } else if (newY < Maxdownwards) {
        y = Maxdownwards;
        velocityY = -velocityY; // Reverse direction
    } else {
        y = newY;
        notify();
    }
}



