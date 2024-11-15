#include "Entity.h"

// Constructor of the entity

Entity::Entity(int x, int y) : x(x), y(y) {}

// Destructor of the entity

Entity::~Entity() {}

// Get the x position of the entity

float Entity::getX() const {
    return x;
}

// Get the y position of the entity

float Entity::getY() const {
    return y;
}

// Set the position of the entity

void Entity::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

// Update the entity

void Entity::update(float deltaTime) {
    x += velocityX * deltaTime;
    y += velocityY * deltaTime;
}
