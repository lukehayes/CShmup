#ifndef GM_PLAYER_H
#define GM_PLAYER_H

#include "raylib.h"
#include "transform.h"
#include "game_manager.h"
#include <stdlib.h>

typedef struct Player
{
    Transform_t transform;
    Color color;
    float speed;

} Player;

Player* PlayerCreate(int x, int y, GameManager* game)
{
    Player* player = malloc(sizeof(Transform));

    player->transform.position.x = x;
    player->transform.position.y = y;
    player->transform.rotation   = 0;
    player->transform.scale.x    = game->tileSize * game->tileScale;
    player->transform.scale.y    = game->tileSize * game->tileScale;

    player->color                = GREEN;
    player->speed                = 100;

    return player;
}

void PlayerDestroy(Player* player)
{
    free(player);
}



#endif // !GM_PLAYER_H
