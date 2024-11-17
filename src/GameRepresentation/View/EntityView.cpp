// Created by karan on 14/11/2024.

#include "EntityView.h"
#include "Entity.h"  // Include the Entity class for reference

// Constructor to initialize the view with the associated entity
EntityView::EntityView(Entity& entity) : entity(entity) {
    // Initialize the sprite or set any default properties for the sprite
    // In this base class, we don't set a texture, but derived classes can.
}

// The update method could be implemented here, but it's left as virtual to be overridden
// by derived classes since each entity might need its own update logic (e.g., animations)
void EntityView::update(float deltaTime) {
    // Default update logic (if any) can be placed here.
    // Derived classes will override this method for specific updates (animations, movement, etc.)
}

// The render method could be implemented here, but it's left as virtual to be overridden
// by derived classes for specific rendering logic
void EntityView::render(sf::RenderWindow& window) {
    window.draw(sprite);  // Draw the sprite (if applicable)
}
