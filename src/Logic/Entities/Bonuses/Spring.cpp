//
// Created by Skip on 16/11/2024.
//

#include "Spring.h"

/// @brief Constructs a Spring object.
Spring::Spring(float x, float y, const std::shared_ptr<Platform>& platform) : Bonus(x, y, platform) {
    type = SPRING; ///< Set the bonus type to SPRING.
    collisionOnLand = true; ///< Spring bonus triggers collision on landing.
}
