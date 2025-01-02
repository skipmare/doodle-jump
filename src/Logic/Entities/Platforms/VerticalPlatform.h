//
// Created by Skip on 15/11/2024.
//

#ifndef VERTICALPLATFORM_H
#define VERTICALPLATFORM_H

#include "Platform.h"
#include <iostream>

/// @file VerticalPlatform.h
/// @brief Declares the VerticalPlatform class, which represents a platform that moves vertically in the game.

/// @class VerticalPlatform
/// @brief Represents a platform that moves up and down in the game.
///
/// This class extends the `Platform` class, and is used to create platforms that oscillate vertically.
class VerticalPlatform : public Platform {
public:
    /// @brief Constructs a VerticalPlatform object.
    /// @param x The initial x-coordinate of the platform.
    /// @param y The initial y-coordinate of the platform.
    VerticalPlatform(float x, float y);

    /// @brief Default destructor for the VerticalPlatform class.
    ~VerticalPlatform() override;

    /// @brief Updates the platform's position based on its vertical movement.
    /// @param deltaTime The time elapsed since the last update.
    void update(float deltaTime) override;

    /// @brief Sets the position of the platform.
    /// @param x The new x-coordinate of the platform.
    /// @param initialY The new y-coordinate (initial position) of the platform.
    void setPosition(float x, float initialY) override;

private:
    float maxtravel = 70.0f; ///< The maximum distance the platform can travel vertically.
};

#endif // VERTICALPLATFORM_H
