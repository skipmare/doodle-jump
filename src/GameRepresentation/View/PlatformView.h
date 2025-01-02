/**
* @file PlatformView.h
 * @brief Header file for the PlatformView class, which represents the view for a platform entity.
 *
 * The PlatformView class is responsible for rendering the graphical representation of a platform,
 * including texture loading and handling fallback rendering if the texture cannot be loaded.
 *
 * @date Created by karan on 14/11/2024.
 */

#ifndef PLATFORMVIEW_H
#define PLATFORMVIEW_H

#include "../Logic/Entities/Platforms/Platform.h"  ///< Include the Platform class for platform properties
#include "EntityView.h"  ///< Include the EntityView class as a base class
#include <SFML/Graphics.hpp>  ///< SFML for rendering graphics

/**
 * @class PlatformView
 * @brief Class for rendering and updating the view of a platform entity.
 *
 * The PlatformView class is responsible for rendering the graphical representation of a platform,
 * updating its position, and handling texture loading based on the platform type.
 */
class PlatformView : public EntityView {
public:
    /**
     * @brief Constructor for the PlatformView class.
     *
     * Initializes the PlatformView with a reference to the associated platform and the render window.
     *
     * @param platform A shared pointer to the associated platform.
     * @param window A shared pointer to the SFML render window.
     */
    explicit PlatformView(const std::shared_ptr<Platform> &platform, const std::shared_ptr<sf::RenderWindow> &window);

    /**
     * @brief Loads the texture based on the platform type.
     *
     * This method loads a different texture depending on the type of the platform.
     */
    void loadTexture() final;

private:
    std::shared_ptr<Platform> platform;  ///< The platform associated with this view
};

#endif // PLATFORMVIEW_H
