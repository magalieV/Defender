/*
** EPITECH PROJECT, 2018
** defender
** File description:
** Created by remipeyras,
*/

#ifndef DEFENDER_STRUCT_DEFENDER_H
#define DEFENDER_STRUCT_DEFENDER_H

#include "my_g.h"
#include "my.h"
#include <stdbool.h>

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} frame_buffer_t;

typedef struct win {
    frame_buffer_t *buffer;
    sfColor color;
    int x;
    int y;
    int max_x;
    int max_y;
    sfSprite *sprite;
    sfTexture *texture;
} win_t;

typedef struct button_s {
    sfTexture *texture[2];
    sfSprite *sprite[2];
    sfIntRect rect;
    sfVector2f pos;
} button_t;

typedef struct music_s {
    sfMusic **music;
    sfMusic **sound;
    float mus_vol;
    float snd_vol;
} music_t;

typedef struct text_s {
    sfFont *font;
    sfText **text;
} text_t;

typedef struct object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vectf;
    float speed;
} object_t;

typedef struct my_button {
    sfIntRect rect;
    object_t hover;
    object_t butt;
    object_t press;
    bool end;
} my_button_t;

typedef struct anim_s {
    object_t obj;
    sfIntRect rect;
    int offset;
    sfClock *clock;
} anim_t;

typedef struct base_s {
    sfVideoMode mode;
    sfRenderWindow *window;
} base_t;

typedef struct event_game {
    int bol;
    int boll;
    int repush;
    int button;
    int score;
    int fire;
    int fire_repush;
    int castle;
    int nb_mob;
    int pause;
    unsigned int money;
} event_game_t;

typedef struct read {
    int nb;
    sfVector2f *vect;
} read_t;

typedef struct game_s {
    int bol;
    base_t basic;
    sfEvent event;
    music_t music;
    text_t text;
    object_t *obj;
    my_button_t *butt;
    anim_t anim;
    win_t wind;
    read_t read;
    char **map;
    char **tower;
} game_t;

typedef struct assit_t {
    object_t *obj;
    text_t text;
} assit_s;

typedef struct transport_t {
    my_button_t *button;
    object_t back;
    object_t *info;
    text_t name;
    assit_s *selection;
} transport_s;

#endif /*DEFENDER_STRUCT_DEFENDER_H*/
