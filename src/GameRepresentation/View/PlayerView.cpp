#include "PlayerView.h"

// Constructor to initialize PlayerView with the associated Player entity
PlayerView::PlayerView(std::shared_ptr<Player> player, std::shared_ptr<sf::RenderWindow> window) : EntityView(player, window), player(player) {
    loadTexture();  // Load texture based on the player's state
    sprite.setPosition(player->getX(), player->getY());  // Set the initial position
}

// Load a texture based on the player's state
void PlayerView::loadTexture() {

    std::string textureFile = "Sprites/player.png"; // Example texture path

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        isTextureLoaded = true; // Set texture loaded flag
        sprite.setTexture(texture);  // Apply the loaded texture to the sprite

        // Calculate the scale factors to match the player's dimensions
        float scaleX = player->getWidth() / static_cast<float>(texture.getSize().x);
        float scaleY = player->getHeight() / static_cast<float>(texture.getSize().y);
        sprite.setScale(scaleX, scaleY); // Resize the sprite

        // Set the origin to the center of the sprite
        sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

        // Set the initial position to the player's position
        sprite.setPosition(player->getX(), player->getY());
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(player->getWidth(), player->getHeight())); // Create rectangle with player dimensions
        fallbackShape.setFillColor(sf::Color::Red);  // Set a fallback color (can be customized)
        fallbackShape.setPosition(player->getX() - player->getWidth() / 2, player->getY() - player->getHeight() / 2); // Center the rectangle
    }
}
