#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <memory> // For std::unique_ptr
#include "Observer.h"

class Subject {
    std::vector<std::shared_ptr<Observer>> observers; // Vector of unique_ptr to observers
public:
    // Attach an observer to this subject
    void attach(std::shared_ptr<Observer> observer);

    // Detach an observer from this subject
    void detach(std::shared_ptr<Observer> observer); // Use raw pointer for detaching

    // Notify all observers that are attached to this subject
    void notify();
};

#endif // SUBJECT_H