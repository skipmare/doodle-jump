/**
 * @file EntityView.h
 * @brief Header file for the EntityView class, which represents the view for an entity.
 *
 * The EntityView class is responsible for rendering an entity in the game world, updating its position,
 * and handling texture loading and fallback rendering.
 *
 * @date Created by karan on 14/11/2024.
 */

#ifndef INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H
#define INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H

#include <SFML/Graphics.hpp>  ///< SFML for rendering graphics
#include "Entity.h"  ///< Include the Entity class for entity properties

/**
 * @class EntityView
 * @brief Abstract base class for rendering and updating an entity's view.
 *
 * The EntityView class is responsible for rendering the graphical representation of an entity,
 * updating its position, and loading the corresponding texture. It provides a basic structure
 * for subclasses that render specific types of entities (e.g., platform, bonus, etc.).
 */
class EntityView : public Observer {
public:
    /**
     * @brief Destructor for the EntityView class.
     */
    ~EntityView() override = default;

    /**
     * @brief Pure virtual method to load the texture for the entity.
     *
     * Derived classes must implement this method to load the texture specific to the entity type.
     */
    virtual void loadTexture() = 0;

    /**
     * @brief Constructor for the EntityView class.
     *
     * Initializes the EntityView with a reference to the associated entity and the render window.
     *
     * @param entity A shared pointer to the associated entity.
     * @param window A shared pointer to the SFML render window.
     */
    explicit EntityView(const std::shared_ptr<Entity> &entity, const std::shared_ptr<sf::RenderWindow> &window);

    /**
     * @brief Updates the position and renders the entity's view.
     *
     * This method is called to update the entity's position and render it.
     */
    void update() final;

    /**
     * @brief Renders the entity's view.
     *
     * This method is responsible for drawing the entity's sprite or fallback shape on the screen.
     */
    virtual void render();

    /**
     * @brief Sets the position of the entity's view.
     *
     * This method sets the position of the sprite or fallback shape based on the entity's position.
     */
    void setPosition();

protected:
    std::shared_ptr<sf::RenderWindow> CurrentWindow;  ///< The render window for rendering the entity
    std::shared_ptr<Entity> entity;  ///< The entity associated with this view
    sf::Sprite sprite;  ///< The sprite representing the entity
    sf::Text ScoreText;  ///< Text to display information about the entity
    sf::Text BestScoreText;  ///< Text to display the best score
    sf::Texture texture;  ///< The texture for the sprite
    sf::RectangleShape fallbackShape;  ///< The fallback shape to be rendered if texture loading fails
    bool isTextureLoaded = false; ///< Flag indicating whether the texture has been loaded
};

#endif // INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H
