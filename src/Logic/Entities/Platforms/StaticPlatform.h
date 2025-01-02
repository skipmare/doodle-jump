//
// Created by Skip on 15/11/2024.
//

#ifndef STATICPLATFORM_H
#define STATICPLATFORM_H

#include "Platform.h"

/// @file StaticPlatform.h
/// @brief Declares the StaticPlatform class, which represents a static platform in the game.

/// @class StaticPlatform
/// @brief Represents a static platform in the game, which does not move.
/// 
/// This class extends the `Platform` class, and is used to create platforms that remain in a fixed position.
class StaticPlatform : public Platform {
public:
    /// @brief Constructs a StaticPlatform object.
    /// @param x The initial x-coordinate of the platform.
    /// @param y The initial y-coordinate of the platform.
    StaticPlatform(float x, float y);

    /// @brief Default destructor for the StaticPlatform class.
    ~StaticPlatform() override;
};

#endif // STATICPLATFORM_H
