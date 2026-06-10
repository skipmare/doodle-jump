/**
 * @file World.cpp
 * @brief Implementation of the World class responsible for managing the game world, including entities, platforms, player, and collision detection.
 */

#include "World.h"
#include "iostream"

/**
 * @brief Constructor for the World class.
 *
 * Initializes the World object with a given factory, view dimensions, and creates the score entity.
 *
 * @param factory The factory used to create game entities.
 * @param viewWidth The width of the camera's view.
 * @param viewHeight The height of the camera's view.
 */
World::World(const std::shared_ptr<AbstractFactory>& factory, float viewWidth, float viewHeight)
    : score(nullptr), factory(factory), camera(viewWidth, viewHeight) {
    score = factory->createScore(150, 100); // Create the score entity
    genWorld(); // Generate the world
}

/**
 * @brief Checks for collision between two entities.
 *
 * This method checks whether two entities' bounding boxes intersect.
 *
 * @param entity1 The first entity.
 * @param entity2 The second entity.
 * @return true If the bounding boxes of the entities intersect.
 * @return false If the bounding boxes do not intersect.
 */
bool World::checkCollision(std::shared_ptr<Entity> const& entity1, std::shared_ptr<Entity> const& entity2) {
    if (!entity1 || !entity2) return false; // Handle null pointers.

    BoundingBox box1 = entity1->getBoundingBox();
    BoundingBox box2 = entity2->getBoundingBox();

    return (box1.right >= box2.left && box1.left <= box2.right &&
            box1.bottom >= box2.top && box1.top <= box2.bottom);
}

/**
 * @brief Checks for collision between the player and an entity.
 *
 * This method checks whether the player collides with a given entity, taking into account the platform type and collision settings.
 *
 * @param entity The entity to check collision with.
 * @return true If a collision is detected between the player and the entity.
 * @return false If no collision is detected.
 */
bool World::checkCollision_player(const std::shared_ptr<Entity>& entity) const {
    if (!entity || !player) return false;

    if (entity->getCollidable()) {
        if (entity->getCollisionOnLand()) {
            BoundingBox playerBox = player->getLandingBox();
            BoundingBox entityBox = entity->getBoundingBox();
            const float previousBottom = player->getPreviousY() + player->getHeight() / 2.0f;
            const bool crossedPlatformTop = previousBottom <= entityBox.top && playerBox.bottom >= entityBox.top;
            const bool overlapsHorizontally = playerBox.right >= entityBox.left && playerBox.left <= entityBox.right;
            return crossedPlatformTop && overlapsHorizontally && player->isFalling();
        } else {
            return checkCollision(player, entity);
        }
    }
    return false;
}

/**
 * @brief Removes entities and bonuses that are out of view.
 *
 * Entities and bonuses that have moved beyond the camera view are marked for removal and deleted from the world.
 */
void World::removeRemovableEntities() {
    // Check if the entity is out of view
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
            ActivePlatforms--;
        } else {
            ++it;
        }
    }

    // Remove bonuses which are out of view
    for (auto it = bonuses.begin(); it != bonuses.end();) {
        if ((*it)->getOutOfView()) {
            it = bonuses.erase(it);
        } else {
            ++it;
        }
    }
}

/**
 * @brief Generates the world by creating entities, platforms, and the player.
 *
 * This method clears the existing world, resets the platform count, and creates the player and initial platforms.
 */
void World::genWorld() {
    entities.clear();
    bonuses.clear();
    background.clear();
    ActivePlatforms = 0;

    player = factory->createPlayer(0, 0); // Create the player entity
    player->setPosition(250, 530); // Set player position on top of the static platform

    // Hard code a static platform at (250, 200)
    std::shared_ptr<Platform> staticPlatform = factory->createPlatform(250, 600, PlatformType::STATIC);
    entities.push_back(staticPlatform);
    pathAnchor = staticPlatform;
    ActivePlatforms++;

    extendPlayablePath(camera.getCameraY() - camera.getViewHeight());
    generateBackground(camera.getCameraY() + 400, camera.getCameraY() - 400);
}

/**
 * @brief Generates platforms within a specified vertical range.
 *
 * Extends the guaranteed playable route to the top of the requested Y-range.
 *
 * @param fromy The upper Y-bound of the platform generation range.
 * @param toy The lower Y-bound of the platform generation range.
 */
