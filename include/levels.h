#ifndef GM_LEVEL_H
#define GM_LEVEL_H

#include "raylib.h"
#include "game_manager.h"
#include "player.h"
#include "renderer.h"
#include <stdio.h>
#include <math.h>

void LevelStartMenu(GameManager* game)
{
    static float c = 0.0;
    c += 0.1;

    BeginDrawing();
        ClearBackground(BLACK);

        DrawTextEx(game->font, "!*?;@~# ABCDE abcde 12345", (Vector2){800.0  / 2, 600.0 / 2}, game->font_size * game->font_mult, 0, (Color){255,255,255, sin(c) * 100} );
        //DrawTextEx(game->font, "Press Space To Start.", (Vector2){1100.0  / 2, 700.0 / 2}, game->font_size * game->font_mult, 0, (Color){255,255,255, sin(c) * 100} );
        // DrawText("Press X to start...", 10, 50, 16, WHITE);
    EndDrawing();
}

void LevelPlay(GameManager* game)
{
    PlayerUpdate(game->player, game);

    BeginDrawing();
        ClearBackground(BLACK);

        DrawText("PlayState", 10, 10, 22, WHITE);

        DrawRectangle(
            game->player->transform.position.x,
            game->player->transform.position.y,
            game->player->transform.scale.x,
            game->player->transform.scale.y,
            WHITE);
    EndDrawing();

}

void LevelPaused(GameManager* game)
{
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Paused State", 10, 10, 22, WHITE);
    EndDrawing();
}



#endif // GAME_LEVEL_H
