#ifndef INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H
#define INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H

#include "AbstractFactory.h" // Include the abstract factory header
#include "PlayerView.h"
#include "PlatformView.h"
#include "BonusView.h"
#include "BGtileView.h"
#include <memory>
#include <utility> // For std::pair

class ConcreteFactory : public AbstractFactory {
public:
    // Constructor
    ConcreteFactory(std::shared_ptr<sf::RenderWindow> window) : currentWindow(window) {}

    // Create a Player instance and return a pair with Player and PlayerView
    std::shared_ptr<Player> createPlayer(float x, float y) override;

    // Create a Platform instance and return a pair with Platform and PlatformView
    std::shared_ptr<Platform> createPlatform(float x, float y, PlatformType type) override;

    // Create a Bonus instance and return a pair with Bonus and BonusView
    std::shared_ptr<Bonus> createBonus(float x, float y, BonusType type) override;

    // Create a BGtile instance and return a pair with BGtile and BGtileView
    std::shared_ptr<BGtile> createBGtile(float x, float y) override;

private:
    std::shared_ptr<sf::RenderWindow> currentWindow; // Reference to the window
};

#endif // INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H