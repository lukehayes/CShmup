#ifndef GM_RENDERER_H
#define GM_RENDERER_H

#include "game_manager.h"

/**
* Rendering helper functions
*/

void GmDrawText(const GameManager* game, const char* text, Vector2 pos)
{
    DrawTextEx(game->font,
               text,
               pos,
               game->font_size * game->font_mult,
               0,
               WHITE);
}


#endif // !GM_RENDERER_H
