/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-luca.orelli
** File description:
** key_event.c
*/

#include "runner.h"

void analyse_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtKeyPressed && game->event.key.code
        == sfKeyEscape)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtKeyPressed && game->event.key.code
        == sfKeySpace && game->is_grounded == true) {
            create_jumpsong(game);
            game->is_grounded = false;
            game->speed.y = -JUMP_HEIGHT;
        }
    }
}
