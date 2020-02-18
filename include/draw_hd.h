/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#ifndef DRAW_HEADER
#define DRAW_HEADER

    //PIXEL
void draw_square(sfColor, win_t);
void my_put_pixel(frame_buffer_t *, unsigned int, unsigned int, sfColor);
void frame_buffer_destroy(frame_buffer_t *);
frame_buffer_t *frame_buffer_create(unsigned int, unsigned int);
void draw_load(game_t win, object_t load, object_t *pict);
char **my_str_to_word_array(char const *str);
void write_on_file(char const *score, char **map, game_t window);
char **str_to_tab(char const *str);
int draw_credit(game_t *win, object_t *obj);
int set_credit(game_t *win, object_t *obj);
void destroy_credit(game_t *win);
void display_molten(game_t window, object_t font, object_t *pict, int alpha);
char *my_read_file(char const *str);

#endif
