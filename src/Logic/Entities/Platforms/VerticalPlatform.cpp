//
// Created by Skip on 15/11/2024.
//

#include "VerticalPlatform.h"

/// @brief Constructs a VerticalPlatform object.
VerticalPlatform::VerticalPlatform(float x, float y) : Platform(x, y) {
    velocityY = 30.0f; ///< Set the vertical velocity for movement.
    type = PlatformType::VERTICAL; ///< Set the platform type to VERTICAL.
    initialY = y; ///< Store the initial y-coordinate for vertical movement.
}

/// @brief Default destructor for the VerticalPlatform class.
VerticalPlatform::~VerticalPlatform() = default;

/// @brief Updates the platform's vertical position based on the velocity.
void VerticalPlatform::update(float deltaTime) {
    float newY = y + velocityY * deltaTime; ///< Calculate new y-position based on velocity.

    // Check if the platform has moved out of the allowed range.
    float Maxupwards = initialY - 50;
    float Maxdownwards = initialY + 50;

    if (newY < Maxupwards) {
        velocityY = -velocityY; ///< Reverse direction when reaching the upper boundary.
    } else if (newY > Maxdownwards) {
        velocityY = -velocityY; ///< Reverse direction when reaching the lower boundary.
    } else {
        y = newY; ///< Update the platform's y-position.
        notify(); ///< Notify observers (if any).
    }
}

/// @brief Sets the position of the platform, including vertical position adjustments.
void VerticalPlatform::setPosition(float x, float initialY) {
    this->x = x; ///< Update the x-coordinate.
    float diff = this->initialY - initialY; ///< Calculate the vertical difference.
    this->initialY = initialY; ///< Update the initial y-coordinate.
    this->y = this->y - diff; ///< Adjust the platform's current y-position.
    notify(); ///< Notify observers (if any).
}
