/*
** EPITECH PROJECT, 2021
** bs_csfml
** File description:
** move_rect.c
*/

#include "runner.h"

game_t *base_structs(game_t *game)
{
    game->rect.height = 32;
    game->rect.width = 32;
    game->rect.left = 0;
    game->rect.top = 0;
    game->pos.x = 300;
    game->pos.y = 725;
    game->spike->spike_pos.x = game->spike->convert;
    game->spike->spike_pos.y = 808;
    game->is_grounded = true;
    return game;
}

sfSprite *sprite_creator(char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

void init_sprite(game_t *game)
{
    game->background = sprite_creator("parallax/layer06.png");
    game->para1 = sprite_creator("parallax/layer05.png");
    game->para2 = sprite_creator("parallax/layer04.png");
    game->para3 = sprite_creator("parallax/layer03.png");
    game->para4 = sprite_creator("parallax/layer02.png");
    game->floor = sprite_creator("parallax/layer01.png");
    game->spike->spiker = sprite_creator("ressources/spike_A.png");
    sfSprite_setScale(game->spike->spiker, (sfVector2f) {0.3, 0.3});
    game->personnage = sprite_creator("ressources/Pink_Monster_Run_6.png");
    sfSprite_setScale(game->personnage, (sfVector2f) {5, 5});
}
