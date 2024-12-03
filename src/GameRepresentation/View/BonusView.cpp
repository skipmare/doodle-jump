#include "BonusView.h"
#include <iostream> // For error handling

// Constructor that accepts a Bonus entity reference
BonusView::BonusView(std::shared_ptr<Bonus> bonus, std::shared_ptr<sf::RenderWindow> window) : EntityView(bonus, window), bonus(bonus) {
    loadTexture();  // Load the texture based on bonus type
    this->setPosition();  // Set the initial position of the bonus sprite
}

// Load the texture based on the bonus type
void BonusView::loadTexture() {
    std::string textureFile;  // Variable to hold the texture file path

    // Load different textures based on bonus type
    switch (bonus->getType()) {  // Assuming 'getType()' returns the BonusType enum
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
        fallbackShape.setSize(sf::Vector2f(bonus->getWidth(), bonus->getHeight())); // Set a default size for the fallback shape
        fallbackShape.setPosition(bonus->getX() - bonus->getWidth()/2, bonus->getY() - bonus->getHeight()/2); // Center the rectangle
        std::cerr << "Failed to load texture from: " << textureFile << std::endl; // Log the error
    }
}


