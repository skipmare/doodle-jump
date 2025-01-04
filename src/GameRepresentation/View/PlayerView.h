#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "EntityView.h"
#include "Player.h"

/**
 * @class PlayerView
 * @brief Handles the visual representation of the Player entity.
 *
 * This class is responsible for rendering the Player entity on the screen,
 * including managing textures for different directions (left and right)
 * and a fallback shape in case textures fail to load. It dynamically updates
 * the sprite and position based on the Player's state.
 */
class PlayerView : public EntityView {
public:
    /**
     * @brief Constructs a PlayerView object and associates it with a Player entity.
     *
     * Initializes the PlayerView with the associated Player entity and
     * SFML render window. It loads the necessary textures and sets the
     * initial visual state.
     *
     * @param player A shared pointer to the Player entity.
     * @param window A shared pointer to the SFML render window used for rendering.
     */
    PlayerView(const std::shared_ptr<Player>& player, const std::shared_ptr<sf::RenderWindow>& window);

    /**
     * @brief Updates the sprite, position, and rendering of the Player entity.
     *
     * This method dynamically adjusts the visual state of the PlayerView
     * to reflect the Player's current direction and position.
     */
    void update() override;

    /**
     * @brief Renders the Player entity on the screen.
     *
     * Draws the appropriate sprite (left or right) or a fallback shape
     * if the textures are not available.
     */
    void render() override;

private:
    /**
     * @brief Loads textures for both left and right directions.
     *
     * Attempts to load textures from files for rendering the Player in
     * left and right orientations. If loading fails, sets up a fallback
     * rectangle shape.
     */
    void loadTexture() override;

    /**
     * @brief Updates the sprite based on the Player's direction.
     *
     * Selects the appropriate sprite (left or right) based on whether
     * the Player is moving left or right.
     */
    void updateSprite();

    // Member variables
    std::shared_ptr<Player> player; ///< Pointer to the associated Player entity
    sf::Texture textureLeft; ///< Texture for the left direction
    sf::Texture textureRight; ///< Texture for the right direction
    sf::Sprite PlayerLeft; ///< Sprite for the left direction
    sf::Sprite PlayerRight; ///< Sprite for the right direction
    sf::Sprite* currentSprite = nullptr; ///< Pointer to the currently active sprite
    sf::RectangleShape fallbackShape; ///< Fallback rectangle shape for visual representation

    bool isLeftTextureLoaded = true; ///< Flag to indicate if left texture is loaded
    bool isRightTextureLoaded = true; ///< Flag to indicate if right texture is loaded
};

#endif // PLAYERVIEW_H
