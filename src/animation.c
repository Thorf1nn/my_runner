/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-luca.orelli
** File description:
** animation.c
*/

#include "runner.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void perso_time(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->second = game->time.microseconds / 100000.0;
    if (game->second > 1) {
        move_rect(&game->rect, 32, 192);
        sfClock_restart(game->clock);
        sfSprite_setTextureRect(game->personnage, game->rect);
    }
}

void perso_time_jump(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->second = game->time.microseconds / 100000.0;
    if (game->second > 1) {
        move_rect(&game->rect, 32, 256);
        sfClock_restart(game->clock);
        sfSprite_setTextureRect(game->personnage, game->rect);
    }
}

void sprites_move(game_t *game)
{
    spike_sprites_moov(game);
    sfSprite_move(game->background, (sfVector2f){-1, 0});
    sfSprite_move(game->para1, (sfVector2f){-2, 0});
    sfSprite_move(game->para2, (sfVector2f){-2.5, 0});
    sfSprite_move(game->para3, (sfVector2f){-3, 0});
    sfSprite_move(game->para4, (sfVector2f){-3.5 , 0});
    sfSprite_move(game->floor, (sfVector2f){-4, 0});
    if (sfSprite_getPosition(game->background).x <= -1920)
        sfSprite_setPosition(game->background, (sfVector2f){0, 0});
    if (sfSprite_getPosition(game->para1).x <= -1920)
        sfSprite_setPosition(game->para1, (sfVector2f){0, 0});
    if (sfSprite_getPosition(game->para2).x <= -1920)
        sfSprite_setPosition(game->para2, (sfVector2f){0, 0});
    if (sfSprite_getPosition(game->para3).x <= -1920)
        sfSprite_setPosition(game->para3, (sfVector2f){0, 0});
    if (sfSprite_getPosition(game->para4).x <= -1920)
        sfSprite_setPosition(game->para4, (sfVector2f){0, 0});
    if (sfSprite_getPosition(game->floor).x <= -1920)
        sfSprite_setPosition(game->floor, (sfVector2f){0, 0});
}

void spike_sprites_moov(game_t *game)
{
    sfSprite_move(game->spike->spiker, (sfVector2f){-20, 0});
    if (sfSprite_getPosition(game->spike->spiker).x <= -1920) {
        sfSprite_setPosition(game->spike->spiker, (sfVector2f)
        {1920, game->spike->spike_pos.y});
    }
}
