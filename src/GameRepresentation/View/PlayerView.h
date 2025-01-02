#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "EntityView.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

/**
 * @class PlayerView
 * @brief Manages the visual representation of the Player entity.
 *
 * The PlayerView class handles the rendering and visual state of the Player entity.
 * It is responsible for loading and applying the texture to the player sprite,
 * as well as providing fallback visuals if the texture fails to load.
 */
class PlayerView : public EntityView {
public:
    /**
     * @brief Constructs a PlayerView object and associates it with a Player entity.
     *
     * This constructor initializes the PlayerView with the associated Player entity
     * and the SFML render window. It also loads the player's texture and sets
     * the initial position of the player.
     *
     * @param player A shared pointer to the Player entity.
     * @param window A shared pointer to the SFML render window used for rendering.
     */
    PlayerView(const std::shared_ptr<Player> &player, const std::shared_ptr<sf::RenderWindow> &window);

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
    void loadTexture() final; // Load texture based on the player's state

private:
    /**
     * @brief Reference to the associated Player entity.
     *
     * This member stores the reference to the Player entity, which this PlayerView
     * is responsible for rendering.
     */
    std::shared_ptr<Player> player; // Reference to the associated player
};

#endif // PLAYERVIEW_H
