#ifndef GM_GAME_MATH_H
#define GM_GAME_MATH_H

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
    return a.x > b.x &&
           a.x + a.width < b.width + b.x &&
           a.y > b.y &&
           a.y + a.height < b.height + b.y;
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

#endif // GM_GAME_MATH_H
