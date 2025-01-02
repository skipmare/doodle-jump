/**
 * @file BGtileView.cpp
 * @brief Implements the BGtileView class for rendering background tile entities.
 *
 * This file contains the implementation of the BGtileView class. It defines the constructor, destructor, and
 * methods for loading textures and rendering the background tile in the game window.
 */

#include "BGtileView.h"
#include <iostream> // For error handling

/**
 * @brief Constructs a BGtileView object.
 * @param tile A shared pointer to the BackgroundTile entity.
 * @param window A shared pointer to the SFML render window.
 */
BGtileView::BGtileView(const std::shared_ptr<BGtile> &tile, const std::shared_ptr<sf::RenderWindow> &window)
    : EntityView(tile, window), tile(tile) {
    loadTexture(); // Load the texture based on the background tile type
    setPosition(); // Set the initial position of the background tile sprite
}

/**
 * @brief Loads the texture for the background tile.
 * 
 * This method loads the appropriate texture based on the background tile's properties. If loading fails,
 * it creates a fallback shape to represent the tile.
 */
void BGtileView::loadTexture() {
    std::string textureFile = "Assets/Sprites/defaulttile.png"; // Default texture path
    fallbackShape.setFillColor(sf::Color::Yellow); // Fallback color for unknown

    // Attempt to load the texture from file
    if (texture.loadFromFile(textureFile)) {
        isTextureLoaded = true;
        sprite.setTexture(texture); // Apply the texture to the sprite

        // Scale the sprite to match the tile's dimensions
        float scaleX = tile->getWidth() / static_cast<float>(texture.getSize().x);
        float scaleY = tile->getHeight() / static_cast<float>(texture.getSize().y);
        sprite.setScale(scaleX, scaleY);

        // Set the sprite's origin to the center
        sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

        // Position the sprite at the tile's position
        sprite.setPosition(tile->getX(), tile->getY());
    } else {
        // If texture loading fails, use a fallback shape
        fallbackShape.setSize(sf::Vector2f(tile->getWidth(), tile->getHeight()));
        fallbackShape.setPosition(tile->getX() - tile->getWidth() / 2, tile->getY() - tile->getHeight() / 2);
        fallbackShape.setOutlineColor(sf::Color::Black); // Set border color to black
        fallbackShape.setOutlineThickness(2.0f); // Set border thickness

        std::cerr << "Failed to load texture from: " << textureFile << std::endl;
        isTextureLoaded = false;
    }
}
