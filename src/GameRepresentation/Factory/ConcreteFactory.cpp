#include "ConcreteFactory.h"

std::unique_ptr<Player> ConcreteFactory::createPlayer(float x, float y) {
    auto player = std::make_unique<Player>(x, y); // Create a player
    auto playerView = std::make_unique<PlayerView>(*player,currentwindow); // Create the player view
    player->attach(std::move(playerView)); // Attach the view to the player
    return player; // Return the unique_ptr to the Player
}

std::unique_ptr<Platform> ConcreteFactory::createPlatform(float x, float y, PlatformType type) {
    std::unique_ptr<Platform> platform; // Create a platform based on the type
    switch (type) {
        case PlatformType::STATIC:
            platform = std::make_unique<Platform>(x, y); // Create a static platform
            break;
        case PlatformType::VERTICAL:
            platform = std::make_unique<VerticalPlatform>(x, y); // Create a vertical platform
            break;
        case PlatformType::HORIZONTAL:
            platform = std::make_unique<HorizontalPlatform>(x, y); // Create a horizontal platform
            break;
        case PlatformType::DISAPPEARING:
            platform = std::make_unique<Platform>(x, y); // Create a disappearing platform (implement as needed)
            break;
        default:
            return nullptr; // Handle unknown platform type
    }

    auto platformView = std::make_unique<PlatformView>(*platform,currentwindow); // Create the platform view
    platform->attach(std::move(platformView)); // Attach the view to the platform
    return platform; // Return the unique_ptr to the Platform
}

std::unique_ptr<Bonus> ConcreteFactory::createBonus(float x, float y, BonusType type) {
    std::unique_ptr<Bonus> bonus; // Create a bonus based on the type
    switch (type) {
        case BonusType::SPRING:
            bonus = std::make_unique<Spring>(x, y); // Create a spring bonus
            break;
        case BonusType::JETPACK:
            bonus = std::make_unique<Jetpack>(x, y); // Create a jetpack bonus
            break;
        default:
            return nullptr; // Handle unknown bonus type
    }

    auto bonusView = std::make_unique<BonusView>(*bonus,currentwindow); // Create the bonus view
    bonus->attach(std::move(bonusView)); // Attach the view to the bonus
    return bonus; // Return the unique_ptr to the Bonus
}