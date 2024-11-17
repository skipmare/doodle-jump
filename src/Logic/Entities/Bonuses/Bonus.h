//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_BONUS_H
#define INC_2024_PROJECT_SKIPMARE_BONUS_H
#include "../Entity.h"

enum BonusType {
    JETPACK,
    SPRING
};

class Bonus : public Entity {
public:
    Bonus(float x, float y); // Constructor
    ~Bonus() override = default; // Destructor

    void update(float deltaTime) override; // Updates the bonus

    BonusType getType() const; // Returns the type of the bonus

protected:
    BonusType type;
    float duration = 0; // Duration of the bonus
    bool isActive = false; // Bonus is active
};


#endif //INC_2024_PROJECT_SKIPMARE_BONUS_H
