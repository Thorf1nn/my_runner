/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-luca.orelli
** File description:
** destroy.c
*/

#include "runner.h"

void destroy_game(game_t *game)
{
    sfSprite_destroy(game->personnage);
    sfSprite_destroy(game->spike->spiker);
    sfSprite_destroy(game->background);
    sfSprite_destroy(game->para1);
    sfSprite_destroy(game->para2);
    sfSprite_destroy(game->para3);
    sfSprite_destroy(game->para4);
    sfSprite_destroy(game->floor);
    sfSprite_destroy(game->over->over);
    sfSprite_destroy(game->over->over2);
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->jumpsong);
    sfRenderWindow_destroy(game->window);
    free(game);
}
