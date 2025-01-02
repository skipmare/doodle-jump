//
// Created by Skip on 15/11/2024.
//

#include "DisappearingPlatform.h"

/// @file DisappearingPlatform.cpp
/// @brief Implements the DisappearingPlatform class methods.

/// @brief Constructs a DisappearingPlatform object.
/// @param x The initial x-coordinate of the platform.
/// @param y The initial y-coordinate of the platform.
DisappearingPlatform::DisappearingPlatform(float x, float y) : StaticPlatform(x, y) {
    type = PlatformType::DISAPPEARING; ///< Set the platform type to disappearing.
    disappeared = false; ///< Initially, the platform has not disappeared.
    jumptrigger = false; ///< Jump trigger is disabled by default.
}

/// @brief Default destructor for the DisappearingPlatform class.
DisappearingPlatform::~DisappearingPlatform() = default;

/// @brief Updates the platform state.
/// @param deltaTime The time elapsed since the last update.
///
/// If the platform has collided with another entity, it will be marked as out of view.
void DisappearingPlatform::update(float deltaTime) {
    if (hasCollided) {
        this->setOutOfView(true);
    }
    notify(); ///< Notify observers of the state change.
}

/// @brief Checks if the platform has disappeared.
/// @return `true` if the platform has disappeared, otherwise `false`.
bool DisappearingPlatform::isDisappeared() const {
    return disappeared;
}
