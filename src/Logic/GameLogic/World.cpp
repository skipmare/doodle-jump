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
    player->setPosition(250, 530);

    //create the score entity
    score = factory->createScore(150,100);

    // Generate additional platforms as needed
    EASY easySettings;
    float chanceStatic = easySettings.ChanceStatic;
    float chanceHorizontal = easySettings.ChanceHorizontal;
    float chanceVertical = easySettings.ChanceVertical;
    float minDistance = easySettings.minDistance;
    float chanceDisappearing = easySettings.ChanceDisappearing;
    genPlats(chanceStatic, chanceVertical, chanceHorizontal, chanceDisappearing,  minDistance,easySettings.maxDistance, camera.getCameraY() + 395, camera.getCameraY() - 395);
    generateBackground(camera.getCameraY() + 400, camera.getCameraY() - 400);
}

void World::genPlats(float chanceStatic, float chanceVertical, float chanceHorizontal, float chanceDisappearing, float minDistance, float maxDistance, float fromy, float toy) {

    bool canGenerateMore = true;

    while (canGenerateMore) {
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
            std::cout<<"New platform generated"<<std::endl;
            ActivePlatforms++;
        }

        // Check if we can generate more platforms in the given range
        canGenerateMore = false;
        for (float y = toy; y <= fromy; y += minDistance) {
            bool spaceAvailable = true;
            for (const auto& entity : entities) {
                if (std::abs(entity->getY() - y) < minDistance) {
                    spaceAvailable = false;
                    break;
                }
            }

            if (spaceAvailable) {
                canGenerateMore = true;
                break;
            }
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
std::vector<std::shared_ptr<Platform>> World::getEntities() const{
    return entities;
}
void World::update(float deltaTime) {
    updateCamera();                        // Update camera position
    updateBackground(deltaTime);          // Update background tiles
    updateEntities(deltaTime);             // Update all entities (platforms, etc.)
    updatePlayer(deltaTime);               // Update player
    checkCollisions();                     // Check for player collisions with entities
    removeRemovableEntities();             // Remove entities that are out of view
    generateNewPlatforms();                // Generate new platforms if needed
    checkGameOver();                       // Check if the game is over
}

// Function to update the player
void World::updatePlayer(float deltaTime) {
    player->update(deltaTime);  // Update the player with the deltaTime

    // Make sure player doesn't go out of view
    if (player->getY() < camera.getCameraY()) {
        player->setPosition(player->getX(), camera.getCameraY());
    }
}

// Function to update the camera
void World::updateCamera() {
    camera.updateCameraY(player->getY());  // Update the camera's Y position based on the player
}

// Function to update the entities (platforms, etc.)
void World::updateEntities(float deltaTime) {
    for (const auto& entity : entities) {
        // Mark entity out of view if it has moved past the camera view
        if (entity->getY() > camera.getCameraY() + camera.getViewHeight() / 2) {
            entity->setOutOfView(true);
        }

        // Move the platforms down if the player is going up
        if (player->getVelocityY() < 0 && !player->getCollisionWithPlatform()) {
            entity->setPosition(entity->getX(), entity->getY() - player->getVelocityY() * deltaTime);
            score->setScore(score->getScore() - player->getVelocityY() * deltaTime);
        }
        // Update entity (handle entity-specific updates)
        entity->update(deltaTime);
        score->update(deltaTime);
    }
}

// Function to check for collisions between player and entities
void World::checkCollisions() {
    for (const auto& entity : entities) {
        if (checkCollision_player(entity)) {
            player->setCWP(entity->getHasCollided());
            entity->setHasCollided(true);
            if(entity->getJumpTrigger()) {
                player->jump();  // Make player jump upon collision
            }
            break;  // Assuming one collision is enough for now
        }
    }
}

// Function to generate new platforms if needed
void World::generateNewPlatforms() {
    EASY easySettings;
    float minDistance = easySettings.minDistance;

    genPlats(easySettings.ChanceStatic, easySettings.ChanceVertical, easySettings.ChanceHorizontal, easySettings.ChanceDisappearing,minDistance,easySettings.maxDistance,camera.getCameraY() - 395, camera.getCameraY() - 800);
}

void World::generateNewTiles() {
    generateBackground(camera.getCameraY() - 400, camera.getCameraY() - 800);
}

// Function to check if the game is over
void World::checkGameOver() {
    if (player->getY() > 800) {
        isGameOver = true;
    }

    if (isGameOver) {
    }
}

//function to generate the background tiles for the world
void World::generateBackground(float from_y, float to_y) {
    float viewWidth = camera.getViewWidth();

    // Generate background tiles
    for (float y = from_y; y >= to_y-50; y -= 50) {
        for (float x = camera.getCameraX() - viewWidth / 2; x <= camera.getCameraX() + viewWidth / 2; x += 50) {
            std::shared_ptr<BGtile> bgTile = factory->createBGtile(x, y);
            background.push_back(bgTile);
        }
    }
}

void World::updateBackground(float deltaTime) {
    float viewHeight = camera.getViewHeight();
    float cameraY = camera.getCameraY();

    for (const auto& bgTile : background) {
        // Mark background tile out of view if it has moved past the camera view
        if (bgTile->getY() > cameraY + viewHeight / 2 + bgTile->getHeight() / 2) {
            bgTile->setOutOfView(true);
        }

        // Move the background tiles down if the player is going up
        if (player->getVelocityY() < 0 && !player->getCollisionWithPlatform()) {
            bgTile->setPosition(bgTile->getX(), bgTile->getY() - player->getVelocityY() * deltaTime);
        }

        // Update background tile (handle tile-specific updates)
        bgTile->update(deltaTime);
    }

    float lowestY = std::numeric_limits<float>::max();

    // Find the tile with the lowest Y position
    for (const auto& bgTile : background) {
        if (bgTile->getY() < lowestY) {
            lowestY = bgTile->getY();
        }
    }

    float currentX = 0.0f;
    for (auto& bgTile : background) {
        if (bgTile->getOutOfView()) {
            bgTile->setOutOfView(false);
            bgTile->setPosition(currentX, lowestY - bgTile->getHeight());
            currentX += bgTile->getHeight();
            if (currentX > 500) {
                currentX = 0.0f;
            }
        }
    }
}



