#include "raylib.h"
#include "constants.h"
#include "entity.h"
#include "collision.h"

bool GAME_RUNNING = false;


#define POLYMORPHIC(e, var_name, cls) ((e)* (var_name) = ((e)*) &cls;)

typedef struct Foo
{
    Rectangle rect;
    Color color;
    int dx;
    int dy;
    int speed;
    char type[30];

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

    Foo foo = { 
        .rect = {.x = 300, .y = 200, .width = 30, .height = 10},
        .color    = PURPLE,
        .dx       = 1,
        .dy       = 1,
        .speed    = GetRandomValue(80,300),
        /*.type     = *strncpy(f.type, "foo", strlen("foo") + 1)*/
    };

    /*Foo* f = &foo;*/
    Entity* f = (Entity*) &foo;

    for(int i = 0; i <= ENT_COUNT - 1; i++)
    {
        int rx = GetRandomValue(10,WINDOW_WIDTH);
        int ry = GetRandomValue(10,WINDOW_HEIGHT);
        Entity e = entity_create(rx,ry, "Entity");
        ents[i] = e;
    }

    Entity e1 = entity_create(100,100, "Entity");
    Entity e2 = entity_create(400,100, "Entity");

    /* == LOOP ==================================================================*/
    while(!GAME_RUNNING)
    {
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) GAME_RUNNING = true;

        BeginDrawing();

            ClearBackground(DARKGRAY);

            DrawRectangle(10,10,100,100, BLACK);

            
            if(IsKeyDown(KEY_E))
            {
                Entity* rand_ent = &ents[GetRandomValue(0, ENT_COUNT - 1)];
                rand_ent->movement = movement_create_fastest();
            }


            do_collisions(*(&ents));



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
            entity_draw(*f);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
