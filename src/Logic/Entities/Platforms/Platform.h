//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_PLATFORM_H
#define INC_2024_PROJECT_SKIPMARE_PLATFORM_H

#include "../Entity.h"

/// @file Platform.h
/// @brief Declares the Platform class, which represents a platform in the game.

/// @class Platform
/// @brief Represents a platform that can be interacted with in the game world.
///
/// This class is used to create platforms that entities can collide with or stand on.
class Platform : public Entity {
public:
    /// @brief Constructs a Platform object.
    /// @param x The initial x-coordinate of the platform.
    /// @param y The initial y-coordinate of the platform.
    Platform(float x, float y);

    /// @brief Default destructor for the Platform class.
    ~Platform() override;

    /// @brief Updates the platform state.
    /// @param deltaTime The time elapsed since the last update.
    ///
    /// This method is called every frame to update the platform's state.
    void update(float deltaTime) override;

    /// @brief Gets the type of the platform.
    /// @return The platform type as a PlatformType enum.
    [[nodiscard]] PlatformType getPlatformType() const;

    /// @brief Gets the initial y-coordinate of the platform.
    /// @return The initial y-coordinate.
    [[nodiscard]] float getInitialY() const { return initialY; }

protected:
    float initialY; ///< The initial y-coordinate of the platform, used for resetting.
    PlatformType type; ///< The type of the platform (e.g., static, horizontal, vertical).
};

#endif // INC_2024_PROJECT_SKIPMARE_PLATFORM_H
