//
// Created by Skip on 15/11/2024.
//

#include "HorizontalPlatform.h"

/// @brief Constructs a HorizontalPlatform object.
HorizontalPlatform::HorizontalPlatform(float x, float y) : Platform(x, y) {
    type = PlatformType::HORIZONTAL; ///< Set the platform type to HORIZONTAL.
    velocityX = 55.0f; ///< Set the horizontal velocity for movement.
}

/// @brief Default destructor for the HorizontalPlatform class.
HorizontalPlatform::~HorizontalPlatform() = default;

/// @brief Updates the platform's horizontal position based on the velocity.
void HorizontalPlatform::update(float deltaTime) {
    float newX = x + velocityX * deltaTime; ///< Calculate new x-position based on velocity.

    // Check if the platform has moved out of the screen width.
    if (newX - width / 2 < 0) {
        newX = width / 2; ///< Set newX to the left boundary.
        velocityX = -velocityX; ///< Reverse direction when reaching the left boundary.
    } else if (newX + width / 2 > 500) {
        newX = 500 - width / 2; ///< Set newX to the right boundary.
        velocityX = -velocityX; ///< Reverse direction when reaching the right boundary.
    }

    // Use setPosition to update the position of the platform.
    setPosition(newX, getY()); ///< Assuming getY() returns the current y position.
}
