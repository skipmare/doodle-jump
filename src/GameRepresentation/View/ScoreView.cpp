//
// Created by Skip on 21/12/2024.
//

#include "ScoreView.h"

// Constructor to initialize the view with the associated score
ScoreView::ScoreView(const std::shared_ptr<Score> &score, const std::shared_ptr<sf::RenderWindow> &window)
    : EntityView(score, window), score(score) {
    loadFont();
    configureText();
}

// Load font for displaying the score
void ScoreView::loadFont() {
    if (!font.loadFromFile("Assets/CenturyGothic.ttf")) {
        std::cerr << "Error loading font\n";
    }
}

// Configure text properties
void ScoreView::configureText() {
    text.setFont(font);
    text.setPosition(15, 10);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Green);
    text.setString(std::to_string(score->getScore()));
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(0.5f);
}

void ScoreView::loadTexture() {
    // Do nothing
}

void ScoreView::render() {
    text.setString(std::to_string(score->getScore()/100));
    CurrentWindow->draw(text);
}