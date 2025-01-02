//
// Created by Skip on 15/11/2024.
//

#include "StaticPlatform.h"

/// @brief Constructs a StaticPlatform object.
StaticPlatform::StaticPlatform(float x, float y) : Platform(x, y) {
    type = PlatformType::STATIC; ///< Set the platform type to STATIC.
}

/// @brief Default destructor for the StaticPlatform class.
StaticPlatform::~StaticPlatform() = default;
