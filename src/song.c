/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-luca.orelli
** File description:
** jump_song.c
*/

#include "runner.h"

void create_jumpsong(game_t *game)
{
    game->jumpsong = sfMusic_createFromFile("ressources/jumpsong.ogg");
    if (game->jumpsong)
        sfMusic_play(game->jumpsong);
}

void create_musique(game_t *game)
{
    game->music = sfMusic_createFromFile("ressources/musique.ogg");
    if (game->music)
        sfMusic_play(game->music);
}
