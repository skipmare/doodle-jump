#ifndef PLATFORMVIEW_H
#define PLATFORMVIEW_H

#include "../Logic/Entities/Platforms/Platform.h"
#include "EntityView.h"
#include <SFML/Graphics.hpp>

class PlatformView : public EntityView {
public:
    explicit PlatformView(std::shared_ptr<Platform> platform, std::shared_ptr<sf::RenderWindow> window);
    void loadTexture(); // Load texture based on platform type

private:
    std::shared_ptr<Platform> platform; // Reference to the associated platform
};

#endif // PLATFORMVIEW_H