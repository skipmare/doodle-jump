// Created by karan on 14/11/2024.

#ifndef INC_2024_PROJECT_SKIPMARE_BONUSVIEW_H
#define INC_2024_PROJECT_SKIPMARE_BONUSVIEW_H

#include <SFML/Graphics.hpp>
#include "EntityView.h"
#include "../Logic/Entities/Bonuses/Bonus.h"

class BonusView : public EntityView {
public:
    // Constructor that accepts a Bonus entity reference
    explicit BonusView(Bonus& bonus, sf::RenderWindow& window);

    // Destructor
    ~BonusView() override = default;

    // Update method to handle bonus-specific animation or effects
    void update() override;

private:
    Bonus& bonus;  // Reference to the bonus entity for which the view is created

    // Load the texture based on the bonus type
    void loadTexture();

    // Set sprite position based on bonus position
    void setPosition();
};

#endif //INC_2024_PROJECT_SKIPMARE_BONUSVIEW_H
