#include "raylib.h"
#include "constants.h"
#include "game_manager.h"
#include "levels.h"

bool GAME_RUNNING = false;


int main() {

    /* == RAYLIB INIT ============================================================*/ 
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);
    SetExitKey(KEY_SPACE);
    SetTraceLogLevel(LOG_ALL);

    GameManager* game = GameManagerCreate();

    /* == LOOP ==================================================================*/
    while(!GAME_RUNNING)
    {
        game->deltaTime = GetFrameTime();


        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) GAME_RUNNING = true;

        if(IsKeyPressed(KEY_X))
        {
            game->gameState = GAMESTATE_PLAYING;
        }

        if(IsKeyPressed(KEY_P))
        {
            game->gameState = GAMESTATE_PAUSED;
        }

        switch (game->gameState) {

            case GAMESTATE_START_MENU:

                LevelStartMenu(game);
                break;
            
            case GAMESTATE_PLAYING:

                LevelPlay(game);
                break;

            case GAMESTATE_PAUSED:

                LevelPaused(game);
                break;
        }

    }

    GameManagerDestroy(game);

    CloseWindow();

    return 0;
}
