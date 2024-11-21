#include "PlayerView.h"

// Constructor to initialize PlayerView with the associated Player entity
PlayerView::PlayerView(Player& player) : EntityView(player), player(player) {
    loadTexture();  // Load texture based on the player's state
    sprite.setPosition(player.getX(), player.getY());  // Set the initial position
}

// Method to update the visual representation
void PlayerView::update() {
    if(isTextureLoaded){
        sprite.setPosition(player.getX(), player.getY());
    }else {
        fallbackShape.setPosition(player.getX() - player.getWidth() / 2, player.getY() - player.getHeight() / 2);
    }
}

// Load a texture based on the player's state
void PlayerView::loadTexture() {
    std::string textureFile = "../Sprites/player.png"; // Example texture path

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        isTextureLoaded = true; // Set texture loaded flag
        sprite.setTexture(texture);  // Apply the loaded texture to the sprite
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(player.getWidth(), player.getHeight())); // Create rectangle with player dimensions
        fallbackShape.setFillColor(sf::Color::Red);  // Set a fallback color (can be customized)
        fallbackShape.setPosition(player.getX() - player.getWidth() / 2, player.getY() - player.getHeight() / 2); // Center the rectangle
    }
}
