//
// Created by Skip on 21/12/2024.
//

#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include "EntityView.h"
#include "../Logic/Entities/Score.h"
#include <iostream>
#include <cmath>

/**
 * @class ScoreView
 * @brief Handles the visual representation of the score.
 *
 * The ScoreView class is responsible for rendering the current score and the best score
 * as text on the screen. It includes methods for loading fonts, configuring text properties,
 * and rendering the scores with custom colors and outlines.
 */
class ScoreView : public EntityView {
public:
    /**
     * @brief Constructs a ScoreView object.
     *
     * Initializes the view with the associated score entity and window, and loads the font
     * for displaying the score.
     *
     * @param score A shared pointer to the Score entity that holds the score information.
     * @param window A shared pointer to the SFML render window used for drawing.
     */
    ScoreView(const std::shared_ptr<Score> &score, const std::shared_ptr<sf::RenderWindow> &window);

    /**
     * @brief Loads the texture based on the score's state.
     *
     * This method is overridden from the base class but does nothing in this context as
     * the score is displayed using text, not a texture.
     */
    void loadTexture() final;

    /**
     * @brief Loads the font for displaying the score.
     *
     * This method loads the font from the file "Assets/CenturyGothic.ttf". If the font cannot
     * be loaded, an error message is printed to the standard error stream.
     */
    void loadFont();

    /**
     * @brief Configures the text properties for the score display.
     *
     * This method sets the font, position, size, color, and outline for both the current score
     * and best score texts.
     */
    void configureText();

    /**
     * @brief Renders the current score and best score on the window.
     *
     * This method updates the text for the current score and best score and draws them
     * on the window. The current score is displayed in green, while the best score is
     * displayed in red.
     */
    void render() override;

private:
    /**
     * @brief Reference to the associated score entity.
     *
     * The ScoreView uses this reference to access the current and best score values.
     */
    std::shared_ptr<Score> score;

    /**
     * @brief Font used for displaying the score text.
     *
     * The font is loaded from a file and used for rendering the score and best score text.
     */
    sf::Font font;
};

#endif //SCOREVIEW_H
