/**
 * @file EntityView.cpp
 * @brief Implementation file for the EntityView class.
 *
 * The EntityView class is responsible for rendering the graphical representation of an entity,
 * updating its position, and handling texture loading and fallback rendering if the texture cannot be loaded.
 *
 * @date Created by karan on 14/11/2024.
 */

#include "EntityView.h"
#include "Entity.h"  ///< Include the Entity class for reference

/**
 * @brief Constructor for the EntityView class.
 *
 * Initializes the EntityView with a reference to the associated entity and the render window.
 * The constructor does not perform any additional logic beyond initializing the entity and window.
 *
 * @param entity A shared pointer to the associated entity.
 * @param window A shared pointer to the SFML render window.
 */
EntityView::EntityView(const std::shared_ptr<Entity> &entity, const std::shared_ptr<sf::RenderWindow> &window)
    : entity(entity), CurrentWindow(window) {
    // DO NOTHING, JUST INITIALIZE THE ENTITY (BASE CLASS)
}

/**
 * @brief Updates the position and renders the entity's view.
 *
 * This method is called to update the entity's position based on its current state and then render it on the screen.
 * It calls `setPosition` to adjust the position of the sprite or fallback shape, and then calls `render` to display the entity.
 */
void EntityView::update() {
    setPosition();  ///< Set the position of the entity
    render();  ///< Render the entity
}

/**
 * @brief Renders the entity's view.
 *
 * This method is responsible for drawing the entity's sprite or fallback shape on the screen.
 * If the texture is successfully loaded, the sprite is drawn; otherwise, a fallback shape is drawn.
 * Additionally, the entity's X position is displayed as a score.
 */
void EntityView::render() {
    if (texture.getSize().x > 0) {  ///< Check if texture is loaded
        CurrentWindow->draw(sprite);  ///< Draw the sprite if texture is loaded
    } else {
        CurrentWindow->draw(fallbackShape);  ///< Draw the fallback shape if texture loading failed
    }

    // Display the entity's X position as a score
    ScoreText.setString(std::to_string(entity->getX()));
    CurrentWindow->draw(ScoreText);  ///< Draw the score text on the screen
}

/**
 * @brief Sets the position of the entity's view.
 *
 * This method updates the position of the sprite or fallback shape based on the entity's current position.
 * If the texture is loaded, the sprite's position is set directly; otherwise, the fallback shape's position is adjusted.
 */
void EntityView::setPosition() {
    if (isTextureLoaded) {
        sprite.setPosition(entity->getX(), entity->getY());  ///< Set the position of the sprite
    } else {
        fallbackShape.setPosition(entity->getX() - entity->getWidth() / 2,
                                   entity->getY() - entity->getHeight() / 2);  ///< Center the fallback shape
    }
}
