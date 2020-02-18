/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

int cond_menu(game_t win, object_t *menu_font, object_t load)
{
    int k = found_menu_ad(win, 0);

    if (k == -1) {
        destroy_menu(win, menu_font, load);
        return (0);
    } else if (k == 84) {
        destroy_menu(win, menu_font, load);
        return (0);
    }
    return (0);
}

void draw_load(game_t win, object_t load, object_t *pict)
{
    if (load.sprite)
        sfRenderWindow_drawSprite(win.basic.window, load.sprite, NULL);
    if (pict != NULL)
        display_object(pict, win);
    draw_square(sfBlack, win.wind);
    sfTexture_updateFromPixels(win.wind.texture, win.wind.buffer->pixels,
        1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(win.basic.window, win.wind.sprite, NULL);
}

int load_page(game_t win, object_t *menu_font, object_t load)
{
    sfClock *clock = sfClock_create();
    bool k = 0;

    sfMusic_setLoop(win.music.music[0], sfTrue);
    sfMusic_play(win.music.music[0]);
    win.bol = 2;
    display_molten(win, load, NULL, 255);
    win.obj = menu_font;
    sfClock_destroy(clock);
    k = sfRenderWindow_isOpen(win.basic.window);
    if (k == 1)
        return (cond_menu(win, menu_font, load));
    destroy_menu(win, menu_font, load);
    return (0);
}
