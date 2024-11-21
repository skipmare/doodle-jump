// Created by karan on 14/11/2024.

#ifndef INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H
#define INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H

#include <SFML/Graphics.hpp>  // Assuming SFML for rendering
#include "Entity.h"  // Including the Entity header for access to entity properties

class EntityView : public Observer{
public:
    virtual ~EntityView() = default; // Destructor

    // Constructor takes a reference to the associated entity
    explicit EntityView(Entity& entity);

    // Virtual method for updating the view (can be overridden by derived classes)
    virtual void update() = 0;

    // Method for rendering the view
    void render(sf::RenderWindow& window);

protected:
    Entity& entity;  // Reference to the entity this view represents
    sf::Sprite sprite;  // Sprite for graphical representation
    sf::Texture texture;  // Texture for the sprite
    sf::RectangleShape fallbackShape;  // Rectangle shape for fallback
    bool isTextureLoaded = false; // Flag to check if texture is loaded
};

#endif // INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H
