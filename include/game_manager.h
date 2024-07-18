#ifndef GAME_GAMEMANAGER_H
#define GAME_GAMEMANAGER_H

#include "game_state.h"
#include <stdlib.h>

typedef struct GameManager
{
    GameState gameState;

    // System Specifc Settings
    size_t    tileSize;

    // Game Specifc Settings
    size_t    lives;
    size_t    highscore;
    size_t    level;

} GameManager;

GameManager* GameManagerCreate()
{
    GameManager* manager = malloc(sizeof(GameManager));

    manager->tileSize  = 8;

    manager->gameState = GAMESTATE_START_MENU;
    manager->lives     = 3;
    manager->level     = 1;
    manager->highscore = 0;


    return manager;
};


void GameManagerDestroy(GameManager* manager)
{
    free(manager);
}
#endif // !GAME_GAMEMANAGER_H
