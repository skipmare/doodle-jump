//
// Created by Skip on 23/11/2024.
//

#ifndef BGTILEVIEW_H
#define BGTILEVIEW_H

#include <SFML/Graphics.hpp>
#include "EntityView.h"
#include "../Logic/Entities/BGtile.h" // Assuming you have a BackgroundTile entity

class BGtileView : public EntityView {
public:
    // Constructor that accepts a BackgroundTile entity reference and a render window
    explicit BGtileView(BGtile& tile, sf::RenderWindow& window);

    // Destructor
    ~BGtileView() override = default;

private:
    BGtile& tile; // Reference to the background tile entity for which the view is created

    // Load the texture based on the background tile type
    void loadTexture();

};

#endif //BGTILEVIEW_H
