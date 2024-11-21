// Created by Skip on 21/11/2024.

#include "Subject.h"

// Attach an observer to this subject
void Subject::attach(Observer* observer) {
    // Check if the observer is already attached
    if (std::find(observers.begin(), observers.end(), observer) == observers.end()) {
        observers.push_back(observer);
    }
}

// Detach an observer from this subject
void Subject::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

// Notify all observers that are attached to this subject
void Subject::notify() {
    for (Observer* observer : observers) {
        observer->update(); // Call the update method on each observer
    }
}