void World::genPlats(float fromy, float toy) {
    extendPlayablePath(std::min(fromy, toy));
}

float World::maximumReachableHorizontalDistance(float verticalGap) {
    if (verticalGap <= 0.0f) {
        return 0.0f;
    }

    const float jumpSpeed = Player::NormalJumpSpeed;
    const float gravity = Player::NormalGravity;
    const float discriminant = jumpSpeed * jumpSpeed - 2.0f * gravity * verticalGap;
    if (discriminant <= 0.0f) {
        return 0.0f;
    }

    // Landing occurs at the descending intersection with the target platform height.
    const float flightTime = (jumpSpeed + std::sqrt(discriminant)) / gravity;
    const float accelerationTime = Player::MaximumMoveSpeed / Player::MoveAcceleration;
    float travelDistance = 0.0f;
    if (flightTime <= accelerationTime) {
        travelDistance = 0.5f * Player::MoveAcceleration * flightTime * flightTime;
    } else {
        travelDistance =
            0.5f * Player::MoveAcceleration * accelerationTime * accelerationTime +
            Player::MaximumMoveSpeed * (flightTime - accelerationTime);
    }

    // The feet sit behind the facing direction, so only their leading edge counts toward reach.
    constexpr float playerHalfWidth =
        Player::LandingFootWidth / 2.0f - Player::LandingFootOffset;
    constexpr float platformHalfWidth = 40.0f;
    return travelDistance + playerHalfWidth + platformHalfWidth;
}

bool World::isPlatformReachable(float fromX, float fromY, float toX, float toY) {
    const float verticalGap = fromY - toY;
    return verticalGap > 0.0f &&
           std::abs(toX - fromX) <= maximumReachableHorizontalDistance(verticalGap);
}

/**
 * @brief Checks if the maximum distance between platforms is valid.
 *
 * The method checks if a new platform is within the allowed maximum distance from existing platforms.
 *
 * @param MaxDistance The maximum allowed distance between platforms.
 * @param newplat The new platform to check.
 * @return true If the new platform is within the maximum distance.
 * @return false If the new platform is too far from other platforms.
 */
bool World::isValidMaxDistance(float MaxDistance, const std::shared_ptr<Entity>& newplat) const {
    return std::any_of(entities.begin(), entities.end(), [&](const auto& entity) {
        return entity->getPlatformType() != DISAPPEARING &&
               entity->getY() - newplat->getY() <= MaxDistance &&
               isPlatformReachable(entity->getX(), entity->getY(), newplat->getX(), newplat->getY());
    });
}

/**
 * @brief Checks if the minimum distance between platforms is valid.
 *
 * The method ensures that new platforms are not too close to each other.
 *
 * @param minDistance The minimum required distance between platforms.
 * @param newplat The new platform to check.
 * @return true If the new platform is sufficiently far from existing platforms.
 * @return false If the new platform is too close to other platforms.
 */
bool World::isValidMinDistance(float minDistance, const std::shared_ptr<Entity>& newplat) const {
    return !std::any_of(entities.begin(), entities.end(), [&](const auto& entity) {
        float distanceX = std::abs(newplat->getX() - entity->getX());
        float distanceY = std::abs(newplat->getY() - entity->getY());
        return (distanceX < minDistance && distanceY < minDistance);
    });
}

/**
 * @brief Updates the world by processing all entities, the player, and checking collisions.
 *
 * This method updates the camera, background, entities, and player while checking for collisions and removing out-of-view entities.
 *
 * @param deltaTime The time elapsed since the last update.
 */
void World::update(float deltaTime) {
    updateCamera();
    updateBackground(deltaTime);
    updateEntities(deltaTime);
    updatePlayer(deltaTime);
    CheckBonusCollision();
    checkCollisions();
    removeRemovableEntities();
    CheckDifficulty();
    generateNewPlatforms();
    checkGameOver();
}

void World::render() const {
    for (const auto& bgTile : background) {
        bgTile->notify();
    }
    for (const auto& entity : entities) {
        entity->notify();
    }
    for (const auto& bonus : bonuses) {
        bonus->notify();
    }
    player->notify();
    score->notify();
}

/**
 * @brief Updates the player by applying delta time to its movement.
 *
 * This method ensures the player is updated with the elapsed time and that the player doesn't go out of view.
 *
 * @param deltaTime The time elapsed since the last update.
 */
