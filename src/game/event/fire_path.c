/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

moove_t *remove_fire_path(link_t *list, moove_t *moove)
{
    sfTime time = {0};
    float speed = 0;

    while (list && list->prev)
        list = list->prev;
    while (list) {
        for (int i = 0; moove[i].moove; i++) {
            time = sfClock_getElapsedTime(list->clock);
            speed = time.microseconds / 1000000.0;
            if (on_rect(moove[i].corner, list->pos, -1, -1) && speed > 5.0
            && moove[i - 1].moove)
                moove[i - 1].bol = 0;
            }
        if (list->next == NULL)
            break;
        list = list->next;
        }
    return (moove);
}

moove_t *place_fire_path(link_t *list, moove_t *moove)
{
    while (list && list->prev)
        list = list->prev;
    while (list) {
        for (int i = 0; moove[i].moove; i++)
            if (on_rect(moove[i].corner, list->pos, -1, -1)) {
                if (moove[i - 1].moove && moove[i - 1].bol == 0)
                    moove[i- 1].bol = 1;
            }
        if (list->next == NULL)
            break;
        list = list->next;
    }
    moove = remove_fire_path(list, moove);
    return (moove);
}
