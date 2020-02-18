/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

object_t lvl_up_tower(int *tabu, sfVector2f pos, char **tab,
    event_game_t *event)
{
    int i = 0;
    object_t new = {0};
    int y = 0;

    if (tabu[1] >= 3)
        return (new);
    for (i = 0; tab[i]; i++) {
        if (my_getnbr(tab[i + 1]) != tabu[1] ||
        my_getnbr(tab[i + 2]) != tabu[0]) {
            i += 5;
        } else
            break;
    }
    if (my_getnbr(tab[i + 5]) > (*event).money)
        return (new);
    else
        (*event).money -= my_getnbr(tab[i + 5]);
    y = my_getnbr(tab[i + 4]);
    pos.y = pos.y - y + 73;
    create_object(tab[i], 0, pos, &new);
    return (new);
}

void what_tower(int bol, object_t *tower, game_t window, sfClock *cl)
{
    sfVector2f pos = {0};
    sfVector2i mouse = {0};
    sfTime time = {0};

    time = sfClock_getElapsedTime(cl);
    if (time.microseconds / 1000000.0 < 0.0005)
        return;
    mouse = check_pos_mouse(window.basic.window);
    1 ? pos.x = mouse.x, pos.y = mouse.y : 0;
    bol == 1 ? sfSprite_setPosition(tower[0].sprite, pos),
    sfRenderWindow_drawSprite(window.basic.window, tower[0].sprite, NULL) : 0;
    bol == 2 ? sfSprite_setPosition(tower[1].sprite, pos),
    sfRenderWindow_drawSprite(window.basic.window, tower[1].sprite, NULL) : 0;
    if (bol == 3) {
        sfSprite_setPosition(tower[2].sprite, pos);
        sfRenderWindow_drawSprite(window.basic.window, tower[2].sprite, NULL);
    } else if (bol != 1 && bol != 2 && bol != 3) {
        sfSprite_setPosition(tower[3].sprite, pos);
        sfRenderWindow_drawSprite(window.basic.window, tower[3].sprite, NULL);
    }
}

int if_tower_support(game_t window, my_button_t *button, event_game_t *my_event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && (*my_event).bol > 0) {
        (*my_event).repush = check_button_game(button, window.basic.window);
        (*my_event).boll = (*my_event).bol;
        (*my_event).bol = -1;
        if ((*my_event).repush == -1)
            return (-1);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && (*my_event).fire > 0) {
        (*my_event).fire_repush = 1;
        (*my_event).fire = -1;
        (*my_event).bol = -1;
        if ((*my_event).fire_repush == -1)
            return (-1);
    }
    return (0);
}

int tower_to_list(game_t window, event_game_t *my_event)
{
    sfVector2i pos = {0};
    static int bol = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        pos = check_pos_mouse(window.basic.window);
            if (pos.x > 758 && pos.x < 825 && pos.y > 956 && pos.y < 1022)
                return (bol = 1, 1);
            if (pos.x > 825 && pos.x < 893 && pos.y > 956 && pos.y < 1022)
                return (bol = 2, 2);
            if (pos.x > 893 && pos.x < 960 && pos.y > 956 && pos.y < 1022)
                return (bol = 3, 3);
            if (pos.x > 960 && pos.x < 1027 && pos.y > 956 && pos.y < 1022)
                return (my_event->fire = 1, 0);
        if (bol >= 1)
            bol = 0;
            return (-1);
        }
    return (bol);
}
