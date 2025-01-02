//
// Created by karan on 14/11/2024.
//

#include "BGtile.h"

/// @file BGtile.cpp
/// @brief Implements the methods for the BGtile class.

/// @brief Updates the background tile's state.
/// @param deltaTime The time elapsed since the last update, in seconds.
///
/// This method notifies any observers about the state changes of the background tile.
void BGtile::update(float deltaTime) {
    notify(); ///< Notify observers of state changes.
}

/// @brief Constructs a BGtile object with the specified initial position.
/// @param x The initial x-coordinate of the background tile.
/// @param y The initial y-coordinate of the background tile.
///
/// Initializes the background tile with default dimensions and sets its type to `BG_TILE`.
BGtile::BGtile(float x, float y) : Entity(x, y) {
    width = 40; ///< Set the width of the tile.
    height = 40; ///< Set the height of the tile.
    EntityType_var = EntityType::BG_TILE; ///< Set the entity type to background tile.
    collidable = false; ///< Background tiles are not collidable.
}
