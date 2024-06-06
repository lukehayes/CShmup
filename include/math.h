#ifndef GM_MATH_H
#define GM_MATH_H

#include "raylib.h"
#include <stdbool.h>

/**
* Is a rectangle completely inside of another rectangle?
*
* @param Rectangle a
* @param Rectangle b
*
* @return bool
*/
bool rect_inside(Rectangle a, Rectangle b)
{
    return b.x > a.x &&
           b.x + b.width < a.width + a.x &&
           b.y > a.y &&
           b.y + b.height < a.height + a.y;
}

/**
* Does a rectangle overlap of another rectangle?
*
* @param Rectangle a
* @param Rectangle b
*
* @return bool
*/
bool rect_overlap(Rectangle a, Rectangle b)
{
    return a.x < b.x + b.width &&
           b.x < a.x + a.width &&
           a.y < b.y + b.height &&
           b.y < a.y + a.height;
}

#endif // GM_MATH_H
