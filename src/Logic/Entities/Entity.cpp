#include "Entity.h"

// Constructor of the entity

Entity::Entity(float x, float y) : x(x), y(y) {}

// Destructor of the entity

Entity::~Entity() = default;

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
    notify();
}

// Update the entity

void Entity::update(float deltaTime) {
    x += velocityX * deltaTime;
    y += velocityY * deltaTime;
}


// Calculate all x and y positions of the entity

BoundingBox Entity::getBoundingBox() const {
    return { x - width / 2, x + width / 2, y - height / 2, y + height / 2 };
}
