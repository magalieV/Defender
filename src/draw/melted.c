/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

int set_load_part_one(win_t *wind, sfClock *clock, int bol, int ind)
{
    sfTime time = {0};
    double speed = 0;

    time = sfClock_getElapsedTime(clock);
    speed = time.microseconds / 1000000.0;
    if (speed >= 0.005 && (*wind).color.a - 2 >= 0 && bol == 0) {
        (*wind).color.a -= 2;
        if ((*wind).color.a - 5 < 0)
            bol = ind == 0 ? 2 : 1;
        sfClock_restart(clock);
    }
    return (bol);
}

int set_load_part_two(win_t *wind, sfClock *clock, int bol)
{
    sfTime time = {0};
    double speed = 0;

    time = sfClock_getElapsedTime(clock);
    speed = time.microseconds / 1000000.0;
    if (speed >= 0.005 && (*wind).color.a + 2 <= 255 && bol == 1) {
        (*wind).color.a += 2;
        bol = (*wind).color.a + 5 > 255 ? 2 : bol;
        sfClock_restart(clock);
    }
    return (bol);
}

int set_load_color(win_t *wind, sfClock *clock, int bol, int boll)
{
    sfTime time = {0};
    double speed = 0;

    if (boll == 0)
        bol = set_load_part_one(wind, clock, boll, 0);
    else if (boll == 1)
        bol = set_load_part_two(wind, clock, boll);
    else {
        bol = set_load_part_one(wind, clock, bol, 1);
        bol = set_load_part_two(wind, clock, bol);
    }
    return (bol);
}

void display_molten(game_t window, object_t font, object_t *pict, int alpha)
{
    sfClock *clock = sfClock_create();
    int bolean = 0;
    sfClock *cl = sfClock_create();
    sfTime time = {0};

    if (alpha < 0 || alpha > 255)
        return;
    window.wind.color.a = alpha;
    while (sfRenderWindow_isOpen(window.basic.window)) {
        sfRenderWindow_display(window.basic.window);
        time = sfClock_getElapsedTime(cl);
        if (time.microseconds / 1000000.0 > 0.0005
            && (bolean = set_load_color(&window.wind, clock, bolean,
                window.bol)) != 2) {
            draw_load(window, font, pict);
            sfClock_restart(cl);
        } else if (time.microseconds / 1000000.0 > 0.0005)
            break;
        if (get_event_load(window) == 1)
            break;
    }
}
