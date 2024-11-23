#include "PlatformView.h"
#include <SFML/Graphics.hpp>  // For rendering
#include <iostream>            // For error handling

// Constructor takes a reference to the associated platform
PlatformView::PlatformView(Platform& platform, sf::RenderWindow& window) : EntityView(platform,window), platform(platform) {
    loadTexture();  // Load texture for the platform sprite
    sprite.setPosition(platform.getX(), platform.getY());  // Set the initial position
}

// Load texture based on platform type
void PlatformView::loadTexture() {
    std::string textureFile;  // Variable to hold the texture file path

    // Load different textures based on platform type
    switch (platform.getPlatformType()) {
        case PlatformType::STATIC:
            textureFile = "static_platform.png";  // Path to static platform texture
            fallbackShape.setFillColor(sf::Color::Green); // Fallback color for static
            break;
        case PlatformType::VERTICAL:
            textureFile = "vertical_platform.png";  // Path to vertical platform texture
            fallbackShape.setFillColor(sf::Color::Blue); // Fallback color for vertical
            break;
        case PlatformType::HORIZONTAL:
            textureFile = "horizontal_platform.png";  // Path to horizontal platform texture
            fallbackShape.setFillColor(sf::Color::Red); // Fallback color for horizontal
            break;
        case PlatformType::DISAPPEARING:
            textureFile = "disappearing_platform.png";  // Path to disappearing platform texture
            fallbackShape.setFillColor(sf::Color::Yellow); // Fallback color for disappearing
            break;
        default:
            textureFile = ""; // Handle unknown platform type
            fallbackShape.setFillColor(sf::Color::Magenta); // Fallback color for unknown
            break;
    }

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        isTextureLoaded = true; // Set texture loaded flag
        sprite.setTexture(texture);  // Apply the texture to the sprite
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(platform.getWidth(), platform.getHeight())); // Create rectangle with platform dimensions
        fallbackShape.setPosition(platform.getX() - platform.getWidth() / 2, platform.getY() - platform.getHeight() / 2); // Center the rectangle
    }
}