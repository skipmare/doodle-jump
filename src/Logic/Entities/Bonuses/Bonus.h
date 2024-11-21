//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_BONUS_H
#define INC_2024_PROJECT_SKIPMARE_BONUS_H
#include "../Entity.h"



class Bonus : public Entity {
public:
    Bonus(float x, float y); // Constructor
    ~Bonus() override = default; // Destructor

    void update(float deltaTime) override; // Updates the bonus

    [[nodiscard]] BonusType getType() const; // Returns the type of the bonus

protected:
    BonusType type;
    bool isCollected = false; // Bonus is collected
};


#endif //INC_2024_PROJECT_SKIPMARE_BONUS_H
