#ifndef INC_2024_PROJECT_SKIPMARE_WORLD_H
#define INC_2024_PROJECT_SKIPMARE_WORLD_H

#include <vector>
#include <memory>
#include "Entity.h"
#

class World {
public:
    World();
    ~World();

    void initialize();
    void update();

    bool checkCollision(Entity* entity1, Entity* entity2);
    void generateEntities();
    void addEntity(std::unique_ptr<Entity> entity);

private:
    std::vector<std::unique_ptr<Entity>> entities;
};

#endif //INC_2024_PROJECT_SKIPMARE_WORLD_H