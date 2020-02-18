/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#ifndef FOUND
#define FOUND

#include "defender.h"

int play_menu(game_t *window);
int how_to_use(game_t *window);
int option(game_t *window);
int credit(game_t *window);
int display_menu(game_t *);

typedef struct separ {
    int number;
    int (*sort)(game_t *);
} separ_t;

const separ_t SEPARATION_TAB[] = {
    {0, &display_menu},
    {1, &how_to_use},
    {2, &play_menu},
    {3, &option},
    {4, &credit},
    {'\0', NULL}};

#endif
