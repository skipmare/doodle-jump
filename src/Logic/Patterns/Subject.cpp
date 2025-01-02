//
// Created by karan on 14/11/2024.
//

#include "Subject.h"
#include <memory>
#include <algorithm>

/**
 * @brief Attaches an observer to this subject.
 *
 * Adds a shared pointer to an observer to the list of observers. This observer
 * will be notified when the subject's state changes.
 *
 * @param observer A shared pointer to the observer to be attached.
 */
void Subject::attach(std::shared_ptr<Observer> observer) {
    // Add the observer to the vector of observers
    observers.push_back(observer);
}

/**
 * @brief Detaches an observer from this subject.
 *
 * Removes the given observer from the list of observers. The observer will no longer
 * be notified of changes in the subject's state.
 *
 * @param observer A shared pointer to the observer to be detached.
 */
void Subject::detach(std::shared_ptr<Observer> observer) {
    // Remove the observer from the vector of observers
    observers.erase(std::remove_if(observers.begin(), observers.end(),
        [observer](const std::shared_ptr<Observer>& obs) { return obs.get() == observer.get(); }), observers.end());
}

/**
 * @brief Notifies all attached observers of a change.
 *
 * Iterates through the list of attached observers and calls their update method to
 * notify them of a change in the subject's state.
 */
void Subject::notify() {
    for (const auto& observer : observers) {
        observer->update(); // Call the update method on each observer
    }
}
