/*
** EPITECH PROJECT, 2021
** bs_csfml
** File description:
** game.c
*/

#include "runner.h"

void init_world(game_t *game, score_t *score, nombre_t *nombre)
{
    game->counter = malloc(sizeof(counter_t));
    sfRenderWindow_clear(game->window, sfBlack);
    draw_world(game, score, nombre);
    sfRenderWindow_display(game->window);
    sfRenderWindow_setFramerateLimit(game->window, 60);
}

void init(game_t *game)
{
    game->mode.width = 1920, game->mode.height = 1080,
    game->mode.bitsPerPixel = 32;
    game->window = sfRenderWindow_create(game->mode, "Candy Runner",
    sfResize | sfClose, NULL);
    init_sprite(game);
    game->clock = sfClock_create();
}

void draw_world(game_t *game, score_t *score, nombre_t *nombre)
{
    sfRenderWindow_drawSprite(game->window, game->background, NULL);
    sfRenderWindow_drawSprite(game->window, game->para1, NULL);
    sfRenderWindow_drawSprite(game->window, game->para2, NULL);
    sfRenderWindow_drawSprite(game->window, game->para3, NULL);
    sfRenderWindow_drawSprite(game->window, game->para4, NULL);
    sfRenderWindow_drawSprite(game->window, game->floor, NULL);
    sfRenderWindow_drawSprite(game->window, game->personnage, NULL);
    sfRenderWindow_drawSprite(game->window, game->spike->spiker, NULL);
    score_text(score, game);
    score_number(nombre, game);
}

void load_window(game_t *game, score_t *score, nombre_t *nombre)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_world(game, score, nombre);
    sfRenderWindow_display(game->window);
}
