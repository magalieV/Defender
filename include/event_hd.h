/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#ifndef EVENT_HEADER
#define EVENT_HEADER

    //CHECK_EVENT
void check_quit_game(sfRenderWindow *, sfEvent);
int get_event_menu(game_t, my_button_t *);
int check_button(my_button_t *, sfRenderWindow *);
int get_event_load(game_t window);
#endif
