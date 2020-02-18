/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

void draw_life(link_t *list, game_t window)
{
    for (int i = 0; list->hey[i].sprite; i++) {
        sfSprite_setPosition(list->hey[i].sprite, list->anim_tab[0].obj.vectf);
    }
    if (list->life > 60) {
        sfRenderWindow_drawSprite(window.basic.window,
            list->hey[0].sprite, NULL);
    } else if (list->life > 40)
        sfRenderWindow_drawSprite(window.basic.window,
            list->hey[1].sprite, NULL);
    else
        sfRenderWindow_drawSprite(window.basic.window,
            list->hey[2].sprite, NULL);
}

void draw_monster(link_t *list, game_t window, sfClock *cl)
{
    int i = 0;
    sfTime time = {0};

    while (list && list->prev)
        list = list->prev;
    while (list) {
        time = sfClock_getElapsedTime(cl);
        if (time.microseconds / 1000000.0 > 0.00005) {
            if (list->speed > 0 && list->display == true) {
                draw_anim(&list->anim_tab[(int)list->speed - 1],
                window.basic.window);
                draw_life(list, window);
            }
            i++;
            if (list->next == NULL)
                break;
            list = list->next;
            sfClock_restart(cl);
        }
    }
}

link_t *moove_anim_monster(link_t *list, moove_t *moove, sfVector2f ps)
{
    bool stop = false;

    while (list && list->prev && (list = list->prev));
    list = mvt_monster(list, moove, ps, stop);
    while (list && list->prev && (list = list->prev));
    return (list);
}

link_t *moove_monster(link_t *list, char **tab, moove_t *moove, sfClock *cl)
{
    sfVector2f pos = {0};
    int size = 0;
    sfTime time = {0};

    for (size = 0; moove[size].moove; size++);
    if (!list)
        return (list);
    while (list && list->prev && (list = list->prev));
    while (list) {
        time = sfClock_getElapsedTime(cl);
        if (time.microseconds / 1000000.0 > 0.00005) {
            list = loop_affect(moove, list, &size, pos);
            if (size < 0)
                return (list);
            sfClock_restart(cl);
            if (!list->next)
                break;
            list = list->next;
        }
    }
    return (moove_anim_monster(list, moove, pos));
}
