//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_ABSTRACTFACTORY_H
#define INC_2024_PROJECT_SKIPMARE_ABSTRACTFACTORY_H

#include <memory>
#include "Player.h"
#include "../Logic/Entities/Platforms/Platform.h"
#include "../Logic/Entities/Bonuses/Bonus.h"
#include "Entity.h"
#include "../Logic/Entities/Platforms/StaticPlatform.h"
#include "../Logic/Entities/Platforms/DisappearingPlatform.h"
#include "../Logic/Entities/Platforms/VerticalPlatform.h"
#include "../Logic/Entities/Platforms/HorizontalPlatform.h"
#include "../Logic/Entities/BGtile.h"
#include <Bonuses/Jetpack.h>
#include <Bonuses/Spring.h>
#include "../Logic/Entities/Score.h"

/**
 * @class AbstractFactory
 * @brief An abstract base class for creating different game entities like Player, Platform, Bonus, etc.
 *
 * This factory pattern provides a common interface for creating various game objects.
 * The concrete implementation of this factory will define how each object is created.
 */
class AbstractFactory {
public:
    /**
     * @brief Creates a player entity.
     *
     * @param x The x-coordinate of the player.
     * @param y The y-coordinate of the player.
     * @return A shared pointer to the created Player object.
     */
    virtual std::shared_ptr<Player> createPlayer(float x, float y) = 0;

    /**
     * @brief Creates a platform entity.
     *
     * @param x The x-coordinate of the platform.
     * @param y The y-coordinate of the platform.
     * @param type The type of platform to create (e.g., Static, Disappearing, Vertical, Horizontal).
     * @return A shared pointer to the created Platform object.
     */
    virtual std::shared_ptr<Platform> createPlatform(float x, float y, PlatformType type) = 0;

    /**
     * @brief Creates a bonus entity.
     *
     * @param x The x-coordinate of the bonus.
     * @param y The y-coordinate of the bonus.
     * @param type The type of bonus to create (e.g., Jetpack, Spring).
     * @param platform A shared pointer to the platform associated with the bonus.
     * @return A shared pointer to the created Bonus object.
     */
    virtual std::shared_ptr<Bonus> createBonus(float x, float y, BonusType type, std::shared_ptr<Platform> platform) = 0;

    /**
     * @brief Creates a background tile entity.
     *
     * @param x The x-coordinate of the background tile.
     * @param y The y-coordinate of the background tile.
     * @return A shared pointer to the created BGtile object.
     */
    virtual std::shared_ptr<BGtile> createBGtile(float x, float y) = 0;

    /**
     * @brief Creates a score entity.
     *
     * @param x The x-coordinate of the score display.
     * @param y The y-coordinate of the score display.
     * @return A shared pointer to the created Score object.
     */
    virtual std::shared_ptr<Score> createScore(float x, float y) = 0;

    /**
     * @brief Virtual destructor for AbstractFactory class.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~AbstractFactory() = default;
};

#endif //INC_2024_PROJECT_SKIPMARE_ABSTRACTFACTORY_H
