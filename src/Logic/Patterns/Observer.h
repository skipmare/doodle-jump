//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_OBSERVER_H
#define INC_2024_PROJECT_SKIPMARE_OBSERVER_H
#include <SFML/Graphics.hpp>

class Observer {
public:
    virtual void update() = 0; // Method to be called when the subject changes
    virtual void render() = 0; // Method to render the observer
    virtual ~Observer() = default;
};

#endif //INC_2024_PROJECT_SKIPMARE_OBSERVER_H
