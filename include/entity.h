#ifndef GM_ENTITY_H
#define GM_ENTITY_H

#include "raylib.h"
#include "constants.h"
#include <string.h>

typedef struct Entity
{
    Vector2 position;
    Vector2 size;
    Color color;
    int dx;
    int dy;
    int speed;
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

        .dx       = 1,
        .dy       = 1,
        .speed    = GetRandomValue(80,300),
        .type     = { *strncpy(e.type, type, strlen(type) + 1) }
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
    e->position.x += e->dx * e->speed * dt;
    e->position.y += e->dy * e->speed * dt;


    // Screen edge detection.
    if(e->position.x < 2 || e->position.x > WINDOW_WIDTH - 5)
    {
        e->dx = -e->dx;
    }

    if(e->position.y < 2 || e->position.y > WINDOW_HEIGHT - e->size.y)
    {
        e->dy = -e->dy;
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
