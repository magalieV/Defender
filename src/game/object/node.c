/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

link_t *add_link(link_t *begin, anim_t anim, int type,
    anim_t *anim_tab)
{
    link_t *tree = malloc(sizeof(link_t));

    if (!tree)
        return (NULL);
    tree->anim = anim;
    1 ? tree->anim_tab = anim_tab, tree->type = type : 0;
    if (tree->anim_tab) {
        tree->rect.left = tree->anim_tab[0].obj.vectf.x;
        tree->rect.width = tree->anim_tab[0].obj.vectf.y;
        tree->hey = add_life_monster(tree->anim_tab[0].obj.vectf);
    }
    1 ? tree->rect.top = 256, tree->rect.height = 256 : 0;
    1 ? tree->life = 500, tree->display = true : 0;
    tree->clock = sfClock_create();
    1 ? tree->speed = 0, tree->next = NULL : 0;
    if (begin == NULL) {
        tree->prev = NULL;
    } else
        1 ? tree->prev = begin, begin->next = tree : 0;
    return (tree);
}
