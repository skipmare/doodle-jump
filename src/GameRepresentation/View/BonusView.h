/**
* @file BonusView.h
 * @brief Defines the BonusView class, responsible for rendering a bonus entity in the game.
 *
 * This class is used to create a graphical representation of a Bonus entity. It loads textures based on the bonus
 * type and sets the position of the sprite in the game window. If texture loading fails, it uses a fallback shape.
 */

#ifndef INC_2024_PROJECT_SKIPMARE_BONUSVIEW_H
#define INC_2024_PROJECT_SKIPMARE_BONUSVIEW_H

#include <SFML/Graphics.hpp>
#include "EntityView.h"
#include "../Logic/Entities/Bonuses/Bonus.h"

/**
 * @class BonusView
 * @brief Renders a bonus entity.
 *
 * The BonusView class is responsible for rendering a bonus entity. It handles loading textures based on the bonus
 * type, setting the sprite's position, and providing a fallback shape if texture loading fails.
 */
class BonusView : public EntityView {
public:
    /**
     * @brief Constructs a BonusView object.
     * @param bonus A shared pointer to the Bonus entity.
     * @param window A shared pointer to the SFML render window.
     */
    explicit BonusView(const std::shared_ptr<Bonus> &bonus, const std::shared_ptr<sf::RenderWindow> &window);

    /**
     * @brief Destructor for the BonusView class.
     */
    ~BonusView() override = default;

    /**
     * @brief Renders the bonus sprite or fallback shape.
     */
    void render() override;

private:
    std::shared_ptr<Bonus> bonus; ///< Reference to the bonus entity for which the view is created.

    /**
     * @brief Loads the texture for the bonus.
     *
     * This method loads a texture based on the bonus type. If loading fails, a fallback shape is used.
     */
    void loadTexture() override;
};

#endif //INC_2024_PROJECT_SKIPMARE_BONUSVIEW_H
