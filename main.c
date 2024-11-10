#include "raylib.h"
#include "constants.h"
#include "game_manager.h"
#include "levels.h"
#include "player.h"
#include "pickup.h"

bool GAME_RUNNING = false;


int main() {

    /* == RAYLIB INIT ========================================================*/
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);
    SetExitKey(KEY_SPACE);
    SetTraceLogLevel(LOG_ALL);

    /* == GAME INIT ==========================================================*/
    GameManager* game = GameManagerCreate();
    Player* player = PlayerCreate(100,300, game);
    game->player = player;

    Pickup p1 = PickupCreate(100.0,100.0, game);
    Pickup p2 = PickupCreate(300.0,400.0, game);

    printf("Pos %f %f\n", p1.transform.position.x, p1.transform.position.y);
    printf("Scale %f %f\n", p1.transform.scale.x, p1.transform.scale.y);

    /* == LOOP ===============================================================*/
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
                LevelPlay(game);

                PickupDraw(&p1, game);
                PickupDraw(&p2, game);

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
