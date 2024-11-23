// Created by karan on 14/11/2024.

#include "EntityView.h"
#include "Entity.h"  // Include the Entity class for reference

// Constructor to initialize the view with the associated entity
EntityView::EntityView(Entity& entity, sf::RenderWindow& window) : entity(entity), CurrentWindow(window) {
   //DO NOTHING, JUST INITIALIZE THE ENTITY (BASE CLASS)
}
void EntityView::update() {
    setPosition();
}

// The render method could be implemented here, but it's left as virtual to be overridden
// by derived classes for specific rendering logic
void EntityView::render() {
    if (texture.getSize().x > 0) { // Check if texture is loaded
        CurrentWindow.draw(sprite); // Draw the sprite if texture is loaded
    } else {
        CurrentWindow.draw(fallbackShape); // Draw the fallback shape if texture loading failed
    }
}

void EntityView::setPosition() {
    if(isTextureLoaded){
        sprite.setPosition(entity.getX(), entity.getY()); // Set the position of the sprite
    }else {
        fallbackShape.setPosition(entity.getX()-entity.getWidth()/2,entity.getY()-entity.getHeight()/2);
    }
}