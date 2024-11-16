//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_WORLD_H
#define INC_2024_PROJECT_SKIPMARE_WORLD_H
#include <vector>
#include "Entity.h"

class World {
    World();
    ~World();

    void initialize();
    void update();

private:
    std::vector<Entity*> entities;

};


#endif //INC_2024_PROJECT_SKIPMARE_WORLD_H