void World::updatePlayer(float deltaTime) const {
    player->update(deltaTime);
    if (player->getY() < camera.getCameraY()) {
        player->setPosition(player->getX(), camera.getCameraY());
    }
}

/**
 * @brief Updates the camera by adjusting its position based on the player's Y-coordinate.
 */
void World::updateCamera() {
    camera.updateCameraY(player->getY());
}

/**
 * @brief Updates all entities in the world.
 *
 * This method updates the positions and states of all entities, including platforms and bonuses.
 *
 * @param deltaTime The time elapsed since the last update.
 */
void World::updateEntities(float deltaTime) {
    const bool isCameraScrolling =
        player->getVelocityY() < 0 && std::abs(camera.getCameraY() - player->getY()) < 0.001f;

    for (const auto& entity : entities) {
        if (entity->getY() > camera.getCameraY() + camera.getViewHeight() / 2) {
            entity->setOutOfView(true);
        }

        if (isCameraScrolling) {
            if(entity->getPlatformType()==VERTICAL) {
                entity->setPosition(entity->getX(), entity->getInitialY() - player->getVelocityY() * deltaTime);
            } else {
                entity->setPosition(entity->getX(), entity->getY() - player->getVelocityY() * deltaTime);
            }
        }

        entity->update(deltaTime);
    }

    for (const auto& bonus : bonuses) {
        if (bonus->getY() > camera.getCameraY() + camera.getViewHeight() / 2) {
            bonus->setOutOfView(true);
        }
        bonus->update(deltaTime);
    }

    if (isCameraScrolling) {
        score->setScore(score->getScore() - player->getVelocityY() * deltaTime);
    }
    score->update(deltaTime);
}

/**
 * @brief Checks for collisions between the player and entities.
 *
 * This method checks if the player collides with any of the entities in the world and processes the collision.
 */
void World::checkCollisions() {
    for (const auto& entity : entities) {
        if (checkCollision_player(entity)) {
            entity->setHasCollided(true);
            if(entity->getJumpTrigger()) {
                player->jump();
            }
            break;
        }
    }
}

/**
 * @brief Generates new platforms if necessary.
 *
 * This method generates new platforms below the camera view if needed.
 */
void World::generateNewPlatforms() {
    const float targetY = camera.getCameraY() - camera.getViewHeight();
    extendPlayablePath(targetY);
}

void World::extendPlayablePath(float targetY) {
    if (!pathAnchor) {
        return;
    }

    const auto& settings = getDifficulty();
    while (pathAnchor->getY() > targetY) {
        const auto previousPathPlatform = pathAnchor;
        const float verticalGap =
            Random::getInstance().getRandomFloat(settings.minDistance, settings.maxDistance);
        const float physicalHorizontalLimit = maximumReachableHorizontalDistance(verticalGap);
        const float safeHorizontalLimit =
            std::min(settings.maxHorizontalDistance, physicalHorizontalLimit * 0.70f);
        const float y = previousPathPlatform->getY() - verticalGap;
        const float minimumOffset =
            std::max(-safeHorizontalLimit, 40.0f - previousPathPlatform->getX());
        const float maximumOffset =
            std::min(safeHorizontalLimit, 460.0f - previousPathPlatform->getX());

        float x = previousPathPlatform->getX();
        for (int attempt = 0; attempt < 12; ++attempt) {
            const float horizontalOffset =
                Random::getInstance().getRandomFloat(minimumOffset, maximumOffset);
            const float candidateX = previousPathPlatform->getX() + horizontalOffset;
            auto candidate = std::make_shared<StaticPlatform>(candidateX, y);
            const bool overlapsExisting =
                std::any_of(entities.begin(), entities.end(), [&](const auto& entity) {
                    return checkCollision(candidate, entity);
                });
            if (!overlapsExisting) {
                x = candidateX;
                break;
            }
        }

        auto nextPathPlatform = factory->createPlatform(x, y, PlatformType::STATIC);
        genBonus(nextPathPlatform);
        entities.push_back(nextPathPlatform);
        pathAnchor = nextPathPlatform;
        ActivePlatforms++;

        tryGenerateChallengePlatform(previousPathPlatform, nextPathPlatform);
    }
}

