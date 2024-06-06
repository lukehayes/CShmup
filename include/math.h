#ifndef GM_MATH_H
#define GM_MATH_H

#include "raylib.h"
#include <stdbool.h>

bool rect_inside(Rectangle a, Rectangle b)
{
    return a.x > b.x &&
           a.x + a.width < b.width + b.x &&
           a.y > b.y &&
           a.y + a.height < b.height + b.y;
}

bool rect_overlap(Rectangle a, Rectangle b)
{
    return a.x < b.x + b.width &&
           b.x < a.x + a.width &&
           a.y < b.y + b.height &&
           b.y < a.y + a.height;
}

#endif // GM_MATH_H
