/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#ifndef MENU_HEADER
#define MENU_HEADER

    //BUTTON
static int assign_rect(char **, int, sfIntRect *);
my_button_t *create_my_button(char **, my_button_t *);
void destroy_my_button(my_button_t *);

    //LOAD
int create_menu_font(object_t **);
int load_page(game_t, object_t *, object_t);
int my_defender(void);

    //MENU_DISPLAY

object_t *open_back(game_t, object_t *, sfClock *, bool);
object_t *close_back(game_t, object_t *, sfClock *, bool);
void display_render(game_t, object_t *);
void display_button(game_t, my_button_t *);
//static void found_menu_ad(game_t, int);
//int display_menu(game_t, object_t *, sfClock *);

int how_to_use(game_t *);

//tuto
int tuto_event(game_t *, sfEvent *);
int set_tuto(game_t *);
int draw_tuto(game_t *, anim_t);
void destroy_tuto(game_t);

//option
int option_event(game_t *, sfEvent *);
int set_option(game_t *);
int draw_option(game_t *, sfText **);
void destroy_option(game_t);

//building_menu
int draw_test_building(game_t, transport_s);

#endif
