#include "raylib.h"

#define WIDTH  1280
#define HEIGHT  720
#define TITLE  "WINDOW"
#define ENT_COUNT 10

bool GAME_RUNNING = false;

int main() {

    /* == RAYLIB INIT ============================================================*/ 
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);
    SetTraceLogLevel(LOG_ALL);


    /* == LOOP ==================================================================*/
    while(!GAME_RUNNING)
    {
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) GAME_RUNNING = true;

        BeginDrawing();

            ClearBackground(GRAY);

            DrawRectangle(10,10,100,100, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
