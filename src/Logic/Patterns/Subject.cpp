//
// Created by Skip on 21/11/2024.
//

#include "Subject.h"
#include <vector>
#include <algorithm>

// Attach an observer to this subject
void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

// Detach an observer from this subject
void Subject::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

// Notify all observers that are attached to this subject
void Subject::notify() {
    for (Observer* observer : observers) {
        observer->update(); // Notify each observer
    }
}