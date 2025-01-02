//
// Created by Skip on 15/11/2024.
//

#ifndef HORIZONTALPLATFORM_H
#define HORIZONTALPLATFORM_H

#include "Platform.h"

/// @file HorizontalPlatform.h
/// @brief Declares the HorizontalPlatform class.

/// @class HorizontalPlatform
/// @brief A platform that moves horizontally.
///
/// This class represents a platform that moves back and forth horizontally within specified boundaries.
class HorizontalPlatform : public Platform {
public:
    /// @brief Constructs a HorizontalPlatform object.
    /// @param x The initial x-coordinate of the platform.
    /// @param y The initial y-coordinate of the platform.
    HorizontalPlatform(float x, float y);

    /// @brief Default destructor.
    ~HorizontalPlatform() override;

    /// @brief Updates the platform state.
    /// @param deltaTime The time elapsed since the last update.
    void update(float deltaTime) override;
};

#endif // HORIZONTALPLATFORM_H
