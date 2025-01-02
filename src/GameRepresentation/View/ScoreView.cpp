//
// Created by Skip on 21/12/2024.
//

#include "ScoreView.h"

/**
 * @class ScoreView
 * @brief Handles the visual representation of the score.
 *
 * The ScoreView class is responsible for rendering the current score and the best score.
 * It displays the scores as text on the screen, with customized font, size, and colors.
 */
ScoreView::ScoreView(const std::shared_ptr<Score> &score, const std::shared_ptr<sf::RenderWindow> &window)
    : EntityView(score, window), score(score) {
    loadFont();  ///< Load the font used for score display
    configureText();  ///< Configure the text properties for both score and best score
}

/**
 * @brief Loads the font used for displaying the score.
 *
 * This method loads the font from the file "Assets/CenturyGothic.ttf". If the font cannot
 * be loaded, an error message is printed to the standard error stream.
 */
void ScoreView::loadFont() {
    if (!font.loadFromFile("Assets/CenturyGothic.ttf")) {
        std::cerr << "Error loading font\n";  ///< Error message if font fails to load
    }
}

/**
 * @brief Configures the text properties for displaying the score and best score.
 *
 * This method sets the font, position, size, color, and outline for both the current score
 * and best score texts. It also sets the string values to the respective scores.
 */
void ScoreView::configureText() {
    // Configure properties for the current score text
    ScoreText.setFont(font);
    ScoreText.setPosition(15, 50);
    ScoreText.setCharacterSize(30);
    ScoreText.setFillColor(sf::Color::Green);
    ScoreText.setString(std::to_string(score->getScore()));
    ScoreText.setOutlineColor(sf::Color::Black);
    ScoreText.setOutlineThickness(0.5f);

    // Configure properties for the best score text
    BestScoreText.setFont(font);
    BestScoreText.setPosition(15, 10);
    BestScoreText.setCharacterSize(30);
    BestScoreText.setFillColor(sf::Color::Red);
    BestScoreText.setString("Best: " + std::to_string(score->getBestScore()));
    BestScoreText.setOutlineColor(sf::Color::Black);
    BestScoreText.setOutlineThickness(0.5f);
}

/**
 * @brief Loads the texture for the score view.
 *
 * This method is overridden from the base class but does nothing in this context.
 * The score view only uses text for rendering, so no texture is needed.
 */
void ScoreView::loadTexture() {
    // No texture is used for score rendering
}

/**
 * @brief Renders the current score and best score on the window.
 *
 * This method updates the text for the current score and best score and draws them
 * on the window. The current score is displayed in green, while the best score is
 * displayed in red.
 */
void ScoreView::render() {
    // Update and render the current score text
    ScoreText.setString(std::to_string(score->getScore()/100));
    CurrentWindow->draw(ScoreText);

    // Update and render the best score text
    BestScoreText.setString("Best: " + std::to_string(score->getBestScore()/100));
    CurrentWindow->draw(BestScoreText);
}
