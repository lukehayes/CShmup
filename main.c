#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define WIDTH  1280
#define HEIGHT  720
#define TITLE  "WINDOW"
#define ENT_COUNT 10
bool GAME_RUNNING = false;


typedef struct Arena {
    size_t size;
    size_t capacity;
    size_t position;
    void* data;
} Arena;

Arena* arena_init(size_t capacity)
{
    Arena* arena    = malloc(sizeof(Arena));
    arena->size     = 0;
    arena->capacity = capacity;
    arena->position = 0;
    arena->data     = malloc(sizeof(size_t) * capacity);

    return arena;
}

void arena_destroy(Arena* arena)
{
    free(arena->data);
    free(arena);
}




int main() {

    /* == RAYLIB INIT ============================================================*/ 
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);
    SetTraceLogLevel(LOG_ALL);

    Arena* a = arena_init(100);

    printf("Arena Capacity: %lu \n", a->capacity);

    arena_destroy(a);


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
