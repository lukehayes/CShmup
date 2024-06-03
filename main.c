#include "raylib.h"
#include "constants.h"
#include "entity.h"

bool GAME_RUNNING = false;

int main() {

    /* == RAYLIB INIT ============================================================*/ 
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);
    SetExitKey(KEY_SPACE);
    SetTraceLogLevel(LOG_ALL);

    Entity ents[ENT_COUNT];

    for(int i = 0; i <= ENT_COUNT - 1; i++)
    {
        int rx = GetRandomValue(10,WINDOW_WIDTH);
        int ry = GetRandomValue(10,WINDOW_HEIGHT);
        Entity e = entity_create(rx,ry, "Entity");
        ents[i] = e;
    }

    Entity e1 = entity_create(100,100, "Entity");
    Entity e2 = entity_create(400,100, "Entityxxx");

    /* == LOOP ==================================================================*/
    while(!GAME_RUNNING)
    {
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) GAME_RUNNING = true;

        BeginDrawing();

            ClearBackground(GRAY);

            DrawRectangle(10,10,100,100, BLACK);

            for(int i = 0; i <= ENT_COUNT - 1; i++)
            {
                entity_update(&ents[i], GetFrameTime());
            }

            for(int i = 0; i <= ENT_COUNT - 1; i++)
            {
                Entity e = ents[i];
                entity_draw(e);
            }

            entity_draw(e1);
            entity_draw(e2);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
