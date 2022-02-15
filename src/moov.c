/*
** EPITECH PROJECT, 2021
** bs_csfml
** File description:
** analyse_event.c
*/

#include "runner.h"

void jump(game_t *game)
{
    if (game->pos.y <= 725 && game->is_grounded == false) {
        game->speed.y *= FRICTION;
        game->pos.y += GRAVITY;
        game->pos.x += game->speed.x;
        game->pos.y += game->speed.y;
    } else {
        game->is_grounded = true;
        game->pos.y = 725;
    }
}
