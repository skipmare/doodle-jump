//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_PLATFORMVIEW_H
#define INC_2024_PROJECT_SKIPMARE_PLATFORMVIEW_H
#include "EntityView.h"
#include <SFML/Graphics.hpp>
#include "../../Logic/Entities/Platforms/Platform.h"

class PlatformView : public EntityView {
public:
    // Constructor takes a reference to the associated platform
    explicit PlatformView(Platform& platform);

    // Update the visual representation of the platform (e.g., animations, movements)
    void update(float deltaTime) override;


private:
    Platform& platform;  // Reference to the platform entity this view represents
    void loadTexture();  // Load texture based on platform type
};

#endif // INC_2024_PROJECT_SKIPMARE_PLATFORMVIEW_H