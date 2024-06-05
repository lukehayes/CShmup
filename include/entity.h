#ifndef GM_ENTITY_H
#define GM_ENTITY_H

#include "raylib.h"
#include "constants.h"
#include "movement.h"
#include <string.h>

typedef struct Entity
{
    Rectangle rect;
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
        .rect = {.x = x, .y = y, .width = 10, .height = 10},
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
    e->rect.x += e->movement.dx * e->movement.speed * dt;
    e->rect.y += e->movement.dy * e->movement.speed * dt;


    // Screen edge detection.
    if(e->rect.x < 2 || e->rect.x > WINDOW_WIDTH - 5)
    {
        e->movement.dx = -e->movement.dx;
    }

    if(e->rect.y < 2 || e->rect.y > WINDOW_HEIGHT - e->rect.width)
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
    DrawRectangle(e.rect.x, e.rect.y, e.rect.width, e.rect.height, e.color);
}

#endif // !GM_ENTITY_H
