#include "Platform.h"

/// @file Platform.cpp
/// @brief Implements the Platform class methods.

/// @brief Constructs a Platform object.
/// @param x The initial x-coordinate of the platform.
/// @param y The initial y-coordinate of the platform.
Platform::Platform(float x, float y) : Entity(x, y) {
    width = 80; ///< Set the width of the platform.
    height = 30; ///< Set the height of the platform.
    EntityType_var = EntityType::PLATFORM; ///< Set the entity type to platform.
    collidable = true; ///< Platforms are collidable by default.
    collisionOnLand = true; ///< Platforms can trigger collisions on landing.
}

/// @brief Default destructor for the Platform class.
Platform::~Platform() = default;

/// @brief Updates the platform state.
/// @param deltaTime The time elapsed since the last update.
void Platform::update(float deltaTime) {
    notify(); ///< Notify observers of the state change.
}

/// @brief Gets the platform type.
/// @return The type of the platform.
PlatformType Platform::getPlatformType() const {
    return type;
}
