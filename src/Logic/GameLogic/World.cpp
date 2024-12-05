#include "World.h"

// Constructor
World::World(const std::shared_ptr<AbstractFactory>& factory, float viewWidth, float viewHeight)
    : factory(factory), score(0), camera(viewWidth, viewHeight) { // Initialize camera with dimensions
    // Create the player entity
    player = factory->createPlayer(250, 250);
}

// Check collision between two entities
bool World::checkCollision(std::shared_ptr<Entity> entity1, std::shared_ptr<Entity> entity2) {
    if (!entity1 || !entity2) return false; // Handle null pointers.

    BoundingBox box1 = entity1->getBoundingBox(); // Get bounding box of entity1
    BoundingBox box2 = entity2->getBoundingBox(); // Get bounding box of entity2

    return (box1.right >= box2.left && box1.left <= box2.right &&
            box1.bottom >= box2.top && box1.top <= box2.bottom); // Check for collision
}

// Check collision between player and entity
bool World::checkCollision_player(std::shared_ptr<Entity> entity) {
    if (!entity) return false; // Handle null pointer.

    if (entity->getCollidable()) {
        if (entity->getCollisionOnLand()) {
            BoundingBox playerBox = player->getBoundingBox(); // Get bounding box of player
            BoundingBox entityBox = entity->getBoundingBox(); // Get bounding box of entity
            return (std::abs(playerBox.bottom - entityBox.top) < 1.0f && playerBox.right >= entityBox.left && playerBox.left <= entityBox.right && player->isFalling()); // Check for collision        } else {
            return checkCollision(player, entity); // Check collision between player and entity
        }
    }

    return false; // Return false if the entity is not collidable
}

//remove entities which are out of view
void World::removeRemovableEntities() {
    //check if the entity is out of view
    for (auto entity : entities) {
        float maxY = camera.getCameraY() + camera.getViewHeight() / 2;
        float minY = camera.getCameraY() - camera.getViewHeight() / 2;
        if (entity->getY() > maxY || entity->getY() < minY) {
            entity->setOutOfView(true);
        }
    }


    // Remove entities which are out of view
    for (auto it = entities.begin(); it != entities.end();) {
        if ((*it)->getOutOfView()) {
            it = entities.erase(it);
        } else {
            ++it;
        }
    }
}
