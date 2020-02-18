/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

node_t *add_node(object_t object, int *tabu, sfVector2f pos, moove_t *moove)
{
    node_t *tree = malloc(sizeof(node_t));
    char **tab = create_tab_fire(pos, "res/file/anim_attaque.txt", 0, 0);

    if (!tree)
        return (NULL);
    tree->object = object;
    tree->lvl = tabu[1];
    tree->vectf = pos;
    tree->fight.damage = tabu[0];
    tree->type = tabu[0];
    tree->attak = create_attaq(tree, pos, tabu[0], moove);
    tree = found_attaque_path(tree, moove);
    tree->next = NULL;
    tree->prev = NULL;
    return (tree);
}

void connect_links(node_t *link1, node_t *link2, link_t *link3, link_t *link4)
{
    if (link1) {
        link1->next = link2;
        if (link2 != NULL)
            link2->prev = link1;
    }
    if (link3) {
        link3->next = link4;
        if (link4 != NULL)
            link4->prev = link3;
    }
}

node_t *one_link(node_t *link, char **tab, event_game_t *event,
    my_button_t *button)
{
    sfVector2f pos = button[(*event).repush - 1].butt.vectf;
    object_t new = {0};
    int tabu[2] = {0};

    if (link->type != (*event).boll)
        return (link);
    tabu[0] = link->type;
    tabu[1] = link->lvl + 1;
    new = lvl_up_tower(tabu, pos, tab, event);
    if (!new.sprite)
        return (link);
    link->object = new;
    link->lvl += 1;
    link->fight.damage += 1;
    return (link);
}

node_t *no_link(node_t *link, char **tab, event_game_t *event, path_t path)
{
    sfVector2f pos = path.place[(*event).repush - 1].butt.vectf;
    object_t new = {0};
    node_t *new_link = NULL;
    int tabu[2] = {0};

    while (link && link->next)
        link = link->next;
    tabu[0] = event->boll;
    tabu[1] = 0;
    new = lvl_up_tower(tabu, pos, tab, event);
    if (!new.sprite)
        return (link);
    new_link = add_node(new, tabu, pos, path.moove);
    connect_links(link, new_link, NULL, NULL);
    if (!link) {
        link = new_link;
        link->next = NULL;
        link->prev = NULL;
    }
    return (link);
}

node_t *empire_list(node_t *link, char **tab, event_game_t *event, path_t path)
{
    sfVector2f pos = path.place[(*event).repush - 1].butt.vectf;
    int bol = 0;

    while (link && link->prev != NULL)
        link = link->prev;
    while (link && bol == 0) {
        if (link->vectf.x == pos.x && link->vectf.y == pos.y) {
            link = one_link(link, tab, event, path.place);
            bol = 1;
        } else if (link->next == NULL)
                break;
        else
            link = link->next;
    }
    if (bol == 0)
        link = no_link(link, tab, event, path);
    while (link && link->prev != NULL)
        link = link->prev;
    return (link);
}
