#include "PlatformView.h"

// Constructor takes a reference to the associated platform
PlatformView::PlatformView(const std::shared_ptr<Platform> &platform, const std::shared_ptr<sf::RenderWindow> &window) : EntityView(platform,window), platform(platform) {
    loadTexture();  // Load texture for the platform sprite
    sprite.setPosition(platform->getX(), platform->getY());  // Set the initial position
}

// Load texture based on platform type
void PlatformView::loadTexture() {
    std::string textureFile;  // Variable to hold the texture file path

    // Load different textures based on platform type
    switch (platform->getPlatformType()) {
        case PlatformType::STATIC:
            textureFile = "Assets/Sprites/staticplatform.png";  // Path to static platform texture
        fallbackShape.setFillColor(sf::Color::Green); // Fallback color for static
        break;
        case PlatformType::VERTICAL:
            textureFile = "Assets/Sprites/verticalplatform.png";  // Path to vertical platform texture
        fallbackShape.setFillColor(sf::Color::Blue); // Fallback color for vertical
        break;
        case PlatformType::HORIZONTAL:
            textureFile = "Assets/Sprites/horizontalplatform.png";  // Path to horizontal platform texture
        fallbackShape.setFillColor(sf::Color::Red); // Fallback color for horizontal
        break;
        case PlatformType::DISAPPEARING:
            textureFile = "Assets/Sprites/disappearingplatform.png";  // Path to disappearing platform texture
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

        // Calculate the scale factors to match the platform's dimensions
        float scaleX = platform->getWidth() / static_cast<float>(texture.getSize().x);
        float scaleY = platform->getHeight() / static_cast<float>(texture.getSize().y);
        sprite.setScale(scaleX, scaleY); // Resize the sprite

        // Set the origin to the center of the sprite
        sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

        // Set the initial position to the platform's position
        sprite.setPosition(platform->getX(), platform->getY());
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(platform->getWidth(), platform->getHeight())); // Create rectangle with platform dimensions
        fallbackShape.setPosition(platform->getX() - platform->getWidth() / 2, platform->getY() - platform->getHeight() / 2); // Center the rectangle
    }
}