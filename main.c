#include "raylib.h"
#include "constants.h"
#include "entity.h"
#include "collision.h"
#include "quadtree.h"
#include "math.h"

#define POLYMORPHIC(e, var_name, cls) ((e)* (var_name) = ((e)*) &cls;)

bool GAME_RUNNING = false;

int main() {

    /* == RAYLIB INIT ============================================================*/ 
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
    SetTargetFPS(60);
    SetExitKey(KEY_Q);
    SetExitKey(KEY_SPACE);
    SetTraceLogLevel(LOG_ALL);


    /*for(int i = 0; i <= ENT_COUNT - 1; i++)*/
    /*{*/
        /*int rx = GetRandomValue(10,WINDOW_WIDTH);*/
        /*int ry = GetRandomValue(10,WINDOW_HEIGHT);*/
        /*Entity e = entity_create(rx,ry, "Entity");*/
        /*ents[i] = e;*/
    /*}*/

    QuadTree* qt = quadtree_create((Rectangle){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});


    Entity ents[ENT_COUNT];

    for(int i = 0; i <= ENT_COUNT - 1; i++)
    {
        int rx = GetRandomValue(10,800);
        int ry = GetRandomValue(10,600);
        quadtree_insert(qt, (Rectangle){rx,ry,3,3});

        Entity e = entity_create(rx,ry, "Entity");
        ents[i] = e;
    }


    /* == LOOP ==================================================================*/
    while(!GAME_RUNNING)
    {
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) GAME_RUNNING = true;

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(10,10,100,100, PURPLE);


            if(IsKeyDown(KEY_E))
            {
                Entity* rand_ent   = &ents[GetRandomValue(0, ENT_COUNT - 1)];
                rand_ent->movement = movement_create_fastest();
            }

            quadtree_draw(qt);

            /*do_collisions(*(&ents));*/

            /*for(int i = 0; i <= ENT_COUNT - 1; i++)*/
            /*{*/
                /*entity_update(&ents[i], GetFrameTime());*/
            /*}*/

            for(int i = 0; i <= ENT_COUNT - 1; i++)
            {
                Entity e = ents[i];
                entity_draw(e);
            }

        EndDrawing();
    }

    quadtree_destroy(qt);

    CloseWindow();

    return 0;
}
