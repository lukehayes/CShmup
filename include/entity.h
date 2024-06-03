#ifndef GM_ENTITY_H
#define GM_ENTITY_H

#include "raylib.h"
#include <string.h>
#include <stdio.h>

typedef struct Entity
{
    Vector2 position;
    Vector2 size;
    Color color;
    char type[100];

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
    Entity e = { .position = {x,y}, .size = {40,40}, .color = GREEN };
    strcpy(e.type, type);

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
    e->position.x += 1 * 100 * dt;
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
