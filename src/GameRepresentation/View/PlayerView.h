#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "EntityView.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class PlayerView : public EntityView {
public:
    PlayerView(Player& player); // Constructor
    void update() override; // Update the visual representation
    void loadTexture(); // Load texture based on the player's state

private:
    Player& player; // Reference to the associated player
};

#endif // PLAYERVIEW_H