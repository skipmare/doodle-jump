//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_BGTILE_H
#define INC_2024_PROJECT_SKIPMARE_BGTILE_H

#include "Entity.h"

/// @file BGtile.h
/// @brief Declares the BGtile class, representing background tiles in the game.

/// @class BGtile
/// @brief A class representing a background tile entity.
///
/// The BGtile class is a derived class of `Entity` that provides specific
/// behavior for background tiles in the game world.
class BGtile : public Entity {
public:
    /// @brief Constructs a BGtile object with the specified initial position.
    /// @param x The initial x-coordinate of the background tile.
    /// @param y The initial y-coordinate of the background tile.
    BGtile(float x, float y);

    /// @brief Default destructor.
    ~BGtile() override = default;

    /// @brief Updates the background tile's state.
    /// @param deltaTime The time elapsed since the last update, in seconds.
    void update(float deltaTime) override;
};

#endif // INC_2024_PROJECT_SKIPMARE_BGTILE_H
