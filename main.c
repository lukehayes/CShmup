#include "raylib.h"
#include "constants.h"
#include "entity.h"
#include "game_manager.h"
#include <stdio.h>

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
                printf("Start Menu \n");

                BeginDrawing();
                    ClearBackground(BLACK);
                    DrawRectangle(100,100,100,100, RED);
                EndDrawing();

                break;
            
            case GAMESTATE_PLAYING:
                printf("Playing\n");
                BeginDrawing();
                    ClearBackground(BLACK);
                    DrawRectangle(100,300,100,100, GREEN);
                EndDrawing();
                break;

            case GAMESTATE_PAUSED:
                printf("Paused\n");
                BeginDrawing();
                    ClearBackground(BLACK);
                    DrawRectangle(300,100,100,100, BLUE);
                EndDrawing();
                break;
        }

    }

    GameManagerDestroy(game);

    CloseWindow();

    return 0;
}
