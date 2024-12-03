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

class AbstractFactory {
public:
    virtual std::shared_ptr<Player> createPlayer(float x, float y) = 0; // Create a Player
    virtual std::shared_ptr<Platform> createPlatform(float x, float y, PlatformType type) = 0; // Create a Platform
    virtual std::shared_ptr<Bonus> createBonus(float x, float y, BonusType type) = 0; // Create a Bonus
    virtual std::shared_ptr<BGtile> createBGtile(float x, float y) = 0; // Create a BGtile
    virtual ~AbstractFactory() = default; // Virtual destructor
};

#endif //INC_2024_PROJECT_SKIPMARE_ABSTRACTFACTORY_H
