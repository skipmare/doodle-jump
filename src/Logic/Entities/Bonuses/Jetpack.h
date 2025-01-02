//
// Created by Skip on 16/11/2024.
//

#ifndef JETPACK_H
#define JETPACK_H

#include "Bonus.h"

/// @file Jetpack.h
/// @brief Declares the Jetpack class, which represents a specific type of bonus.

/// @class Jetpack
/// @brief Represents a Jetpack bonus item.
/// 
/// This class extends the `Bonus` class and represents a specific type of bonus (JETPACK).
class Jetpack : public Bonus {
public:
    /// @brief Constructs a Jetpack object.
    /// @param x The initial x-coordinate of the Jetpack.
    /// @param y The initial y-coordinate of the Jetpack.
    /// @param platform The platform on which the Jetpack is placed.
    Jetpack(float x, float y, const std::shared_ptr<Platform>& platform);

    /// @brief Default destructor for the Jetpack class.
    ~Jetpack() override = default;
};

#endif // JETPACK_H
