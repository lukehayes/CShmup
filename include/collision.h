#ifndef GM_COLLISION_H
#define GM_COLLISION_H

#include "entity.h"
#include <stdio.h>

void do_collisions(Entity* entities)
{
    for(int i = 0; i <= ENT_COUNT - 1; i++)
    {
        Entity* current_entity = &entities[i];

        for(int j = 0; j <= ENT_COUNT - 1; j++)
        {
            Entity* other_entity = &entities[j];

            if(other_entity != current_entity)
            {
                if(CheckCollisionRecs(current_entity->rect, other_entity->rect))
                {
                    current_entity->movement.dx = -current_entity->movement.dx;
                    /*other_entity->movement.dy = -other_entity->movement.dy;*/

                    Color colors[]= {RED, GREEN, BLUE};

                    printf("Other Collision E %i P %p \n", i, other_entity);
                    printf(".... \n");
                    printf("Curr Collision E %i P %p \n", i, current_entity);
                    printf("-------------------------------- \n");

                    other_entity->color = colors[GetRandomValue(0,2)];
                }
            }
        }
    }
}

#endif // !GM_COLLISION_H
