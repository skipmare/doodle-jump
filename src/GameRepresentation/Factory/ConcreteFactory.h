// ConcreteFactory.h
#ifndef INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H
#define INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H

#include "AbstractFactory.h" // Include the abstract factory header
#include "PlayerView.h"
#include "PlatformView.h"
#include "BonusView.h"

class ConcreteFactory : public AbstractFactory {
public:
    // Constructor
    ConcreteFactory(sf::RenderWindow& window) : currentwindow(window) {};
    // Create a Player instance
    std::unique_ptr<Player> createPlayer(float x, float y) override;

    // Create a Platform instance
    std::unique_ptr<Platform> createPlatform(float x, float y, PlatformType type) override;

    // Create a Bonus instance
    std::unique_ptr<Bonus> createBonus(float x, float y, BonusType type) override;
private:
    sf::RenderWindow& currentwindow; // Reference to the window


};

#endif // INC_2024_PROJECT_SKIPMARE_CONCRETEFACTORY_H