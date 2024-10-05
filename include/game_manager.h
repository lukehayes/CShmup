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

GameManager* GameManagerCreate();


void GameManagerDestroy(GameManager* manager);

#endif // !GAME_AMEMANAGER_H
