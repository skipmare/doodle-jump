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
    float Maxupwards = initialY - 50;
    float Maxdownwards = initialY + 50;

    // Check if the platform is going out of the allowed range
    if (newY < Maxupwards) {
        velocityY = -velocityY; // Reverse direction
    } else if (newY > Maxdownwards) {
        velocityY = -velocityY; // Reverse direction
    } else {
        y = newY;
        notify();
    }
}

// Set the position of the platform, gets called to change the initial position of the platform
void VerticalPlatform::setPosition(float x, float initialY) {
    this->x = x;
    float diff = this->initialY - initialY;
    this->initialY = initialY;
    this->y = this->y - diff;
    notify();
}



