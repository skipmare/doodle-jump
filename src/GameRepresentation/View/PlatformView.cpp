// Created by karan on 14/11/2024.

#include "PlatformView.h"
#include <SFML/Graphics.hpp>  // For rendering

// Constructor takes a reference to the associated platform
PlatformView::PlatformView(Platform& platform) : EntityView(platform), platform(platform) {
    loadTexture();  // Load texture for the platform sprite
    sprite.setPosition(platform.getX(), platform.getY());  // Set the initial position
}

// Update the visual representation of the platform (e.g., animations, movements)
void PlatformView::update(float deltaTime) {
    // Here we could apply movement or animations if the platform type requires it
    sprite.setPosition(platform.getX(), platform.getY());  // Update position based on platform's position

    // Example: Add any platform-specific logic here (e.g., moving platforms, disappearing platforms, etc.)
}

// Load texture based on platform type (for simplicity, let's assume platform types map to specific textures)
void PlatformView::loadTexture() {
    std::string textureFile;  // Variable to hold the texture file path

    // Load different textures based on platform type
    switch (platform.getPlatformType()) {
        case PlatformType::STATIC:
            textureFile = "static_platform.png";  // Path to static platform texture
            break;
        case PlatformType::VERTICAL:
            textureFile = "vertical_platform.png";  // Path to vertical platform texture
            break;
        case PlatformType::HORIZONTAL:
            textureFile = "horizontal_platform.png";  // Path to horizontal platform texture
            break;
        case PlatformType::DISAPPEARING:
            textureFile = "disappearing_platform.png";  // Path to disappearing platform texture
            break;
    }

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        sprite.setTexture(texture);  // Apply the texture to the sprite
    } else {
        // If texture loading fails, set a fallback color (could be any color you prefer)
        sprite.setColor(sf::Color::Green);  // Fallback color in case of texture load failure
    }
}
