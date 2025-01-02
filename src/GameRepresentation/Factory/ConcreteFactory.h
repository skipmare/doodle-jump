#ifndef INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H
#define INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H

#include "AbstractFactory.h" // Include the abstract factory header
#include "PlayerView.h"
#include "PlatformView.h"
#include "BonusView.h"
#include "BGtileView.h"
#include <memory>
#include "ConcreteFactory.h"
#include "ScoreView.h"

/**
 * @class ConcreteFactory
 * @brief A concrete implementation of the AbstractFactory.
 *
 * The ConcreteFactory is responsible for creating various game objects such as Player, Platform, Bonus, BGtile, and Score.
 * It creates both the game entities and their corresponding views. The factory provides the methods to instantiate these objects
 * with the necessary parameters, using the provided window reference.
 */
class ConcreteFactory : public AbstractFactory {
public:
    /**
     * @brief Constructs a ConcreteFactory with a window reference.
     *
     * Initializes the factory with a shared pointer to the render window, which is used for creating views.
     *
     * @param window A shared pointer to the SFML render window.
     */
    explicit ConcreteFactory(const std::shared_ptr<sf::RenderWindow>& window) : currentWindow(window) {}

    /**
     * @brief Creates a Player instance and returns it.
     *
     * This method creates a Player object at the specified position and returns a shared pointer to it.
     *
     * @param x The x-coordinate for the player's position.
     * @param y The y-coordinate for the player's position.
     * @return A shared pointer to the created Player object.
     */
    std::shared_ptr<Player> createPlayer(float x, float y) override;

    /**
     * @brief Creates a Platform instance and returns it.
     *
     * This method creates a Platform object of the specified type at the given position and returns a shared pointer to it.
     *
     * @param x The x-coordinate for the platform's position.
     * @param y The y-coordinate for the platform's position.
     * @param type The type of platform to create (e.g., Static, Disappearing).
     * @return A shared pointer to the created Platform object.
     */
    std::shared_ptr<Platform> createPlatform(float x, float y, PlatformType type) override;

    /**
     * @brief Creates a Bonus instance and returns it.
     *
     * This method creates a Bonus object at the specified position, of the given type, associated with the provided platform.
     *
     * @param x The x-coordinate for the bonus's position.
     * @param y The y-coordinate for the bonus's position.
     * @param type The type of bonus to create (e.g., Spring, Jetpack).
     * @param platform A shared pointer to the platform the bonus is associated with.
     * @return A shared pointer to the created Bonus object.
     */
    std::shared_ptr<Bonus> createBonus(float x, float y, BonusType type, std::shared_ptr<Platform> platform) override;

    /**
     * @brief Creates a BGtile instance and returns it.
     *
     * This method creates a BGtile (background tile) object at the specified position and returns a shared pointer to it.
     *
     * @param x The x-coordinate for the BGtile's position.
     * @param y The y-coordinate for the BGtile's position.
     * @return A shared pointer to the created BGtile object.
     */
    std::shared_ptr<BGtile> createBGtile(float x, float y) override;

    /**
     * @brief Creates a Score instance and returns it.
     *
     * This method creates a Score object at the specified position and returns a shared pointer to it.
     *
     * @param x The x-coordinate for the score's position.
     * @param y The y-coordinate for the score's position.
     * @return A shared pointer to the created Score object.
     */
    std::shared_ptr<Score> createScore(float x, float y) override;

private:
    std::shared_ptr<sf::RenderWindow> currentWindow; ///< Reference to the SFML render window used for creating views
};

#endif // INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H
