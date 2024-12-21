#include "World.h"
#include "iostream"

// Constructor
World::World(const std::shared_ptr<AbstractFactory>& factory, float viewWidth, float viewHeight)
    : factory(factory), score(0), camera(viewWidth, viewHeight) { // Initialize camera with dimensions

    genWorld(); // Generate the world
}

// Check collision between two entities
bool World::checkCollision(std::shared_ptr<Entity> const& entity1, std::shared_ptr<Entity> const& entity2) {
    if (!entity1 || !entity2) return false; // Handle null pointers.

    BoundingBox box1 = entity1->getBoundingBox(); // Get bounding box of entity1
    BoundingBox box2 = entity2->getBoundingBox(); // Get bounding box of entity2

    return (box1.right >= box2.left && box1.left <= box2.right &&
            box1.bottom >= box2.top && box1.top <= box2.bottom); // Check for collision
}

// Check collision between player and entity
bool World::checkCollision_player(const std::shared_ptr<Entity>& entity) const {
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
    for (const auto& entity : entities) {
        float minY = camera.getCameraY() + camera.getViewHeight() / 2;
        if (entity->getY() > minY) {
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
    EASY easySettings;
    int maxPlatforms = easySettings.platformCount;
    float chanceStatic = easySettings.ChanceStatic;
    float chanceHorizontal = easySettings.ChanceHorizontal;
    float chanceVertical = easySettings.ChanceVertical;
    float minDistance = easySettings.minDistance;
    float maxDistance = easySettings.maxDistance;
    float chanceDisappearing = easySettings.ChanceDisappearing;
    genPlats(chanceStatic, chanceVertical, chanceHorizontal, chanceDisappearing, maxPlatforms, minDistance, maxDistance,camera.getCameraY() + 395, camera.getCameraY() - 100000);

}


void World::genPlats(float chanceStatic, float chanceVertical, float chanceHorizontal, float chanceDisappearing, int maxPlatforms, float minDistance, float maxDistance, float fromy, float toy) {
    // Generate platforms
    while (ActivePlatforms < maxPlatforms) {
        float X_pos = Random::getInstance().getRandomFloat(camera.getCameraX() - 200, camera.getCameraX() + 200);
        float Y_pos = Random::getInstance().getRandomFloat(toy, fromy);

        float chance = Random::getInstance().getRandomFloat(0.0f, 1.0f);

        std::shared_ptr<Platform> newPlatform;

        if (chance < chanceStatic) {
            newPlatform = factory->createPlatform(X_pos, Y_pos, PlatformType::STATIC);
        } else if (chance < chanceStatic + chanceHorizontal) {
            newPlatform = factory->createPlatform(X_pos, Y_pos, PlatformType::HORIZONTAL);
        } else if (chance < chanceStatic + chanceHorizontal + chanceVertical) {
            newPlatform = factory->createPlatform(X_pos, Y_pos, PlatformType::VERTICAL);
        } else if (chance < chanceStatic + chanceHorizontal + chanceVertical + chanceDisappearing) {
            newPlatform = factory->createPlatform(X_pos, Y_pos, PlatformType::DISAPPEARING);
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

        if (!collisionDetected && isValidMinDistance(minDistance, newPlatform) && isValidMaxDistance(maxDistance, newPlatform)) {
            entities.push_back(newPlatform);
            ActivePlatforms++;
        }
    }

}


//check if the max distance between platforms is valid
bool World::isValidMaxDistance(float MaxDistance, const std::shared_ptr<Entity>& newplat) const {
    for (const auto& entity : entities) {
        float distanceX = std::abs(newplat->getX() - entity->getX());
        float distanceY = std::abs(newplat->getY() - entity->getY());
        if (distanceX < MaxDistance && distanceY < MaxDistance) {
            return true;
        }
    }
    return false;
}

//check if the min distance between platforms is valid
bool World::isValidMinDistance(float minDistance, const std::shared_ptr<Entity>& newplat) const{
    for (const auto& entity : entities) {
        float distanceX = std::abs(newplat->getX() - entity->getX());
        float distanceY = std::abs(newplat->getY() - entity->getY());
        if (distanceX < minDistance && distanceY < minDistance) {
            return false;
        }
    }
    return true;
}

// get the player reference
Player& World::getPlayer() {
    return *player;
}

// Get the entities
std::vector<std::shared_ptr<Entity>> World::getEntities() {
    return entities;
}

void World::update(float deltaTime) {
    // Update the player
    player->update(deltaTime);
    // make sure player does not go out of view
    if(player->getY() < camera.getCameraY()){
        player->setPosition(player->getX(), camera.getCameraY());
    }
    // Update the camera
    camera.updateCameraY(player->getY());
    // Update the entities
    for (const auto& entity : entities) {
        if(entity->getY()>camera.getCameraY() + camera.getViewHeight() / 2){
            entity->setOutOfView(true);
            std::cout<<"Entity out of view"<<std::endl;
        }
        if(player->getVelocityY()<0){
            entity->setPosition(entity->getX(), entity->getY() - player->getVelocityY() * deltaTime);
        }
        entity->update(deltaTime);
    }
    // check for collisions
    for (const auto& entity : entities) {
        if (checkCollision_player(entity)) {
           entity->setHasCollided(true);
            player->jump();
            break;
        }
    }
    std::cout<<"entities size: "<<entities.size()<<std::endl;
    removeRemovableEntities(); // Remove entities which are out of view
}





