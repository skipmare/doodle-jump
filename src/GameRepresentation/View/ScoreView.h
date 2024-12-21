//
// Created by Skip on 21/12/2024.
//

#ifndef SCOREVIEW_H
#define SCOREVIEW_H
#include "EntityView.h"
#include "../Logic/Entities/score.h"
#include <iostream>
#include <cmath>

class ScoreView : public EntityView {
public:
    ScoreView(std::shared_ptr<Score> score, std::shared_ptr<sf::RenderWindow> window);
    void loadTexture() override; // Load texture based on the score's state
    void loadFont(); // Load font for displaying the score
    void configureText(); // Configure text properties
    void render() override; // Render the score
private:
    std::shared_ptr<Score> score; // Reference to the associated score
    sf::Font font; // Font for displaying the score
};



#endif //SCOREVIEW_H
