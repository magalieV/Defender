/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

void check_quit_game(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}

int get_event_load(game_t window)
{
    if (sfRenderWindow_pollEvent(window.basic.window, &window.event)) {
        check_quit_game(window.basic.window, window.event);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            return (1);
        return (get_event_load(window));
    }
    return (0);
}

int check_button(my_button_t *butt, sfRenderWindow *window)
{
    sfVector2i new = {0};

    new = check_pos_mouse(window);
    for (int i = 0; butt[i].butt.sprite; i++) {
        if (sfIntRect_contains(&butt[i].rect, new.x, new.y) == true) {
            sfRenderWindow_drawSprite(window, butt[i].hover.sprite, NULL);
            if (butt[i + 1].butt.sprite != NULL)
                return (i + 1);
            else {
                sfRenderWindow_close(window);
                return (-1);
            }
        }
    }
    return (0);
}

int get_event_menu(game_t window, my_button_t *butt)
{
    if (sfRenderWindow_pollEvent(window.basic.window, &window.event)) {
        if (window.event.type == sfEvtClosed) {
            sfRenderWindow_close(window.basic.window);
            return (-1);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft))
            return (check_button(butt, window.basic.window));
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return (1);
    }
    return (0);
}
