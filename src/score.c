/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-luca.orelli
** File description:
** score.c
*/

#include "runner.h"

void score_text(score_t *score, game_t *game)
{
    score->str = "SCORE :";
    score->font_text = sfFont_createFromFile("ressources/Hello Snow.ttf");
    score->text_text = sfText_create();
    sfText_setCharacterSize(score->text_text, 40);
    sfText_setString(score->text_text, score->str);
    sfText_setFont(score->text_text, score->font_text);
    sfText_setColor(score->text_text, sfWhite);
    score->pos_text.x = 700;
    score->pos_text.y = 10;
    sfText_setPosition(score->text_text, score->pos_text);
    sfRenderWindow_drawText(game->window, score->text_text, NULL);
}

void score_number(nombre_t *nombre, game_t *game)
{
    char str[10];
    game->over = malloc(sizeof(over_t));
    if (nombre->score_t < 1000)
        nombre->score_t += 1;
    my_itoa(str, nombre->score_t);
    nombre->font_text = sfFont_createFromFile("ressources/Hello Snow.ttf");
    nombre->text_text = sfText_create();
    sfText_setCharacterSize(nombre->text_text, 40);
    sfText_setString(nombre->text_text, str);
    sfText_setFont(nombre->text_text, nombre->font_text);
    sfText_setColor(nombre->text_text, sfWhite);
    nombre->pos_text.x = 1000;
    nombre->pos_text.y = 10;
    sfText_setPosition(nombre->text_text, nombre->pos_text);
    sfRenderWindow_drawText(game->window, nombre->text_text, NULL);
    game_over_game(game, nombre);
}

void game_over_game(game_t *game, nombre_t *nombre)
{
    if (sfSprite_getPosition(game->spike->spiker).x == game->pos.x
    && game->pos.y == 725)
        nombre->score_t = 1000;
    if (nombre->score_t == 1000) {
        game->over->over = sprite_creator("ressources/gameover.jpg");
        sfRenderWindow_drawSprite(game->window, game->over->over, NULL);
        sfMusic_stop(game->music);
        sfMusic_stop(game->jumpsong);
    }
}
