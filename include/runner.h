/*
** EPITECH PROJECT, 2021
** bs_initcsfml
** File description:
** runner.h
*/

#ifndef RUNNER_H_
    #define RUNNER_H_
    #define GRAVITY 9.81
    #define JUMP_HEIGHT 30
    #define FRICTION 0.95
    #include <stdarg.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <assert.h>
    #include <string.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <pwd.h>
    #include <time.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Export.h>
    #include <stdbool.h>

typedef struct counter_s {
    sfClock *clock;
    int score;
} counter_t;

typedef struct spike_s {
    sfVector2f spike_pos;
    int convert;
    char *data;
    sfSprite *spiker;
} spike_t;

typedef struct over_s {
    sfVector2f over_pos;
    sfSprite *over;
    sfSprite *over2;
} over_t;

typedef struct game_s {
    bool is_grounded;
    sfEvent event;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f speed;
    sfVector2f *speed1;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfSprite *personnage;
    sfSprite *background;
    sfSprite *para1;
    sfSprite *para2;
    sfSprite *para3;
    sfSprite *para4;
    sfSprite *floor;
    float second;
    float mili;
    sfClock *clock;
    sfTime time;
    sfMusic *music;
    sfMusic *jumpsong;
    counter_t *counter;
    spike_t *spike;
    over_t *over;
} game_t;

typedef struct score_s {
    sfText *text_text;
    sfFont *font_text;
    sfVector2f pos_text;
    sfText *text_nb;
    sfFont *font_nb;
    sfVector2f pos_nb;
    int clock_s;
    int score_t;
    char *str;
    counter_t *counter;
} score_t;

typedef struct nombre_s {
    sfText *text_text;
    sfFont *font_text;
    sfVector2f pos_text;
    sfText *text_nb;
    sfFont *font_nb;
    sfVector2f pos_nb;
    int clock_s;
    int score_t;
    char *str;
} nombre_t;

game_t *base_structs(game_t *game);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char *str);
void my_putchar(char c);
void sprites_move(game_t *game);
void move_rect(sfIntRect *rect, int offset, int max_value);
void destroy_game(game_t *game);
void analyse_events(game_t *game);
void create_musique(game_t *game);
void draw_world(game_t *game, score_t *score, nombre_t *nombre);
void init(game_t *game);
void create_time(game_t *game);
void load_window(game_t *game, score_t *score, nombre_t *nombre);
void init_sprite(game_t *game);
sfSprite *sprite_creator(char *filepath);
void perso_time(game_t *game);
void init_world(game_t *game, score_t *score, nombre_t *nombre);
void call_all(game_t *game, score_t *score, nombre_t *nombre);
void jump(game_t *game);
void helping(void);
void score_text(score_t *score, game_t *game);
void my_itoa(char *s, unsigned int n);
void score_number(nombre_t *nombre, game_t *game);
int score_counter(int score);
void init_score(counter_t *counter);
void update_score(counter_t *counter);
void create_jumpsong(game_t *game);
void perso_time_jump(game_t *game);
int to_number(char const *str);
int my_strlen(char const *str);
void get_info_file(char const *filepath, game_t *game);
void before_loop(game_t *game);
void spike_sprites_moov(game_t *game);
void game_over_game(game_t *game, nombre_t *nombre);
void lunch(game_t *game, score_t *score, nombre_t *nombre);

#endif
