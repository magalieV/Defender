/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

void verify_touch(link_t *monster, node_t *tower)
{
    sfVector2f pos = {0};

    while (tower && tower->prev)
        tower = tower->prev;
    while (tower) {
        for (int i = 0; tower->attak[i].sprite; i++) {
            pos = tower->attak[i].vectf;
            if (tower->way[i] != 0 && on_rect(monster->rect, pos, -1, -1)) {
                monster->life -= tower->fight.damage;
                monster->display = (monster->life <= 0) ? false : true;
                break;
            }
        }
        if (!tower->next)
            break;
        tower = tower->next;
    }
}

void is_monster_touch(link_t *monster, node_t *tower)
{
    while (monster && monster->prev)
        monster = monster->prev;
    while (tower && tower->prev)
        tower = tower->prev;
    while (monster) {
        verify_touch(monster, tower);
        if (!monster->next)
            break;
        monster = monster->next;
    }
}
