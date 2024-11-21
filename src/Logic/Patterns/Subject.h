//
// Created by Skip on 21/11/2024.
//

#ifndef SUBJECT_H
#define SUBJECT_H



#include <vector>
#include <algorithm>
#include "Observer.h"

class Subject {

    // Vector of observers that are attached to this subject
    std::vector<Observer*> observers;

public:

    // Attach an observer to this subject
    void attach(Observer* observer);

    // Detach an observer from this subject
    void detach(Observer* observer);

    // Notify all observers that are attached to this subject
    void notify();
};



#endif //SUBJECT_H
