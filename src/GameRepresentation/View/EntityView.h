// Created by karan on 14/11/2024.

#ifndef INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H
#define INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H

#include <SFML/Graphics.hpp>  // Assuming SFML for rendering
#include "Entity.h"  // Including the Entity header for access to entity properties

class EntityView : public Observer{
public:
    virtual ~EntityView() = default; // Destructor


    // Pure virtual method to load the texture
    virtual void loadTexture() = 0;

    // Constructor takes a reference to the associated entity
    explicit EntityView(std::shared_ptr<Entity> entity, std::shared_ptr<sf::RenderWindow> window);

    // Method to update the view
    void update() final;

    // Method for rendering the view
    virtual void render();

    // Method to set the position of the view
    void setPosition();

protected:
    std::shared_ptr<sf::RenderWindow> CurrentWindow;  // Reference to the render window
    std::shared_ptr<Entity> entity;  // Reference to the entity this view represents
    sf::Sprite sprite;  // Sprite for graphical representation
    sf::Text text;  // Text for displaying information
    sf::Texture texture;  // Texture for the sprite
    sf::RectangleShape fallbackShape;  // Rectangle shape for fallback
    bool isTextureLoaded = false; // Flag to check if texture is loaded
};

#endif // INC_2024_PROJECT_SKIPMARE_ENTITYVIEW_H
