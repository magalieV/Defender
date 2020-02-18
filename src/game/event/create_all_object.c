/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

my_button_t **create_all_button(char *path, read_t rd)
{
    sfVector2f pos = {192, 96};
    my_button_t **button = malloc(sizeof(my_button_t *) * 5);
    my_button_t *end = NULL;
    char **butt_tab = read_doub_file("res/file/button_game.txt");
    char **pause = read_doub_file("res/file/button_pause.txt");

    button[0] = create_button_tab(path, path, rd, pos);
    button[1] = create_road();
    button[2] = create_my_button(butt_tab, button[2]);
    button[3] = create_my_button(pause, button[3]);
    button[4] = end;
    return (button);
}
