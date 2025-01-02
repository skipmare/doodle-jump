/**
 * @file BonusView.cpp
 * @brief Implements the BonusView class for rendering bonus entities.
 *
 * This file contains the implementation of the BonusView class. It defines the constructor, destructor, and
 * methods for loading textures and rendering the bonus in the game window.
 */

#include "BonusView.h"
#include <iostream> // For error handling

/**
 * @brief Constructs a BonusView object.
 * @param bonus A shared pointer to the Bonus entity.
 * @param window A shared pointer to the SFML render window.
 */
BonusView::BonusView(const std::shared_ptr<Bonus> &bonus, const std::shared_ptr<sf::RenderWindow> &window)
    : EntityView(bonus, window), bonus(bonus) {
    loadTexture();  // Load the texture based on bonus type
    setPosition();  // Set the initial position of the bonus sprite
}

/**
 * @brief Loads the texture for the bonus.
 *
 * This method loads the appropriate texture based on the bonus type. If loading fails,
 * it creates a fallback shape to represent the bonus.
 */
void BonusView::loadTexture() {
    std::string textureFile;  // Variable to hold the texture file path

    // Load different textures based on bonus type
    switch (bonus->getType()) {
        case BonusType::JETPACK:
            textureFile = "Assets/Sprites/Jetpack.png";  // Path to jetpack bonus texture
            fallbackShape.setFillColor(sf::Color::Cyan); // Fallback color for jetpack
            break;
        case BonusType::SPRING:
            textureFile = "Assets/Sprites/Spring.png";  // Path to spring bonus texture
            fallbackShape.setFillColor(sf::Color::Magenta); // Fallback color for spring
            break;
        default:
            textureFile = "Assets/Sprites/default_bonus.png";  // Fallback texture if type is unknown
            fallbackShape.setFillColor(sf::Color::Yellow); // Fallback color for unknown
            break;
    }

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        sprite.setTexture(texture);  // Apply the texture to the sprite

        // Calculate the scale factors to match the bonus's dimensions
        float scaleX = bonus->getWidth() / static_cast<float>(texture.getSize().x);
        float scaleY = bonus->getHeight() / static_cast<float>(texture.getSize().y);
        sprite.setScale(scaleX, scaleY); // Resize the sprite

        // Set the origin to the center of the sprite
        sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

        // Set the initial position to the bonus's position
        sprite.setPosition(bonus->getX(), bonus->getY());
        isTextureLoaded = true; // Indicate that the texture has been loaded successfully
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(bonus->getWidth(), bonus->getHeight())); // Set a default size for the fallback shape
        fallbackShape.setPosition(bonus->getX() - bonus->getWidth() / 2, bonus->getY() - bonus->getHeight() / 2); // Center the rectangle

        // Set the outline color and thickness for the fallback shape
        fallbackShape.setOutlineColor(sf::Color::Black); // Set border color to black
        fallbackShape.setOutlineThickness(2.0f); // Set border thickness (adjust as needed)

        std::cerr << "Failed to load texture from: " << textureFile << std::endl; // Log the error
        isTextureLoaded = false; // Indicate that the texture loading failed
    }
}

/**
 * @brief Renders the bonus entity.
 *
 * This method draws the bonus entity to the window. If the texture is loaded, it draws the sprite;
 * otherwise, it draws the fallback shape.
 */
void BonusView::render() {
    if (isTextureLoaded) {
        CurrentWindow->draw(sprite); // Draw the sprite if texture is loaded
    } else {
        CurrentWindow->draw(fallbackShape); // Draw the fallback shape if texture is not loaded
    }
}
