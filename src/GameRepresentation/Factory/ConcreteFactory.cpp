#include "ConcreteFactory.h"
#include "PlayerView.h"
#include "PlatformView.h"
#include "BonusView.h"
#include "BGtileView.h"
#include <memory>
#include <tuple> // For std::tuple

// Create a Player instance
std::shared_ptr<Player> ConcreteFactory::createPlayer(float x, float y) {
    auto player = std::make_shared<Player>(x, y); // Create a player
    auto playerView = std::make_shared<PlayerView>(player, currentWindow); // Create the player view
    player->attach(playerView); // Attach the view to the player
    return player; // Return the shared_ptr to the Player
}

// Create a Platform instance
std::shared_ptr<Platform> ConcreteFactory::createPlatform(float x, float y, PlatformType type) {
    std::shared_ptr<Platform> platform; // Create a platform based on the type

    // Create a platform based on the specified type
    switch (type) {
        case PlatformType::STATIC:
            platform = std::make_shared<Platform>(x, y); // Create a static platform
            break;
        case PlatformType::VERTICAL:
            platform = std::make_shared<VerticalPlatform>(x, y); // Create a vertical platform
            break;
        case PlatformType::HORIZONTAL:
            platform = std::make_shared<HorizontalPlatform>(x, y); // Create a horizontal platform
            break;
        case PlatformType::DISAPPEARING:
            platform = std::make_shared<Platform>(x, y); // Create a disappearing platform (implement as needed)
            break;
    }

    auto platformView = std::make_shared<PlatformView>(platform, currentWindow); // Create the platform view
    platform->attach(platformView); // Attach the view to the platform
    return platform; // Return the shared_ptr to the Platform
}

// Create a Bonus instance and return a tuple with Bonus and BonusView
std::shared_ptr<Bonus> ConcreteFactory::createBonus(float x, float y, BonusType type) {
    std::shared_ptr<Bonus> bonus; // Create a bonus based on the type

    // Create a bonus based on the specified type
    switch (type) {
        case BonusType::SPRING:
            bonus = std::make_shared<Spring>(x, y); // Create a spring bonus
            break;
        case BonusType::JETPACK:
            bonus = std::make_shared<Jetpack>(x, y); // Create a jetpack bonus
            break;
    }

    auto bonusView = std::make_shared<BonusView>(bonus, currentWindow); // Create the bonus view
    bonus->attach(bonusView); // Attach the view to the bonus
    return bonus; // Return the shared_ptr to the Bonus
}

// Create a BGtile instance
std::shared_ptr<BGtile> ConcreteFactory::createBGtile(float x, float y) {
    auto bgTile = std::make_shared<BGtile>(x, y); // Create a background tile
    auto bgTileView = std::make_shared<BGtileView>(bgTile, currentWindow); // Create the background tile view
    bgTile->attach(bgTileView); // Attach the view to the background tile
    return bgTile; // Return the shared_ptr to the BGtile
}