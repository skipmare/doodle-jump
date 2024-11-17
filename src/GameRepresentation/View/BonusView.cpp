// Created by karan on 14/11/2024.

#include "BonusView.h"
#include <SFML/Graphics.hpp>  // For rendering

// Constructor that accepts a Bonus entity reference
BonusView::BonusView(Bonus& bonus) : EntityView(bonus), bonus(bonus) {
    loadTexture();  // Load the texture based on bonus type
    setPosition();  // Set the initial position of the bonus sprite
}

// Update method to handle bonus-specific animation or effects
void BonusView::update(float deltaTime) {
    // Here, we can apply animations or effects related to the bonus
    // For example, handle the duration of the bonus or any active state effects
    // For now, we'll just keep the position updated as per the bonus position

    setPosition();  // Update the position based on the bonus' current position

    // Example: If bonus is active, do something with it (animations, effects)
}

// Load the texture based on the bonus type
void BonusView::loadTexture() {
    std::string textureFile;  // Variable to hold the texture file path

    // Load different textures based on bonus type
    switch (bonus.getType()) {  // Assuming 'getType()' returns the BonusType enum
        case BonusType::JETPACK:
            textureFile = "jetpack_bonus.png";  // Path to jetpack bonus texture
            break;
        case BonusType::SPRING:
            textureFile = "spring_bonus.png";  // Path to spring bonus texture
            break;
        default:
            textureFile = "default_bonus.png";  // Fallback texture if type is unknown
            break;
    }

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        sprite.setTexture(texture);  // Apply the texture to the sprite
    } else {
        // If texture loading fails, set a fallback color (could be any color you prefer)
        sprite.setColor(sf::Color::Yellow);  // Fallback color in case of texture load failure
    }
}

// Set sprite position based on bonus position
void BonusView::setPosition() {
    sprite.setPosition(bonus.getX(), bonus.getY());  // Set the sprite's position based on bonus position
}
