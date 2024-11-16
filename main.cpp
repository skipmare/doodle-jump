#include <SFML/Graphics.hpp>
#include <vector>
#include "src/Logic/Entities/Platforms/HorizontalPlatform.h"
#include "src/Logic/Entities/Platforms/VerticalPlatform.h"
#include <iostream>
void drawPlatform(sf::RenderWindow& window, Platform& platform) {
    float left, right, top, bottom;
    platform.getBoundingBox(left, right, top, bottom);

    sf::RectangleShape rectangle(sf::Vector2f(right - left, bottom - top));
    rectangle.setPosition(left, top);

    switch (platform.getPlatformType()) {
        case PlatformType::STATIC:
            rectangle.setFillColor(sf::Color::Green);
        break;
        case PlatformType::VERTICAL:
            rectangle.setFillColor(sf::Color::Blue);
        break;
        case PlatformType::HORIZONTAL:
            rectangle.setFillColor(sf::Color::Red);
        break;
        case PlatformType::DISAPPEARING:
            rectangle.setFillColor(sf::Color::Yellow);
        break;
    }

    window.draw(rectangle);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 800), "Platform Test");

    std::vector<Platform*> platforms;
    platforms.push_back(new HorizontalPlatform(100.0f, 200.0f));
    platforms.push_back(new VerticalPlatform(300.0f, 400.0f));

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        for (Platform* platform : platforms) {
            platform->update(deltaTime);
        }

        window.clear();
        for (Platform* platform : platforms) {
            drawPlatform(window, *platform);
        }
        window.display();
    }

    for (Platform* platform : platforms) {
        delete platform;
    }

    return 0;
}