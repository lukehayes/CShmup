#include "raylib.h"
#include "constants.h"
#include "entity.h"
#include "arena.h"

#include <stdio.h>

#define POLYMORPHIC(e, var_name, cls) ((e)* (var_name) = ((e)*) &cls;)

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

    Entity ents[ENT_COUNT];

    Arena* arena = arena_init(100);

    int n = 111;
    int m = 333;
    Foo f1 = {.name = "F1", .value = 555};
    Foo f2 = {.name = "F2", .value = 777};

    size_t n_pos = arena_insert(arena, &n, sizeof(n));
    size_t m_pos = arena_insert(arena, &m, sizeof(m));
    arena_insert(arena, &f1, sizeof(f1));
    arena_insert(arena, &f2, sizeof(f2));

    printf("Position: %lu, Value: %lu \n\n", n_pos, *(size_t*)arena->data + n_pos);
    printf("Position: %lu, Value: %lu \n\n", m_pos, *(size_t*)arena->data + m_pos);
    printf("TEST: %lu \n", *(int*)arena->data);

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
