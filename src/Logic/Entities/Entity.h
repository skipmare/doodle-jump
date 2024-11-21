//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_ENTITY_H
#define INC_2024_PROJECT_SKIPMARE_ENTITY_H
#include <Subject.h>
#include <vector>

enum EntityType {
    PLAYER,
    PLATFORM,
    BONUS,
    BG_TILE,
    NONE
};

enum BonusType {
    JETPACK,
    SPRING
};

enum PlatformType {
    STATIC,
    VERTICAL,
    HORIZONTAL,
    DISAPPEARING
};


class Entity : public Subject {
public:
    Entity(float x, float y);
    virtual ~Entity(); // virtual destructor for derived class

    virtual void update(float deltaTime) = 0; // update the entity, pure virtual function

    [[nodiscard]] float getX() const; // get the x position of the entity
    [[nodiscard]] float getY() const; // get the y position of the entity
    void setPosition(float x, float y); // set the position of the entity

    void getBoundingBox(float& left, float& right, float& top, float& bottom); // used to check for collision

    [[nodiscard]] EntityType getEntityType() const; // get the type of the entity

    [[nodiscard]] float getWidth() const{return width;}; // get the width of the entity
    [[nodiscard]] float getHeight() const{return height;}; // get the height of the entity
    [[nodiscard]] bool getHasCollided() const{return hasCollided;}; // get the collision status of the entity
    void setHasCollided(bool collided); // set the collision status of the entity
protected:
    float x = 0, y = 0; // position of the entity, change it in derived class for different position
    float velocityX = 0, velocityY = 0; // set it to 0 for stationary entity, change it in derived class for moving entity
    float width = 0, height = 0; // width and height of the entity, change it in derived class for different size
    EntityType EntityType = NONE; // type of the entity, change it in derived class for different type
    bool hasCollided = false; // check if the entity has collided with player

};


#endif
