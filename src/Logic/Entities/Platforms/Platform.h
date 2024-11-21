//
// Created by karan on 14/11/2024.
//

// Platform.h
#ifndef INC_2024_PROJECT_SKIPMARE_PLATFORM_H
#define INC_2024_PROJECT_SKIPMARE_PLATFORM_H
#include "../Entity.h"
#include "../Player.h"

class Platform : public Entity {
public:

    // Constructor and destructor
    Platform(float x, float y);
    ~Platform() override;

    // Updates the platform
    void update(float deltaTime) override;

    // Returns the type of the platform
     [[nodiscard]] PlatformType getPlatformType() const;

    // Collision check with the player
    bool checkCollision(Player& Player);

protected:
    // Type of the platform
    PlatformType type;
};

#endif //INC_2024_PROJECT_SKIPMARE_PLATFORM_H