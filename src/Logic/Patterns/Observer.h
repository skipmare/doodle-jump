//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_OBSERVER_H
#define INC_2024_PROJECT_SKIPMARE_OBSERVER_H

/**
 * @class Observer
 * @brief An abstract base class for the Observer design pattern.
 *
 * The Observer class is used to define a contract for objects that wish to be notified
 * of changes in a Subject. This class defines an update method that will be called when
 * the subject undergoes a change.
 */
class Observer {
public:
    /**
     * @brief Called to notify the observer of a change in the subject.
     *
     * This method is called when the subject's state changes and the observer needs
     * to react accordingly.
     */
    virtual void update() = 0;

    /**
     * @brief Virtual destructor for Observer class.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Observer() = default;
};

#endif //INC_2024_PROJECT_SKIPMARE_OBSERVER_H
