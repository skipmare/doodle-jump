//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_BONUS_H
#define INC_2024_PROJECT_SKIPMARE_BONUS_H
#include "../Entity.h"
#include "../Platforms/Platform.h"
#include "../Utilities/Random.h"


class Bonus : public Entity {
public:
    Bonus(float x, float y, std::shared_ptr<Platform> platform); // Constructor
    ~Bonus() override = default; // Destructor

    void update(float deltaTime) override; // Updates the bonus

    [[nodiscard]] BonusType getType() const; // Returns the type of the bonus
protected:
    BonusType type;
    std::shared_ptr<Platform> on_platform;
    float prevPlatformX = 0;
    float prevPlatformY = 0;
};


#endif //INC_2024_PROJECT_SKIPMARE_BONUS_H
