#include "BGtileView.h"
#include <iostream> // For error handling

// Constructor that accepts a BackgroundTile entity reference
BGtileView::BGtileView(std::shared_ptr<BGtile> tile, std::shared_ptr<sf::RenderWindow> window)
    : EntityView(tile, window), tile(tile) {
    loadTexture(); // Load the texture based on the background tile type
    setPosition(); // Set the initial position of the background tile sprite
}

// Load the texture based on the background tile type
void BGtileView::loadTexture() {
    std::string textureFile = "Sprites/defaulttile.png"; // Example texture path

    fallbackShape.setFillColor(sf::Color::Yellow); // Fallback color for unknown

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        isTextureLoaded = true; // Indicate that the texture has been loaded successfully
        sprite.setTexture(texture); // Apply the texture to the sprite

        // Calculate the scale factors to match the tile's dimensions
        float scaleX = tile->getWidth() / static_cast<float>(texture.getSize().x);
        float scaleY = tile->getHeight() / static_cast<float>(texture.getSize().y);
        sprite.setScale(scaleX, scaleY); // Resize the sprite

        // Set the origin to the center of the sprite
        sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

        // Set the initial position to the tile's position
        sprite.setPosition(tile->getX(), tile->getY());
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(tile->getWidth(), tile->getHeight())); // Set a default size for the fallback shape
        fallbackShape.setPosition(tile->getX() - tile->getWidth() / 2, tile->getY() - tile->getHeight() / 2); // Center the rectangle

        // Set the outline color and thickness for the fallback shape
        fallbackShape.setOutlineColor(sf::Color::Black); // Set border color to black
        fallbackShape.setOutlineThickness(2.0f); // Set border thickness (adjust as needed)

        std::cerr << "Failed to load texture from: " << textureFile << std::endl; // Log the error
        isTextureLoaded = false; // Indicate that the texture loading failed
    }
}