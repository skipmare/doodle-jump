// Created by karan on 14/11/2024.

#include "PlayerView.h"
#include <SFML/Graphics.hpp>  // SFML for graphics

// Constructor to initialize PlayerView with the associated Player entity
PlayerView::PlayerView(Player& player) : EntityView(player), player(player) {
    // Initialize the graphical representation of the player with a sprite
    loadTexture();  // Load texture based on the player's state (if applicable)

    // Set the initial position of the sprite based on the player's position
    sprite.setPosition(player.getX(), player.getY());
}

// Method to update the visual representation (e.g., move, animate)
void PlayerView::update(float deltaTime) {
    // Update sprite's position based on player's position
    sprite.setPosition(player.getX(), player.getY());

    // You can add more logic here for animations, etc.
}

// Load a texture or set a texture based on the player's state
void PlayerView::loadTexture() {
    // Load a texture for the player
    // Replace "path_to_player_texture.png" with the actual path to your texture file
    if (texture.loadFromFile("../Sprites/player.png")) {
        sprite.setTexture(texture);  // Apply the loaded texture to the sprite
    } else {
        // If texture loading fails, set a default color or handle the error
        sprite.setColor(sf::Color::Red);  // For example, use red color as fallback
    }
}