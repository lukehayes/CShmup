#include "raylib.h"
#include "constants.h"
#include "game_manager.h"
#include "levels.h"
#include "player.h"

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
    Player* player = PlayerCreate(100,300, game);

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

        if(IsKeyPressed(KEY_Q))
        {
            game->gameState = GAMESTATE_START_MENU;
        }

        switch (game->gameState) {

            case GAMESTATE_START_MENU:

                LevelStartMenu(game);
                break;
            
            case GAMESTATE_PLAYING:

                PlayerUpdate(player, game);

                BeginDrawing();
                    ClearBackground(BLACK);
                    DrawRectangle(
                        player->transform.position.x,
                        player->transform.position.y,
                        player->transform.scale.x,
                        player->transform.scale.x,
                        PINK);
                EndDrawing();

                /*LevelPlay(game);*/
                break;

            case GAMESTATE_PAUSED:

                LevelPaused(game);
                break;
        }

    }

    GameManagerDestroy(game);
    PlayerDestroy(player);

    CloseWindow();

    return 0;
}
