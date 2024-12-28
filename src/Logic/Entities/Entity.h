//
// Created by karan on 14/11/2024.
//

#ifndef INC_2024_PROJECT_SKIPMARE_ENTITY_H
#define INC_2024_PROJECT_SKIPMARE_ENTITY_H

#include <Subject.h>

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

struct BoundingBox {
    float left;
    float right;
    float top;
    float bottom;
};

class Entity : public Subject {
public:
    Entity(float x, float y);
    virtual ~Entity(); // virtual destructor for derived class

    virtual void update(float deltaTime) = 0; // update the entity, pure virtual function

    [[nodiscard]] float getX() const; // get the x position of the entity
    [[nodiscard]] virtual float getY() const; // get the y position of the entity
    virtual void setPosition(float x, float y); // set the position of the entity

    [[nodiscard]] BoundingBox getBoundingBox() const; // get the bounding box of the entity
    [[nodiscard]] EntityType getEntityType() const; // get the type of the entity

    [[nodiscard]] float getWidth() const { return width; } // get the width of the entity
    [[nodiscard]] float getHeight() const { return height; } // get the height of the entity
    [[nodiscard]] bool getCollisionOnLand() const { return collisionOnLand; } // get the collision on land state
    [[nodiscard]] bool getCollidable() const { return collidable; } // get the collidable state
    [[nodiscard]] bool getJumpTrigger() const { return jumptrigger; } // get the jump trigger state
    void setJumpTrigger(bool input) { jumptrigger = input; } // set the jump trigger state

    void setOutOfView(bool outOfView); // set the out of view state
    [[nodiscard]] bool getOutOfView() const; // get the out of view state

    [[nodiscard]] bool getHasCollided() const { return hasCollided; } // get the has collided state
    void setHasCollided(bool hasCollided); // set the has collided state

protected:
    float x = 0, y = 0; // position of the entity, change it in derived class for different position
    float velocityX = 0, velocityY = 0; // set it to 0 for stationary entity, change it in derived class for moving entity
    float width = 0, height = 0; // width and height of the entity, change it in derived class for different size
    EntityType EntityType_var = NONE; // type of the entity, change it in derived class for different type
    bool collisionOnLand = false; // check if the entity has collided with player on landing
    bool collidable = true; // check if the entity is collidable
    bool jumptrigger = true;
    bool hasCollided = false; // check if the entity has collided with player
    bool outOfView = false; // check if the entity is out of view
};

#endif // INC_2024_PROJECT_SKIPMARE_ENTITY_H