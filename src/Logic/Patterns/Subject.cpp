//
// Created by karan on 14/11/2024.
//

#include "Subject.h"
#include <memory>
#include <algorithm>

// Attach an observer to this subject
void Subject::attach(std::shared_ptr<Observer> observer) {
    // Add the unique_ptr to the vector
    observers.push_back(observer);
}

// Detach an observer from this subject
void Subject::detach(std::shared_ptr<Observer> observer) {
    // Remove the observer from the vector
    observers.erase(std::remove_if(observers.begin(), observers.end(),
        [observer](const std::shared_ptr<Observer>& obs) { return obs.get() == observer.get(); }), observers.end());
}

// Notify all observers that are attached to this subject
void Subject::notify() {
    for (const auto& observer : observers) {
        observer->update(); // Call the update method on each observer
    }
}