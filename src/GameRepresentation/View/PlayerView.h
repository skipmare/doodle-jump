//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_PLAYERVIEW_H
#define INC_2024_PROJECT_SKIPMARE_PLAYERVIEW_H
#include "EntityView.h"
#include <SFML/Graphics.hpp>
#include "../../Logic/Entities/Player.h"

// PlayerView inherits from EntityView and handles rendering the player
class PlayerView : public EntityView {
public:
    // Constructor takes a reference to the associated Player entity
    explicit PlayerView(Player& player);

    // Update the visual representation (e.g., animations, movements)
    void update(float deltaTime) override;

private:
    Player& player;  // Reference to the Player entity this view represents
    void loadTexture();  // Load texture based on the player's state (if applicable)
};

#endif // INC_2024_PROJECT_SKIPMARE_PLAYERVIEW_H