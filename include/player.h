#ifndef GM_PLAYER_H
#define GM_PLAYER_H

#include "raylib.h"
#include "transform.h"
#include <stdlib.h>

typedef struct Player
{
    Transform_t transform;
    Color color;
    float speed;

} Player;

Player* PlayerCreate(int x, int y, GameManager* game)
{
    Player* player = malloc(sizeof(Player));

    player->transform.position.x = x;
    player->transform.position.y = y;
    player->transform.rotation   = 0;
    player->transform.scale.x    = game->tileSize * game->tileScale * 2;
    player->transform.scale.y    = game->tileSize * game->tileScale * 2;

    player->color                = GREEN;
    player->speed                = 300;

    return player;
}


void PlayerUpdate(Player* player, GameManager* game)
{
    if(IsKeyDown(KEY_W))
    {
        player->transform.position.y -= 1 * player->speed * game->deltaTime;
    }
    
    if(IsKeyDown(KEY_S))
    {
        player->transform.position.y += 1 * player->speed * game->deltaTime;
    }

    if(IsKeyDown(KEY_A))
    {
        player->transform.position.x -= 1 * player->speed * game->deltaTime;
    }

    if(IsKeyDown(KEY_D))
    {
        player->transform.position.x += 1 * player->speed * game->deltaTime;
    }

}



void PlayerDestroy(Player* player)
{
    free(player);
}



#endif // !GM_PLAYER_H
