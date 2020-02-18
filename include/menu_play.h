/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MENU_PLAY
#define MENU_PLAY
int f_pro(game_t game, int bol);
int lvl(game_t game, int bol);
int infi_game(game_t game, int bol);

typedef struct separ {
    int event;
    int (*sort)(game_t, int bol);
} separ_t;

const separ_t SEPARATION_MEN[] = {
    {1, &infi_game},
    {2, &f_pro},
    {3, &lvl},
    {4, &lvl},
    {5, &lvl},
    {6, &lvl},
    {'\0', NULL}};
#endif