void World::tryGenerateChallengePlatform(
    const std::shared_ptr<Platform>& fromPlatform,
    const std::shared_ptr<Platform>& pathPlatform) {
    const auto& settings = getDifficulty();
    if (Random::getInstance().getRandomFloat(0.0f, 1.0f) > settings.ChallengePlatformChance) {
        return;
    }

    const float verticalGap =
        Random::getInstance().getRandomFloat(settings.minDistance * 0.70f, settings.maxDistance);
    const float reachableDistance = maximumReachableHorizontalDistance(verticalGap) * 0.65f;
    const float maximumOffset = std::min(settings.maxHorizontalDistance * 1.15f, reachableDistance);
    const float minimumOffset = std::min(80.0f, maximumOffset * 0.55f);
    const float pathDirection = pathPlatform->getX() - fromPlatform->getX();
    const float branchDirection = pathDirection >= 0.0f ? -1.0f : 1.0f;
    const float offset =
        branchDirection * Random::getInstance().getRandomFloat(minimumOffset, maximumOffset);
    const float x = std::max(40.0f, std::min(460.0f, fromPlatform->getX() + offset));
    const float y = fromPlatform->getY() - verticalGap;

    auto candidate = std::make_shared<StaticPlatform>(x, y);
    const bool overlapsExisting = std::any_of(entities.begin(), entities.end(), [&](const auto& entity) {
        return checkCollision(candidate, entity);
    });
    if (overlapsExisting ||
        !isPlatformReachable(fromPlatform->getX(), fromPlatform->getY(), x, y)) {
        return;
    }

    auto challengePlatform = factory->createPlatform(x, y, randomChallengePlatformType());
    genBonus(challengePlatform);
    entities.push_back(challengePlatform);
    ActivePlatforms++;
}

PlatformType World::randomChallengePlatformType() const {
    const auto& settings = getDifficulty();
    const float nonStaticChance =
        settings.ChanceHorizontal + settings.ChanceVertical + settings.ChanceDisappearing;
    const float chance = Random::getInstance().getRandomFloat(0.0f, nonStaticChance);
    if (chance < settings.ChanceHorizontal) {
        return PlatformType::HORIZONTAL;
    }
    if (chance < settings.ChanceHorizontal + settings.ChanceVertical) {
        return PlatformType::VERTICAL;
    }
    return PlatformType::DISAPPEARING;
}

/**
 * @brief Generates new background tiles if necessary.
 *
 * This method generates new background tiles based on the camera's position.
 */
void World::generateNewTiles() {
    generateBackground(camera.getCameraY() - 400, camera.getCameraY() - 800);
}

/**
 * @brief Checks if the game is over.
 *
 * This method checks if the player has fallen out of the game world and resets the game state if necessary.
 */
void World::checkGameOver() {
    const float bottomOfView = camera.getCameraY() + camera.getViewHeight() / 2.0f;
    if (player->getY() - player->getHeight() / 2.0f > bottomOfView) {
        isGameOver = true;
        std::cout << "Game Over" << std::endl;
    }

    if (isGameOver) {
        score->ResetScore();
        camera.resetCamera();
        isGameOver = false;
        genWorld();
    }
}

/**
 * @brief Generates the background tiles for the world.
 *
 * This method creates background tiles within the specified vertical range and populates the background.
 *
 * @param from_y The upper Y-bound of the background generation range.
 * @param to_y The lower Y-bound of the background generation range.
 */
void World::generateBackground(float from_y, float to_y) {
    float viewWidth = camera.getViewWidth();

    // Generate background tiles
    for (float y = from_y; y >= to_y; y -= 40.0f) {
        for (float x = camera.getCameraX() - viewWidth / 2 + 20.0f;
             x <= camera.getCameraX() + viewWidth / 2;
             x += 40.0f) {
            std::shared_ptr<BGtile> bgTile = factory->createBGtile(x, y);
            background.push_back(bgTile);
        }
    }
}
/**
 * @brief Updates the background by checking if any tiles are out of view, and if so, moves them.
 * Also, handles tile-specific updates and adjusts the background position when the player moves.
 *
 * @param deltaTime The time elapsed since the last update, used to adjust the movement of background tiles.
 */
