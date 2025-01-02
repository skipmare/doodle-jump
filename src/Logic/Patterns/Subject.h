//
// Created by karan on 14/11/2024.
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory> // For std::shared_ptr
#include "Observer.h"

/**
 * @class Subject
 * @brief A class that manages and notifies a list of observers.
 * 
 * The Subject class follows the Observer design pattern, allowing observers to attach 
 * and detach themselves from the subject. When the subject's state changes, it will notify 
 * all attached observers by calling their update method.
 */
class Subject {
    std::vector<std::shared_ptr<Observer>> observers; ///< A vector to hold the observers

public:
    /**
     * @brief Attaches an observer to this subject.
     * 
     * @param observer A shared pointer to the observer to be attached.
     * This observer will be notified when the subject's state changes.
     */
    void attach(std::shared_ptr<Observer> observer);

    /**
     * @brief Detaches an observer from this subject.
     * 
     * @param observer A shared pointer to the observer to be detached.
     * The observer will no longer be notified of changes in the subject.
     */
    void detach(std::shared_ptr<Observer> observer);

    /**
     * @brief Notifies all attached observers of a change.
     * 
     * This method iterates through the list of attached observers and calls their 
     * update method to notify them of a change in the subject's state.
     */
    void notify();
};

#endif // SUBJECT_H
