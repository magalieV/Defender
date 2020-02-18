/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

int check_button_game(my_button_t *butt, sfRenderWindow *window)
{
    sfVector2i new = {0};

    new = check_pos_mouse(window);
    for (int i = 0; butt[i].butt.sprite; i++) {
        if (sfIntRect_contains(&butt[i].rect, new.x, new.y) == true) {
            sfRenderWindow_drawSprite(window, butt[i].hover.sprite, NULL);
            if (butt[i].butt.sprite != NULL)
                return (i + 1);
            else {
                return (-1);
            }
        }
    }
    return (0);
}

link_t *mvt_monster(link_t *list, moove_t *moove, sfVector2f ps, bool stop)
{
    while (list) {
        ps.x = list->anim_tab[0].obj.vectf.x;
        ps.y = list->anim_tab[0].obj.vectf.y;
        stop = list->type == 3 ? true : false;
        ps.y -= (list->speed == 4 && stop == false) ? 3 : 0;
        ps.y += (list->speed == 1 && stop == false) ? 3 : 0;
        ps.x += (list->speed == 2 && stop == false) ? 3 : 0;
        ps.x -= (list->speed == 3 && stop == false) ? 3 : 0;
        for (int i = 0; list->anim_tab[i].obj.sprite; i++) {
            1 ? list->rect.left = ps.x, list->rect.width = ps.y : 0;
            list->anim_tab[i].obj.vectf.y = ps.y;
            list->anim_tab[i].obj.vectf.x = ps.x;
            sfSprite_setPosition(list->anim_tab[i].obj.sprite, ps);
        }
        if (!list->next)
            break;
        list = list->next;
    }
    return (list);
}

link_t *on_function(moove_t *moove, int i, sfVector2f pos, link_t *list)
{
    if (on_rect(moove[i].corner, pos, -1, -1)
    && list->speed != 4) {
        list->speed = moove[i].moove;
    } else if (on_rect(moove[i].corner, pos, 180, 3)
    && list->speed == 4) {
        list->speed = moove[i].moove;
    }
    return (list);
}

link_t *loop_affect(moove_t *moove, link_t *list, int *size, sfVector2f pos)
{
    for (int i = 0; moove[i].moove; i++) {
        pos.x = list->anim_tab[0].obj.vectf.x;
        pos.y = list->anim_tab[0].obj.vectf.y;
        list->type = 0;
        if (on_rect(moove[*size - 1].corner, pos, -1, -1)) {
            list->type = 3;
            break;
        }
        if (on_rect(moove[i].corner, pos, -1, -1)
        && moove[i].bol != 0) {
            *size = -1;
            return (list);
        }
        list = on_function(moove, i, pos, list);
    }
    return (list);
}
