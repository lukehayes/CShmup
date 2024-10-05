#include "game_manager.h"
#include "game_state.h"
#include <stdlib.h>

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
