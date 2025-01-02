#include "ConcreteFactory.h"

// Create a Player instance
/**
 * @brief Creates a Player instance and its associated PlayerView.
 *
 * This method creates a Player object at the specified position and a PlayerView that represents
 * the visual aspects of the Player. The view is attached to the player, ensuring that changes to
 * the player's state are reflected in the view.
 *
 * @param x The x-coordinate for the player's position.
 * @param y The y-coordinate for the player's position.
 * @return A shared pointer to the created Player object.
 */
std::shared_ptr<Player> ConcreteFactory::createPlayer(float x, float y) {
    auto player = std::make_shared<Player>(x, y); // Create a player
    auto playerView = std::make_shared<PlayerView>(player, currentWindow); // Create the player view
    player->attach(playerView); // Attach the view to the player
    return player; // Return the shared_ptr to the Player
}

// Create a Platform instance
/**
 * @brief Creates a Platform instance based on the specified type and position.
 *
 * This method creates a Platform object based on the given platform type (Static, Vertical,
 * Horizontal, or Disappearing) and position. It also creates a corresponding PlatformView to represent
 * the platform visually and attaches it to the platform.
 *
 * @param x The x-coordinate for the platform's position.
 * @param y The y-coordinate for the platform's position.
 * @param type The type of platform to create (e.g., Static, Vertical, Horizontal, Disappearing).
 * @return A shared pointer to the created Platform object.
 */
std::shared_ptr<Platform> ConcreteFactory::createPlatform(float x, float y, PlatformType type) {
    std::shared_ptr<Platform> platform; // Create a platform based on the type

    // Create a platform based on the specified type
    switch (type) {
        case PlatformType::STATIC:
            platform = std::make_shared<StaticPlatform>(x, y); // Create a static platform
            break;
        case PlatformType::VERTICAL:
            platform = std::make_shared<VerticalPlatform>(x, y); // Create a vertical platform
            break;
        case PlatformType::HORIZONTAL:
            platform = std::make_shared<HorizontalPlatform>(x, y); // Create a horizontal platform
            break;
        case PlatformType::DISAPPEARING:
            platform = std::make_shared<DisappearingPlatform>(x, y); // Create a disappearing platform
            break;
    }

    auto platformView = std::make_shared<PlatformView>(platform, currentWindow); // Create the platform view
    platform->attach(platformView); // Attach the view to the platform
    return platform; // Return the shared_ptr to the Platform
}

// Create a Bonus instance and return a tuple with Bonus and BonusView
/**
 * @brief Creates a Bonus instance and its associated BonusView.
 *
 * This method creates a Bonus object of the specified type (e.g., Spring or Jetpack) at the given position,
 * associated with a platform. It also creates a BonusView and attaches it to the bonus.
 *
 * @param x The x-coordinate for the bonus's position.
 * @param y The y-coordinate for the bonus's position.
 * @param type The type of bonus to create (e.g., Spring, Jetpack).
 * @param platform A shared pointer to the platform associated with the bonus.
 * @return A shared pointer to the created Bonus object.
 */
std::shared_ptr<Bonus> ConcreteFactory::createBonus(float x, float y, BonusType type, std::shared_ptr<Platform> platform) {
    std::shared_ptr<Bonus> bonus; // Create a bonus based on the type

    // Create a bonus based on the specified type
    switch (type) {
        case BonusType::SPRING:
            bonus = std::make_shared<Spring>(x, y, platform); // Create a spring bonus
            break;
        case BonusType::JETPACK:
            bonus = std::make_shared<Jetpack>(x, y,platform); // Create a jetpack bonus
            break;
    }

    auto bonusView = std::make_shared<BonusView>(bonus, currentWindow); // Create the bonus view
    bonus->attach(bonusView); // Attach the view to the bonus
    return bonus; // Return the shared_ptr to the Bonus
}

// Create a BGtile instance
/**
 * @brief Creates a BGtile (background tile) instance and its associated BGtileView.
 *
 * This method creates a BGtile object at the specified position and creates a BGtileView to represent
 * the visual aspect of the BGtile. The view is attached to the BGtile.
 *
 * @param x The x-coordinate for the BGtile's position.
 * @param y The y-coordinate for the BGtile's position.
 * @return A shared pointer to the created BGtile object.
 */
std::shared_ptr<BGtile> ConcreteFactory::createBGtile(float x, float y) {
    auto bgTile = std::make_shared<BGtile>(x, y); // Create a background tile
    auto bgTileView = std::make_shared<BGtileView>(bgTile, currentWindow); // Create the background tile view
    bgTile->attach(bgTileView); // Attach the view to the background tile
    return bgTile; // Return the shared_ptr to the BGtile
}

// Create a Score instance
/**
 * @brief Creates a Score instance and its associated ScoreView.
 *
 * This method creates a Score object at the specified position and creates a ScoreView to represent
 * the visual aspect of the score. The view is attached to the Score.
 *
 * @param x The x-coordinate for the score's position.
 * @param y The y-coordinate for the score's position.
 * @return A shared pointer to the created Score object.
 */
std::shared_ptr<Score> ConcreteFactory::createScore(float x, float y) {
    auto score = std::make_shared<Score>(x, y); // Create a score
    auto scoreView = std::make_shared<ScoreView>(score, currentWindow); // Create the score view
    score->attach(scoreView); // Attach the view to the score
    return score; // Return the shared_ptr to the Score
}
