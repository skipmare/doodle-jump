#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "EntityView.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class PlayerView : public EntityView {
public:
    PlayerView(const std::shared_ptr<Player> &player, const std::shared_ptr<sf::RenderWindow> &window); // Constructor
    void loadTexture() final; // Load texture based on the player's state

private:
    std::shared_ptr<Player> player; // Reference to the associated player
};

#endif // PLAYERVIEW_H