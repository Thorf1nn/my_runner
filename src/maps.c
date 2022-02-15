/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-luca.orelli
** File description:
** maps_open.c
*/

#include "runner.h"

void get_info_file(char const *filepath, game_t *game)
{
    FILE *fp = fopen(filepath, "r");
    size_t size = my_strlen(filepath);

    game->spike = malloc(sizeof(spike_t));
    game->spike->data = NULL;
    while (getline(&game->spike->data, &size, fp))
        break;
    game->spike->convert = to_number(game->spike->data);
}
