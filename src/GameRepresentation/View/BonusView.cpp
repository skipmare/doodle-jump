#include "BonusView.h"
#include <iostream> // For error handling

// Constructor that accepts a Bonus entity reference
BonusView::BonusView(Bonus& bonus) : EntityView(bonus), bonus(bonus) {
    loadTexture();  // Load the texture based on bonus type
    setPosition();  // Set the initial position of the bonus sprite
}

// Update method to handle bonus-specific animation or effects
void BonusView::update() {
    // Update the position based on the bonus' current position
    setPosition();
}

// Load the texture based on the bonus type
void BonusView::loadTexture() {
    std::string textureFile;  // Variable to hold the texture file path

    // Load different textures based on bonus type
    switch (bonus.getType()) {  // Assuming 'getType()' returns the BonusType enum
        case BonusType::JETPACK:
            textureFile = "jetpack_bonus.png";  // Path to jetpack bonus texture
            fallbackShape.setFillColor(sf::Color::Cyan); // Fallback color for jetpack
            break;
        case BonusType::SPRING:
            textureFile = "spring_bonus.png";  // Path to spring bonus texture
            fallbackShape.setFillColor(sf::Color::Magenta); // Fallback color for spring
            break;
        default:
            textureFile = "default_bonus.png";  // Fallback texture if type is unknown
            fallbackShape.setFillColor(sf::Color::Yellow); // Fallback color for unknown
            break;
    }

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        sprite.setTexture(texture);  // Apply the texture to the sprite
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(16, 16)); // Set a default size for the fallback shape
        fallbackShape.setPosition(bonus.getX() - 8, bonus.getY() - 8); // Center the rectangle
        std::cerr << "Failed to load texture from: " << textureFile << std::endl; // Log the error
    }
}

// Set sprite position based on bonus position
void BonusView::setPosition() {
    sprite.setPosition(bonus.getX(), bonus.getY());  // Set the sprite's position based on bonus position
    fallbackShape.setPosition(bonus.getX() - 8, bonus.getY() - 8); // Center the rectangle
}
