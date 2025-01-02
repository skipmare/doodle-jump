/// @file Entity.h
/// @brief Declares the base Entity class and related enumerations for the game.

#ifndef INC_2024_PROJECT_SKIPMARE_ENTITY_H
#define INC_2024_PROJECT_SKIPMARE_ENTITY_H

#include <Subject.h>

/// @brief Enumeration for the types of entities in the game.
enum EntityType {
    PLAYER,      ///< Represents the player entity.
    PLATFORM,    ///< Represents a platform entity.
    BONUS,       ///< Represents a bonus entity.
    BG_TILE,     ///< Represents a background tile entity.
    NONE         ///< Represents an undefined entity type.
};

/// @brief Enumeration for the types of bonuses in the game.
enum BonusType {
    JETPACK, ///< Represents a jetpack bonus.
    SPRING   ///< Represents a spring bonus.
};

/// @brief Enumeration for the types of platforms in the game.
enum PlatformType {
    STATIC,       ///< Represents a static platform.
    VERTICAL,     ///< Represents a vertically moving platform.
    HORIZONTAL,   ///< Represents a horizontally moving platform.
    DISAPPEARING  ///< Represents a disappearing platform.
};

/// @brief Represents the bounding box of an entity.
struct BoundingBox {
    float left;   ///< Left edge of the bounding box.
    float right;  ///< Right edge of the bounding box.
    float top;    ///< Top edge of the bounding box.
    float bottom; ///< Bottom edge of the bounding box.
};

/// @brief Base class for all entities in the game.
///
/// This class defines common properties and methods that all game entities share.
class Entity : public Subject {
public:
    /// @brief Constructs an Entity object with the specified initial position.
    /// @param x The initial x-coordinate of the entity.
    /// @param y The initial y-coordinate of the entity.
    Entity(float x, float y);

    /// @brief Virtual destructor to allow proper cleanup of derived classes.
    virtual ~Entity();

    /// @brief Updates the entity's state.
    /// @param deltaTime Time elapsed since the last update, in seconds.
    virtual void update(float deltaTime) = 0;

    /// @brief Gets the x-coordinate of the entity.
    /// @return The x-coordinate.
    [[nodiscard]] float getX() const;

    /// @brief Gets the y-coordinate of the entity.
    /// @return The y-coordinate.
    [[nodiscard]] virtual float getY() const;

    /// @brief Sets the position of the entity.
    /// @param x The new x-coordinate.
    /// @param y The new y-coordinate.
    virtual void setPosition(float x, float y);

    /// @brief Gets the bounding box of the entity.
    /// @return The bounding box.
    [[nodiscard]] BoundingBox getBoundingBox() const;

    /// @brief Gets the type of the entity.
    /// @return The entity type.
    [[nodiscard]] EntityType getEntityType() const;

    /// @brief Gets the width of the entity.
    /// @return The width.
    [[nodiscard]] float getWidth() const { return width; }

    /// @brief Gets the height of the entity.
    /// @return The height.
    [[nodiscard]] float getHeight() const { return height; }

    /// @brief Checks if the entity has collided with the player on landing.
    /// @return True if a collision occurred on landing, false otherwise.
    [[nodiscard]] bool getCollisionOnLand() const { return collisionOnLand; }

    /// @brief Checks if the entity is collidable.
    /// @return True if the entity is collidable, false otherwise.
    [[nodiscard]] bool getCollidable() const { return collidable; }

    /// @brief Checks if the jump trigger is active.
    /// @return True if the jump trigger is active, false otherwise.
    [[nodiscard]] bool getJumpTrigger() const { return jumptrigger; }

    /// @brief Sets the jump trigger state.
    /// @param input True to activate the jump trigger, false otherwise.
    void setJumpTrigger(bool input) { jumptrigger = input; }

    /// @brief Sets whether the entity is out of view.
    /// @param outOfView True if the entity is out of view, false otherwise.
    void setOutOfView(bool outOfView);

    /// @brief Checks if the entity is out of view.
    /// @return True if the entity is out of view, false otherwise.
    [[nodiscard]] bool getOutOfView() const;

    /// @brief Checks if the entity has collided with the player.
    /// @return True if a collision occurred, false otherwise.
    [[nodiscard]] bool getHasCollided() const { return hasCollided; }

    /// @brief Sets the collision state of the entity.
    /// @param hasCollided True if a collision occurred, false otherwise.
    void setHasCollided(bool hasCollided);

protected:
    float x = 0; ///< The x-coordinate of the entity.
    float y = 0; ///< The y-coordinate of the entity.
    float velocityX = 0; ///< The horizontal velocity of the entity.
    float velocityY = 0; ///< The vertical velocity of the entity.
    float width = 0; ///< The width of the entity.
    float height = 0; ///< The height of the entity.
    EntityType EntityType_var = NONE; ///< The type of the entity.
    bool collisionOnLand = false; ///< Indicates if the entity has collided with the player on landing.
    bool collidable = true; ///< Indicates if the entity is collidable.
    bool jumptrigger = true; ///< Indicates if the jump trigger is active.
    bool hasCollided = false; ///< Indicates if the entity has collided with the player.
    bool outOfView = false; ///< Indicates if the entity is out of view.
};

#endif // INC_2024_PROJECT_SKIPMARE_ENTITY_H
