#include <SFML/Graphics.hpp>
#include <vector>
#include "src/Logic/Entities/Platforms/HorizontalPlatform.h"
#include "src/Logic/Entities/Platforms/VerticalPlatform.h"
#include "src/logic/Utilities/Random.h"
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

bool checkCollision(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
    return !(x1 + w1 < x2 || x1 > x2 + w2 || y1 + h1 < y2 || y1 > y2 + h2);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 800), "Platform Test");

    std::vector<Platform*> platforms;
    Random random;

    const int maxPlatforms = 16;
    const float platformWidth = 100.0f;
    const float platformHeight = 20.0f;

    for (int i = 0; i < maxPlatforms; ++i) {
        float x, y;
        bool collision;
        do {
            collision = false;
            x = random.getRandomX();
            y = random.getRandomY();

            for (Platform* platform : platforms) {
                float left, right, top, bottom;
                platform->getBoundingBox(left, right, top, bottom);
                if (checkCollision(x, y, platformWidth, platformHeight, left, top, right - left, bottom - top)) {
                    collision = true;
                    break;
                }
            }
        } while (collision);

        if (random.getRandomType() == 0) {
            platforms.push_back(new HorizontalPlatform(x, y));
        } else {
            platforms.push_back(new VerticalPlatform(x, y));
        }
    }

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