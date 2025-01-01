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
    ScoreText.setFont(font);
    ScoreText.setPosition(15, 50);
    ScoreText.setCharacterSize(30);
    ScoreText.setFillColor(sf::Color::Green);
    ScoreText.setString(std::to_string(score->getScore()));
    ScoreText.setOutlineColor(sf::Color::Black);
    ScoreText.setOutlineThickness(0.5f);

    BestScoreText.setFont(font);
    BestScoreText.setPosition(15, 10);
    BestScoreText.setCharacterSize(30);
    BestScoreText.setFillColor(sf::Color::Red);
    BestScoreText.setString("Best: " + std::to_string(score->getBestScore()));
    BestScoreText.setOutlineColor(sf::Color::Black);
    BestScoreText.setOutlineThickness(0.5f);
}

void ScoreView::loadTexture() {
    // Do nothing
}

void ScoreView::render() {
    ScoreText.setString(std::to_string(score->getScore()/100));
    CurrentWindow->draw(ScoreText);
    BestScoreText.setString("Best: " + std::to_string(score->getBestScore()/100));
    CurrentWindow->draw(BestScoreText);
}