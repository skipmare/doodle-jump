//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_BONUS_H
#define INC_2024_PROJECT_SKIPMARE_BONUS_H

#include "../Entity.h"
#include "../Platforms/Platform.h"
#include "../Utilities/Random.h"

/// @file Bonus.h
/// @brief Declares the Bonus class and its derived classes for different bonus types.

/// @class Bonus
/// @brief Represents a bonus item that can be collected by the player.
///
/// The Bonus class is a base class for different types of bonuses, such as Jetpack and Spring. It tracks the position
/// of the bonus item relative to a platform, and updates its position as the platform moves.
class Bonus : public Entity {
public:
    /// @brief Constructs a Bonus object.
    /// @param x The initial x-coordinate of the bonus.
    /// @param y The initial y-coordinate of the bonus.
    /// @param platform The platform on which the bonus is placed.
    Bonus(float x, float y, const std::shared_ptr<Platform>& platform);

    /// @brief Default destructor for the Bonus class.
    ~Bonus() override = default;

    /// @brief Updates the bonus position based on the platform's movement.
    /// @param deltaTime The time elapsed since the last update.
    void update(float deltaTime) override;

    /// @brief Returns the type of the bonus.
    /// @return The type of the bonus (Jetpack, Spring, etc.).
    [[nodiscard]] BonusType getType() const;

protected:
    BonusType type; ///< The type of the bonus (e.g., Jetpack, Spring).
    std::shared_ptr<Platform> on_platform; ///< The platform on which the bonus is located.
    float prevPlatformX = 0; ///< The previous x-coordinate of the platform.
    float prevPlatformY = 0; ///< The previous y-coordinate of the platform.
};

#endif //INC_2024_PROJECT_SKIPMARE_BONUS_H
