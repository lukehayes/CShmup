#ifndef GM_TRANSFORM_H
#define GM_TRANSFORM_H

#include <raylib.h>

typedef struct Transform_t
{
    Vector2 position;
    Vector2 scale;
    float   rotation;
} Transform_t;

#endif // !GM_TRANSFORM_H