void World::updateBackground(float deltaTime) {
    float viewHeight = camera.getViewHeight();
    float cameraY = camera.getCameraY();

    for (const auto& bgTile : background) {
        // Mark background tile out of view if it has moved past the camera view
        if (bgTile->getY() > cameraY + viewHeight / 2 + bgTile->getHeight() / 2) {
            bgTile->setOutOfView(true);
        }

        // Move the background tiles down if the player is going up
        if (player->getVelocityY() < 0 &&
            std::abs(camera.getCameraY() - player->getY()) < 0.001f) {
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

    float currentX = camera.getCameraX() - camera.getViewWidth() / 2.0f + 20.0f;
    float nextY = lowestY - 40.0f;
    for (auto& bgTile : background) {
        if (bgTile->getOutOfView()) {
            bgTile->setOutOfView(false);
            bgTile->setPosition(currentX, nextY);
            currentX += bgTile->getHeight();
            if (currentX > camera.getCameraX() + camera.getViewWidth() / 2.0f) {
                currentX = camera.getCameraX() - camera.getViewWidth() / 2.0f + 20.0f;
                nextY -= bgTile->getHeight();
            }
        }
    }
}

/**
 * @brief Retrieves the current difficulty settings based on the game's difficulty level.
 *
 * @return A reference to the current difficulty settings.
 * @throws std::runtime_error if the difficulty level is unknown.
 */
const DifficultySettings& World::getDifficulty() const {
    static EASY easy;
    static MEDIUM medium;
    static HARD hard;

    switch(difficulty) {
        case Difficulty::EASY:
            return easy;
        case Difficulty::MEDIUM:
            return medium;
        case Difficulty::HARD:
            return hard;
    }
    throw std::runtime_error("Unknown difficulty level");
}

/**
 * @brief Sets the difficulty level of the game.
 *
 * @param difficulty The desired difficulty level to set.
 */
void World::setDifficulty(Difficulty difficulty) {
    this->difficulty = difficulty;
}

/**
 * @brief Spawns bonus platforms based on a random spawn rate and the current difficulty level.
 * If a bonus is to be spawned, it can either be a spring or a jetpack, and the bonus is linked to a platform.
 *
 * @param entity A shared pointer to the platform where the bonus might be spawned.
 */
void World::genBonus(const std::shared_ptr<Platform>& entity) {
    float SpawnRate = Random::getInstance().getRandomFloat(0.0f, 1.0f);
    if(entity->getPlatformType()!=DISAPPEARING) {
        if(SpawnRate < getDifficulty().ChanceBonus) {
            float springRate = Random::getInstance().getRandomFloat(0.0f, 1.0f);
            if(springRate < 0.7f) {
                std::shared_ptr<Bonus> newbonus = factory->createBonus(0, 0, BonusType::SPRING, entity);
                bonuses.push_back(newbonus);
            } else {
                std::shared_ptr<Bonus> newbonus = factory->createBonus(0, 0, BonusType::JETPACK, entity);
                bonuses.push_back(newbonus);
            }
        }
    }
}

/**
 * @brief Checks for collisions between the player and any bonuses. If a collision is detected,
 * the corresponding bonus effect is applied to the player.
 */
void World::CheckBonusCollision() {
    for (const auto& bonus : bonuses) {
        if (!bonus->getHasCollided() && checkCollision_player(bonus)) {
            bonus->setHasCollided(true);
            player->applyBonusEffect(bonus->getType());
        }
    }
}

/**
 * @brief Checks the player's score and adjusts the game difficulty accordingly.
 * If the score crosses certain thresholds, the difficulty level is increased.
 */
void World::CheckDifficulty() {
    if(score->getScore()/100 >= 25 && score->getScore()/100 < 75) {
        setDifficulty(Difficulty::MEDIUM);
    } else if(score->getScore()/100 >= 75) {
        setDifficulty(Difficulty::HARD);
    } else {
        setDifficulty(Difficulty::EASY);
    }
}

/**
 * @brief Moves the player in a given direction.
 *
 * @param direction The direction to move the player. A positive value typically represents rightward movement, and negative values represent leftward movement.
 */
void World::PlayerMove(int direction) const {
    player->setMoveDirection(direction);
}

int World::getScore() const {
    return score->getScore();
}

std::shared_ptr<Player> World::getPlayer() const {
    return player;
}

bool World::getGameOver() const {
    return isGameOver;
}

void World::setGameOver(bool gameOver) {
    isGameOver = gameOver;
}

void World::updateBonuses(float deltaTime) {
    for (const auto& bonus : bonuses) {
        bonus->update(deltaTime);
    }
}
