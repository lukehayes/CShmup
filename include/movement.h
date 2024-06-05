#ifndef GM_MOVEMENT_H
#define GM_MOVEMENT_H

#include "raylib.h"

typedef struct
{
    int dx;
    int dy;
    int speed;
} Movement;


Movement movement_create_basic()
{
    Movement m = {
        .dx    = 1,
        .dy    = 1,
        .speed = 100
    };

    return m;
}

Movement movement_create_fast()
{
    Movement m = {
        .dx    = -1,
        .dy    = -1,
        .speed = 300
    };

    return m;
}

Movement movement_create_fastest()
{
    Movement m = {
        .dx    = GetRandomValue(-1,1),
        .dy    = GetRandomValue(-1,1),
        .speed = 600
    };

    return m;
}


#endif // !GM_MOVEMENT_H
