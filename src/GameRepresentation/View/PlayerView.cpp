#include "PlayerView.h"

/**
 * @class PlayerView
 * @brief Handles the visual representation of the Player entity.
 *
 * This class manages the rendering of the Player entity's texture, as well as its
 * fallback shape when texture loading fails. It updates the position and visual
 * state of the Player entity on the screen.
 */

// Constructor to initialize PlayerView with the associated Player entity
/**
 * @brief Constructs a PlayerView object and associates it with a Player entity.
 *
 * This constructor initializes the PlayerView with the associated Player entity and
 * the SFML render window. It loads the player's texture and sets the initial position.
 *
 * @param player A shared pointer to the Player entity.
 * @param window A shared pointer to the SFML render window used for rendering.
 */
PlayerView::PlayerView(const std::shared_ptr<Player> &player, const std::shared_ptr<sf::RenderWindow> &window)
    : EntityView(player, window), player(player) {
    loadTexture();  ///< Load texture based on the player's state
    sprite.setPosition(player->getX(), player->getY());  ///< Set the initial position
}

// Load a texture based on the player's state
/**
 * @brief Loads the texture for the player and applies it to the sprite.
 *
 * This method attempts to load the player's texture from a file. If successful,
 * it scales and applies the texture to the player's sprite. If the texture cannot
 * be loaded, a fallback rectangle shape is created to represent the player.
 *
 * @note If the texture cannot be loaded, a fallback rectangle with a red color is used
 *       to represent the player visually.
 */
void PlayerView::loadTexture() {

    std::string textureFile = "Assets/Sprites/player.png";  ///< Path to the player's texture file

    // Load the texture from file and apply it to the sprite
    if (texture.loadFromFile(textureFile)) {
        isTextureLoaded = true;  ///< Set texture loaded flag
        sprite.setTexture(texture);  ///< Apply the loaded texture to the sprite

        // Calculate the scale factors to match the player's dimensions
        float scaleX = player->getWidth() / static_cast<float>(texture.getSize().x);
        float scaleY = player->getHeight() / static_cast<float>(texture.getSize().y);
        sprite.setScale(scaleX, scaleY);  ///< Resize the sprite

        // Set the origin to the center of the sprite
        sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);

        // Set the initial position to the player's position
        sprite.setPosition(player->getX(), player->getY());
    } else {
        // If texture loading fails, create a rectangle shape as a fallback
        fallbackShape.setSize(sf::Vector2f(player->getWidth(), player->getHeight()));  ///< Create rectangle with player dimensions
        fallbackShape.setFillColor(sf::Color::Red);  ///< Set a fallback color (can be customized)
        fallbackShape.setPosition(player->getX() - player->getWidth() / 2, player->getY() - player->getHeight() / 2);  ///< Center the rectangle
    }
}
