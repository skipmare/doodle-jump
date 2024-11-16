//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_BGTILE_H
#define INC_2024_PROJECT_SKIPMARE_BGTILE_H
#include "Entity.h"

class BGtile : public Entity {
public:
    BGtile(float x, float y);
    ~BGtile() override = default;

    void update(float deltaTime) override;
};


#endif //INC_2024_PROJECT_SKIPMARE_BGTILE_H
