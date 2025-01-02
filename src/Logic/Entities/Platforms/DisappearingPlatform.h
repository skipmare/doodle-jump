//
// Created by Skip on 15/11/2024.
//

#ifndef DISAPPEARINGPLATFORM_H
#define DISAPPEARINGPLATFORM_H

#include "StaticPlatform.h"

/// @file DisappearingPlatform.h
/// @brief Declares the DisappearingPlatform class.

/// @class DisappearingPlatform
/// @brief A platform that disappears when certain conditions are met.
///
/// This class represents a platform that disappears after a collision or another event.
class DisappearingPlatform : public StaticPlatform {
public:
    /// @brief Constructs a DisappearingPlatform object.
    /// @param x The initial x-coordinate of the platform.
    /// @param y The initial y-coordinate of the platform.
    DisappearingPlatform(float x, float y);

    /// @brief Default destructor.
    ~DisappearingPlatform() override;

    /// @brief Updates the platform state.
    /// @param deltaTime The time elapsed since the last update.
    void update(float deltaTime) override;

    /// @brief Checks if the platform has disappeared.
    /// @return `true` if the platform has disappeared, otherwise `false`.
    [[nodiscard]] bool isDisappeared() const;

    /// @brief Plays the disappear sound effect.
    void playDisappearSound();

private:
    bool disappeared; ///< Indicates whether the platform has disappeared.
};

#endif // DISAPPEARINGPLATFORM_H
