#include "Entity.h"

/// @file Entity.cpp
/// @brief Implements the Entity class methods.

/// @brief Constructs an Entity object with the specified initial position.
/// @param x The initial x-coordinate of the entity.
/// @param y The initial y-coordinate of the entity.
Entity::Entity(float x, float y) : x(x), y(y) {}

/// @brief Destructor for the Entity class.
Entity::~Entity() = default;

/// @brief Gets the x-coordinate of the entity.
/// @return The current x-coordinate.
float Entity::getX() const {
    return x;
}

/// @brief Gets the y-coordinate of the entity.
/// @return The current y-coordinate.
float Entity::getY() const {
    return y;
}

/// @brief Sets the position of the entity.
/// @param x The new x-coordinate.
/// @param y The new y-coordinate.
void Entity::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
    notify(); ///< Notify observers of the position change.
}

/// @brief Updates the entity's position based on its velocity.
/// @param deltaTime The time elapsed since the last update, in seconds.
void Entity::update(float deltaTime) {
    x += velocityX * deltaTime; ///< Update the x-coordinate.
    y += velocityY * deltaTime; ///< Update the y-coordinate.
}

/// @brief Calculates and retrieves the bounding box of the entity.
/// @return A BoundingBox struct representing the entity's bounds.
BoundingBox Entity::getBoundingBox() const {
    return { x - width / 2, x + width / 2, y - height / 2, y + height / 2 };
}

/// @brief Sets whether the entity is out of view.
/// @param outOfView True if the entity is out of view, false otherwise.
void Entity::setOutOfView(bool outOfView) {
    this->outOfView = outOfView;
}

/// @brief Checks if the entity is out of view.
/// @return True if the entity is out of view, false otherwise.
bool Entity::getOutOfView() const {
    return outOfView;
}

/// @brief Sets the collision state of the entity.
/// @param hasCollided True if the entity has collided, false otherwise.
void Entity::setHasCollided(bool hasCollided) {
    this->hasCollided = hasCollided;
}
