#ifndef GAME_GAMEMANAGER_H
#define GAME_GAMEMANAGER_H

#include "game_state.h"
#include <stdlib.h>

typedef struct GameManager
{
    GameState gameState;

    // System Specifc Settings
    size_t    width;
    size_t    height;
    size_t    tileSize;
    size_t    tileScale;
    float     deltaTime;

    // Game Specifc Settings
    size_t    lives;
    size_t    highscore;
    size_t    level;

} GameManager;

GameManager* GameManagerCreate()
{
    GameManager* manager = malloc(sizeof(GameManager));

    manager->width      = 180;
    manager->height     = 320;
    manager->tileSize   = 8;
    manager->tileScale  = 2;
    manager->deltaTime  = 0.0;

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
#endif // !GAME_AMEMANAGER_H
