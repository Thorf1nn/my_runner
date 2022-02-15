/*
** EPITECH PROJECT, 2021
** bs_initcsfml
** File description:
** main.c
*/

#include "runner.h"

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    score_t *score = malloc(sizeof(score_t));
    nombre_t *nombre = malloc(sizeof(nombre_t));
    if (ac != 2) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 is required \
        \nretry with -h\n");
        return 84;
    }
    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0) {
            helping();
            return 0;
        }
        if (my_strcmp(av[1], "tilemap/map.txt") == 0)
            get_info_file((av[1]), game);
        else
            return 84;
    }
    lunch(game, score, nombre);
    return 0;
}

void lunch(game_t *game, score_t *score, nombre_t *nombre)
{
    before_loop(game);
    while (sfRenderWindow_isOpen(game->window)) {
        call_all(game, score, nombre);
    }
    destroy_game(game);
}

void before_loop(game_t *game)
{
    base_structs(game);
    init(game);
    create_musique(game);
}

void call_all(game_t *game, score_t *score, nombre_t *nombre)
{
    sfSprite_setTextureRect(game->personnage, game->rect);
    sfSprite_setPosition(game->personnage, game->pos);
    perso_time(game);
    analyse_events(game);
    init_world(game, score, nombre);
    jump(game);
    sprites_move(game);
}

void helping(void)
{
    my_putstr("\nCandy runner created with CSFML. \n\n \
    USAGE\n \
    \t./my_runner tilemap/map.txt \n\n \
    OPTIONS\n \
    \t-h print the usage and quit.\n\n \
    USER INTERACTIONS\n \
    \tSPACE_KEY = jump.\n \
    \tESCAPE_KEY = close.\n\n \
    GAME FONCTIONING\n \
    \tThe goal of this game is simple.\n \
    \tYou just have to avoid the spikes and reach 1000 of score.\n\n \
    TILE MAP FONCTIONING\n \
    \tThe value in the txt file corespond to the x\
    \b\b\b(horizontal) spike coordinate\n\
    \tYou just have to change the value for\
    \b\b\bchange the spike x position in the map.\n \
    \texemple :\n \
    \t1500 = position x of the spike\n\n");
}
