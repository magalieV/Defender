/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

void destroy_doub_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void destroy_obj(object_t *ob)
{
    for (int i = 0; ob[i].vectf.x; i++) {
        sfSprite_destroy(ob[i].sprite);
        sfTexture_destroy(ob[i].texture);
    }
}

void destroy_menu(game_t window, object_t *one, object_t two)
{
    destroy_music(window.music);
    sfSprite_destroy(two.sprite);
    sfTexture_destroy(two.texture);
    destroy_obj(one);
    frame_buffer_destroy(window.wind.buffer);
    sfRenderWindow_destroy(window.basic.window);
}
