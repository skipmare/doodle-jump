//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_ENTITY_H
#define INC_2024_PROJECT_SKIPMARE_ENTITY_H


class Entity {
public:
    Entity(int x, int y);
    virtual ~Entity(); // virtual destructor for derived class

    virtual void update(float deltaTime) = 0; // update the entity, pure virtual function

    float getX() const; // get the x position of the entity
    float getY() const; // get the y position of the entity
    void setPosition(float x, float y); // set the position of the entity

protected:
    float x = 0, y = 0; // position of the entity, change it in derived class for different position
    float velocityX = 0, velocityY = 0; // set it to 0 for stationary entity, change it in derived class for moving entity
    int width = 0, height = 0; // width and height of the entity, change it in derived class for different size
};


#endif
