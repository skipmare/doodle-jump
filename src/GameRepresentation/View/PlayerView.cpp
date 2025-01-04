#include "PlayerView.h"

/**
 * @class PlayerView
 * @brief Handles the visual representation of the Player entity.
 *
 * This class manages the rendering of the Player entity's textures, allowing
 * for dynamic switching based on the player's direction (e.g., moving left or right).
 * It updates the position and visual state of the Player entity on the screen.
 */

// Constructor to initialize PlayerView with the associated Player entity
PlayerView::PlayerView(const std::shared_ptr<Player>& player, const std::shared_ptr<sf::RenderWindow>& window)
    : EntityView(player, window), player(player) {
    loadTexture(); ///< Load textures for both directions
    updateSprite(); ///< Set the initial sprite based on the player's direction
}

// Load textures for both left and right directions
void PlayerView::loadTexture() {
    const std::string textureFileLeft = "Assets/Sprites/playerLeft.png"; ///< Path to the left texture
    const std::string textureFileRight = "Assets/Sprites/playerRight.png"; ///< Path to the right texture

    // Load left texture
    if (textureLeft.loadFromFile(textureFileLeft)) {
        PlayerLeft.setTexture(textureLeft); ///< Assign texture to the left sprite
        PlayerLeft.setOrigin(textureLeft.getSize().x / 2.0f, textureLeft.getSize().y / 2.0f); ///< Center the sprite
        PlayerLeft.setScale(player->getWidth() / static_cast<float>(textureLeft.getSize().x),
                            player->getHeight() / static_cast<float>(textureLeft.getSize().y));
    } else {
        isLeftTextureLoaded = false; ///< Mark failure for left texture
    }

    // Load right texture
    if (textureRight.loadFromFile(textureFileRight)) {
        PlayerRight.setTexture(textureRight); ///< Assign texture to the right sprite
        PlayerRight.setOrigin(textureRight.getSize().x / 2.0f, textureRight.getSize().y / 2.0f); ///< Center the sprite
        PlayerRight.setScale(player->getWidth() / static_cast<float>(textureRight.getSize().x),
                             player->getHeight() / static_cast<float>(textureRight.getSize().y));
    } else {
        isRightTextureLoaded = false; ///< Mark failure for right texture
    }

    // Handle fallback if either texture fails
    if (!isLeftTextureLoaded || !isRightTextureLoaded) {
        fallbackShape.setSize(sf::Vector2f(player->getWidth(), player->getHeight())); ///< Create rectangle
        fallbackShape.setFillColor(sf::Color::Red); ///< Set fallback color
    }
}

// Update the sprite based on the player's direction
void PlayerView::updateSprite() {
    if (player->getisgoingleft()) {
        if (isLeftTextureLoaded) {
            currentSprite = &PlayerLeft;
        } else {
            currentSprite = nullptr; ///< No valid texture for left
        }
    } else {
        if (isRightTextureLoaded) {
            currentSprite = &PlayerRight;
        } else {
            currentSprite = nullptr; ///< No valid texture for right
        }
    }
}

// Update and render the player
void PlayerView::update() {
    updateSprite(); ///< Switch to the correct sprite
    setPosition(); ///< Update position based on player
    render(); ///< Draw the player
}

// Draw the appropriate sprite or fallback shape
void PlayerView::render() {
    if (currentSprite) {
        currentSprite->setPosition(player->getX(), player->getY()); ///< Update sprite position
        CurrentWindow->draw(*currentSprite); ///< Draw the current sprite
    } else {
        fallbackShape.setPosition(player->getX() - player->getWidth() / 2.0f,
                                  player->getY() - player->getHeight() / 2.0f); ///< Center the rectangle
        CurrentWindow->draw(fallbackShape); ///< Draw the fallback shape
    }
}
