#include "BGtileView.h"
#include <iostream> // For error handling

// Constructor that accepts a BackgroundTile entity reference
BGtileView::BGtileView(BGtile& tile, sf::RenderWindow& window)
    : EntityView(tile, window), tile(tile) {
    loadTexture(); // Load the texture based on the background tile type
    setPosition(); // Set the initial position of the background tile sprite
}

// Load the texture based on the background tile type
void BGtileView::loadTexture() {
    std::string textureFile; // Variable to hold the texture file path
    textureFile = "default_tile.png"; // Fallback texture if type is unknown

    fallbackShape.setFillColor(sf::Color::Yellow); // Fallback color for unknown

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        sprite.setTexture(texture); // Apply the texture to the sprite
        isTextureLoaded = true; // Indicate that the texture has been loaded successfully
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(tile.getWidth(), tile.getHeight())); // Set a default size for the fallback shape
        fallbackShape.setPosition(tile.getX() - 8, tile.getY() - 8); // Center the rectangle

        // Set the outline color and thickness for the fallback shape
        fallbackShape.setOutlineColor(sf::Color::Black); // Set border color to black
        fallbackShape.setOutlineThickness(2.0f); // Set border thickness (adjust as needed)

        std::cerr << "Failed to load texture from: " << textureFile << std::endl; // Log the error
        isTextureLoaded = false; // Indicate that the texture loading failed
    }
}