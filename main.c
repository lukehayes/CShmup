#include "raylib.h"
#include "constants.h"
#include "entity.h"
#include "collision.h"
#include "quadtree.h"
#include "math.h"

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

    for(int i = 0; i <= ENT_COUNT - 1; i++)
    {
        int rx = GetRandomValue(10,WINDOW_WIDTH);
        int ry = GetRandomValue(10,WINDOW_HEIGHT);
        Entity e = entity_create(rx,ry, "Entity");
        ents[i] = e;
    }

    QuadTree* qt = quadtree_create((Rectangle){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});

    quadtree_destroy(qt);

    Rectangle a = {200,200,100,100};
    Rectangle b = {400,400,30,30};


    /* == LOOP ==================================================================*/
    while(!GAME_RUNNING)
    {
        if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose()) GAME_RUNNING = true;

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(10,10,100,100, PURPLE);

            float mx = GetMouseX();
            float my = GetMouseY();

            b.x = mx;
            b.y = my;

            if(IsKeyDown(KEY_E))
            {
                Entity* rand_ent = &ents[GetRandomValue(0, ENT_COUNT - 1)];
                rand_ent->movement = movement_create_fastest();
            }

            if(rect_inside(a,b))
            {
                printf("INSIDE \n");

                Rectangle* aa = &a; 

                aa->x = GetRandomValue(10,400);
                aa->y = GetRandomValue(10,400);
            }

            if(rect_overlap(a,b))
            {
                printf("OVERLAP \n");
            }

            DrawRectangle(a.x, a.y, a.width, a.height, DARKGRAY);
            DrawRectangle(b.x, b.y, b.width, b.height, GREEN);

            /*do_collisions(*(&ents));*/

            /*for(int i = 0; i <= ENT_COUNT - 1; i++)*/
            /*{*/
                /*entity_update(&ents[i], GetFrameTime());*/
            /*}*/

            /*for(int i = 0; i <= ENT_COUNT - 1; i++)*/
            /*{*/
                /*Entity e = ents[i];*/
                /*entity_draw(e);*/
            /*}*/

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
