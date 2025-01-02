//
// Created by Skip on 16/11/2024.
//

#include "Jetpack.h"

/// @brief Constructs a Jetpack object.
Jetpack::Jetpack(float x, float y, const std::shared_ptr<Platform>& platform) : Bonus(x, y, platform) {
    type = JETPACK; ///< Set the bonus type to JETPACK.
    collisionOnLand = false; ///< Jetpack bonus does not trigger collision on landing.
}
