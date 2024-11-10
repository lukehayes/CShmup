#ifndef GM_PICKUP_H
#define GM_PICKUP_H

#include "transform.h"
#include "game_manager.h"


typedef enum PICKUP_TYPE
{
    PU_BASIC,
    PU_WEAPON,
    PU_COIN,

} PICKUP_TYPE;

typedef struct Pickup
{
    Transform_t transform;
    Color       color;
    PICKUP_TYPE type;

} Pickup;


Pickup PickupCreate(int x, int y, GameManager* game)
{
    Pickup pickup = {
        .transform = {
            .position = {x,y},
            .scale = {30, 30},
            .rotation = 0
        },
        .color = PURPLE,
        .type = PU_BASIC
    };

    return pickup;
}

void PickupDraw(Pickup* pickup, GameManager* game)
{
    DrawRectangle(
        pickup->transform.position.x,
        pickup->transform.position.y,
        pickup->transform.scale.x,
        pickup->transform.scale.y,
        pickup->color
    );
}



#endif // !GM_PICKUP_H
