#include "raylib.h"
#include "constants.h"
#include "entity.h"
#include "arena.h"

#include <stdio.h>
#include <stdlib.h>

bool GAME_RUNNING = false;

typedef struct Foo 
{
    const char* name;
    size_t value;
} Foo;


int main() {

    /* == RAYLIB INIT ============================================================*/ 
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);
    SetExitKey(KEY_SPACE);
    SetTraceLogLevel(LOG_ALL);

    Arena* arena = arena_init(2);
    arena_release(arena);


    /* == LOOP ==================================================================*/
    while(!GAME_RUNNING)
    {
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) GAME_RUNNING = true;

        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
