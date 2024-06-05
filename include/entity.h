#ifndef GM_ENTITY_H
#define GM_ENTITY_H

#include "raylib.h"
#include "constants.h"
#include "movement.h"
#include <string.h>

typedef struct Entity
{
    Vector2 position;
    Vector2 size;
    Color color;
    Movement movement;
    char type[30];

} Entity;

/**
 * Create an entity on the stack.
 *
 * @param float x             The x position.
 * @param float y             The y position.
 * @param const char* type    The name of the entities type.
 *
 * @return Entity
 */
Entity entity_create(float x, float y, const char* type)
{
    Entity e = { 
        .position = {x,y}, 
        .size     = {10,10}, 
        .color    = LIGHTGRAY,
        .type     = { *strncpy(e.type, type, strlen(type) + 1) },
        .movement = movement_create_basic()
    };

    return e;
}

/**
 * Update an entity.
 *
 * @param Entity* e    The entity to draw.
 * @param float dt     Delta time.
 *
 * @return void
 */
void entity_update(Entity* e, float dt)
{
    // General Movement
    e->position.x += e->movement.dx * e->movement.speed * dt;
    e->position.y += e->movement.dy * e->movement.speed * dt;


    // Screen edge detection.
    if(e->position.x < 2 || e->position.x > WINDOW_WIDTH - 5)
    {
        e->movement.dx = -e->movement.dx;
    }

    if(e->position.y < 2 || e->position.y > WINDOW_HEIGHT - e->size.y)
    {
        e->movement.dy = -e->movement.dy;
    }

}

/**
 * Draw an entity
 *
 * @param const Entity e    The entity to draw.
 *
 * @return void
 */
void entity_draw(const Entity e)
{
    DrawRectangle(e.position.x, e.position.y, e.size.x, e.size.y, e.color);
}

#endif // !GM_ENTITY_H
