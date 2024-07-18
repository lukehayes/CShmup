#ifndef GM_LEVEL_H
#define GM_LEVEL_H

#include "raylib.h"
#include "game_manager.h"

void LevelStartMenu(GameManager* game)
{
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Start Menu", 10,10, 16, WHITE);
    EndDrawing();
}

void LevelPlay(GameManager* game)
{
    double rx = GetRandomValue(10,160);
    double ry = GetRandomValue(10,300);

    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Play State", 10,10, 16, WHITE);
        DrawRectangle(rx,ry, game->tileSize, game->tileSize, ORANGE);
    EndDrawing();

}

void LevelPaused(GameManager* game)
{
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Paused State", 10,10, 16, WHITE);
    EndDrawing();
}



#endif // GAME_LEVEL_H
