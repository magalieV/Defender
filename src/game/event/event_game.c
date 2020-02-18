/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

link_t *create_link(link_t *link, event_game_t *my_event, game_t window,
    my_button_t *road)
{
    if ((*my_event).fire_repush == 1) {
        link = create_link_fire(link, &(*my_event), window, road);
        (*my_event).fire = 0;
    }
    (*my_event).button = 0;
    return (link);
}

node_t *create_tower(node_t *node, event_game_t *my_event, path_t path,
    char **tab)
{
    if ((*my_event).repush > 0) {
        node = empire_list(node, tab, &(*my_event), path);
        (*my_event).repush = 0;
        (*my_event).boll = 0;
    }
    return (node);
}

bool on_rect(sfIntRect rect, sfVector2f pos, int x, int y)
{
    if (x >= 0 && y >= 0) {
        rect.top = x;
        rect.height = y;
    }
    if (pos.x >= rect.left && pos.x <= rect.left + rect.top
        && pos.y >= rect.width && pos.y <= rect.width + rect.height)
        return (true);
    return (false);
}

sfVector2i check_pos_mouse(sfRenderWindow *window)
{
    sfVector2i pos = {0};
    sfVector2u test = {0};
    sfVector2i new = {0};

    test = sfRenderWindow_getSize(window);
    pos = sfMouse_getPositionRenderWindow(window);
    new.x = pos.x * 1920 / test.x;
    new.y = pos.y * 1080 / test.y;
    return (new);
}

void event_to_quit_game(game_t *window, event_game_t *my_event,
    my_button_t **button, object_t font)
{
    while (sfRenderWindow_pollEvent((*window).basic.window, &(*window).event)) {
        if ((*window).event.type == sfEvtClosed)
            sfRenderWindow_close((*window).basic.window);
        if_tower_support((*window), button[0], my_event);
        (*my_event).bol = tower_to_list((*window), my_event);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            (*my_event).button = check_button(button[2], window->basic.window);
        display_pause_menu(window, my_event, font, button[3]);
        if ((*my_event).bol > 0 || (*my_event).bol == -1 ||
        (*my_event).button != 0)
            return;
    }
}
