//
// Created by Skip on 16/11/2024.
//

#ifndef SPRING_H
#define SPRING_H

#include "Bonus.h"

/// @file Spring.h
/// @brief Declares the Spring class, which represents a specific type of bonus.

/// @class Spring
/// @brief Represents a Spring bonus item.
///
/// This class extends the `Bonus` class and represents a specific type of bonus (SPRING).
class Spring : public Bonus {
public:
    /// @brief Constructs a Spring object.
    /// @param x The initial x-coordinate of the Spring.
    /// @param y The initial y-coordinate of the Spring.
    /// @param platform The platform on which the Spring is placed.
    Spring(float x, float y, const std::shared_ptr<Platform>& platform);

    /// @brief Default destructor for the Spring class.
    ~Spring() override = default;
};

#endif //SPRING_H
