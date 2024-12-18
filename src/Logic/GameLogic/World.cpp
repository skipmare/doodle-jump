#include "World.h"
#include "iostream"

// Constructor
World::World(const std::shared_ptr<AbstractFactory>& factory, float viewWidth, float viewHeight)
    : factory(factory), score(0), camera(viewWidth, viewHeight) { // Initialize camera with dimensions

    genWorld(); // Generate the world
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
            return (std::abs(playerBox.bottom - entityBox.top) < 3.0f  && playerBox.right >= entityBox.left && playerBox.left <= entityBox.right && player->isFalling()); // Check for collision
        } else {
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

void World::genWorld() {
    // Clear existing entities
    entities.clear();

    // Reset active platforms count
    ActivePlatforms = 0;

    // Hard code a static platform at (250, 200)
    std::shared_ptr<Platform> staticPlatform = factory->createPlatform(250, 600, PlatformType::STATIC);
    entities.push_back(staticPlatform);
    ActivePlatforms++;

    player = factory->createPlayer(0, 0); // Create the player entity
    // Set player position on top of the static platform
    player->setPosition(250, 570);

    // Generate additional platforms as needed
    HARD easySettings;
    int maxPlatforms = easySettings.platformCount;
    float chanceStatic = easySettings.ChanceStatic;
    float chanceHorizontal = easySettings.ChanceHorizontal;
    float chanceVertical = easySettings.ChanceVertical;
    float minDistance = easySettings.minDistance;
    float maxDistance = easySettings.maxDistance;

    // Generate platforms
    while (ActivePlatforms < maxPlatforms) {
        float X_pos = Random::getInstance().getRandomFloat(camera.getCamerax() - 200, camera.getCamerax() + 200);
        float Y_pos = Random::getInstance().getRandomFloat(camera.getCamerax() - 395, camera.getCamerax() + 395);
        float chance = Random::getInstance().getRandomFloat(0.0f, 1.0f);

        std::shared_ptr<Platform> newPlatform;

        if (chance < chanceStatic) {
            newPlatform = factory->createPlatform(X_pos, Y_pos, PlatformType::STATIC);
        } else if (chance < chanceStatic + chanceHorizontal) {
            newPlatform = factory->createPlatform(X_pos, Y_pos, PlatformType::HORIZONTAL);
        } else if (chance < chanceStatic + chanceHorizontal + chanceVertical) {
            newPlatform = factory->createPlatform(X_pos, Y_pos, PlatformType::VERTICAL);
        }

        bool collisionDetected = false;
        for (const auto& entity : entities) {
            if (checkCollision(newPlatform, entity)) {
                collisionDetected = true;
                break;
            }

            // Additional checks for vertical platforms
            if (newPlatform->getPlatformType() == PlatformType::VERTICAL) {
                if (std::abs(newPlatform->getY() - entity->getY()) < minDistance ||
                    (newPlatform->getX() >= entity->getX() - entity->getWidth() / 2 - minDistance &&
                     newPlatform->getX() <= entity->getX() + entity->getWidth() / 2 + minDistance)) {
                    collisionDetected = true;
                    break;
                }
            }

            // Additional checks for horizontal platforms
            if (newPlatform->getPlatformType() == PlatformType::HORIZONTAL) {
                if (std::abs(newPlatform->getX() - entity->getX()) < minDistance ||
                    (newPlatform->getY() >= entity->getY() - entity->getHeight() / 2 - minDistance &&
                     newPlatform->getY() <= entity->getY() + entity->getHeight() / 2 + minDistance)) {
                    collisionDetected = true;
                    break;
                }
            }
        }

        bool ValidMinDistance = true;
        for (const auto& entity : entities) {
            float distanceX = std::abs(newPlatform->getX() - entity->getX());
            float distanceY = std::abs(newPlatform->getY() - entity->getY());
            std::cout<<distanceX<<std::endl;
            std::cout<<distanceY<<std::endl;
            if (distanceX < minDistance && distanceY < minDistance) {
                ValidMinDistance = false;
                break;
            }
        }

        bool ValidMaxDistance = false;
        for (const auto& entity : entities) {
            float distanceX = std::abs(newPlatform->getX() - entity->getX());
            float distanceY = std::abs(newPlatform->getY() - entity->getY());
            if (distanceX < maxDistance && distanceY < maxDistance) {
                ValidMaxDistance = true;
                break;
            }
        }


        if (!collisionDetected && ValidMinDistance && ValidMaxDistance) {
            entities.push_back(newPlatform);
            ActivePlatforms++;
        }
    }
}

// get the player reference
Player& World::getPlayer() {
    return *player;
}

// Get the entities
std::vector<std::shared_ptr<Entity>> World::getEntities() {
    return entities;
}

//update the world
void World::update(float deltaTime) {
    //update the player
    player->update(deltaTime);

    // Check for collisions
    for (const auto& entity : entities) {
        if (checkCollision_player(entity)) {
            entity->setHasCollided(true);
            player->jump();
        }
    }

    // Update the entities
    for (const auto& entity : entities) {
        entity->update(deltaTime);
    }




}


