/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

void try_down(node_t *node, int bol)
{
    switch (bol) {
        case 1 :
            node->attak[2].vectf.y += 3;
            sfSprite_setPosition(node->attak[2].sprite, node->attak[2].vectf);
            break;
        case 4 :
            node->attak[3].vectf.y -= 3;
            sfSprite_setPosition(node->attak[3].sprite, node->attak[3].vectf);
            break;
        case 2 :
            node->attak[0].vectf.x += 3;
            sfSprite_setPosition(node->attak[0].sprite, node->attak[3].vectf);
            break;
        case 3 :
            node->attak[1].vectf.x -= 3;
            sfSprite_setPosition(node->attak[1].sprite, node->attak[3].vectf);
            break;
        default :
            break;
    }
}

node_t *reini_node(node_t *node, int nb)
{
    node->attak[nb].vectf = node->init;
    sfSprite_setPosition(node->attak[nb].sprite, node->attak[nb].vectf);
}

void moove_attak(node_t *node, game_t window)
{
    sfVector2f pos = {0};

    for (int i = 0; node->attak[i].sprite; i++) {
        pos.x = node->attak[i].vectf.x;
        pos.y = node->attak[i].vectf.y;
        if (node->way[i] == 4)
            pos.y -= 2;
        if (node->way[i] == 1)
            pos.y += 2;
        if (node->way[i] == 2)
            pos.x += 2;
        if (node->way[i] == 3)
            pos.x -= 2;
        if (pos.x >= node->fight.range[0] || pos.y >= node->fight.range[1])
            pos = node->init;
        else if (pos.x <= node->fight.range[2] || pos.y <= node->fight.range[3])
            pos = node->init;
        node->attak[i].vectf.x = pos.x;
        node->attak[i].vectf.y = pos.y;
        sfSprite_setPosition(node->attak[i].sprite, pos);
    }
}

void display_attaque(node_t *node, game_t window, sfClock *cl)
{
    sfTime time = {0};
    int i = 0;

    while (node && node->prev)
        node = node->prev;
    while (node) {
        time = sfClock_getElapsedTime(cl);
        if (time.microseconds / 1000000.0 > 0.00005) {
            for (int i = 0; node->attak[i].sprite; i++) {
                if (node->way[i] != 0)
                    sfRenderWindow_drawSprite(window.basic.window,
                        node->attak[i].sprite, NULL);
                moove_attak(node, window);
            }
            sfClock_restart(cl);
            if (node->next == NULL)
                break;
            node = node->next;
        }
    }
}
