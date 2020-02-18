/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

int set_basic(base_t *base);

void free_node(node_t *node)
{
    sfTexture_destroy(node->object.texture);
    sfSprite_destroy(node->object.sprite);
    node->next = NULL;
    node->prev = NULL;
    free(node);
}

object_t *create_place_object(object_t *place, char const *path, char *nb,
    game_t *window)
{
    object_t end = {0};
    int a = 0;

    if (alloc_place_board(&place, &(*window).read, nb) == -1)
        return (NULL);
    place = malloc(sizeof(object_t) * ((*window).read.nb + 1));
    for (a = 0; a < (*window).read.nb; a++)
        if (create_object(path, 0, (*window).read.vect[a], &place[a]) == -1)
            return (NULL);
    place[a] = end;
    return (place);
}

my_button_t *create_road(void)
{
    my_button_t *road = NULL;
    read_t read = {0};
    object_t *end = NULL;
    sfVector2f size = {190, 190};
    char *path = "res/game/road.png";

    if (alloc_place_board(&end, &read, "2S") == -1)
        return (NULL);
    road = create_button_tab(path, "res/game/road_hover.png", read, size);
    return (road);
}

int ini_back_game(game_t window, event_game_t my_event)
{
    char **tab = read_doub_file("res/file/game_picture.txt");
    object_t **essaie = tab_game(essaie, tab, &window);
    my_button_t **butt = create_all_button("res/game/Place.png", window.read);

    if (butt[1] == NULL)
        return (-1);
    my_event.money = 500;
    window.bol = 0;
    display_molten(window, essaie[0][0], essaie[6], 255);
    window.map = read_doub_file("src/game/board.txt");
    window.tower = read_doub_file("res/file/tower_display.txt");
    display_background(window, essaie, my_event, butt);
    destroy_doub_tab(window.map);
    destroy_doub_tab(window.tower);
    return (-1);
}
