/**
* @file BGtileView.h
 * @brief Defines the BGtileView class, responsible for rendering a background tile entity in the game.
 *
 * This class is used to create a graphical representation of a BackgroundTile entity.
 * It loads textures based on the tile type and sets the position of the sprite in the game window.
 * If texture loading fails, it uses a fallback shape to represent the tile.
 */

#ifndef BGTILEVIEW_H
#define BGTILEVIEW_H

#include <SFML/Graphics.hpp>
#include "EntityView.h"
#include "../Logic/Entities/BGtile.h"

/**
 * @class BGtileView
 * @brief Renders a background tile entity.
 *
 * The BGtileView class is responsible for rendering a background tile entity. It handles loading textures
 * based on the tile type, setting the sprite's position, and providing a fallback shape if texture loading fails.
 */
class BGtileView : public EntityView {
public:
    /**
     * @brief Constructs a BGtileView object.
     * @param tile A shared pointer to the BackgroundTile entity.
     * @param window A shared pointer to the SFML render window.
     */
    explicit BGtileView(const std::shared_ptr<BGtile> &tile, const std::shared_ptr<sf::RenderWindow> &window);

    /**
     * @brief Destructor for the BGtileView class.
     */
    ~BGtileView() override = default;

private:
    std::shared_ptr<BGtile> tile; ///< Reference to the background tile entity for which the view is created.

    /**
     * @brief Loads the texture for the background tile.
     *
     * This method checks the tile type and loads the appropriate texture. If texture loading fails, a fallback shape
     * is created and displayed instead of the texture.
     */
    void loadTexture() override;
};

#endif //BGTILEVIEW_H
