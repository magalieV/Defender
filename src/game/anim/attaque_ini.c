/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

object_t *ini_attaque(sfVector2f pos, int type)
{
    object_t *new = malloc(sizeof(object_t) * (5));
    object_t end = {0};
    int k = 0;
    char **tab = read_doub_file("res/file/anim_attaque.txt");

    if (type == 1) {
        for (int i = 0; i < 4; i++)
            create_object(tab[i], 0, pos, &new[k++]);
    } else if (type == 2) {
        for (int i = 0; i < 4; i++)
            create_object(tab[4], 0, pos, &new[k++]);
    } else {
        for (int i = 0; i < 4; i++)
            create_object(tab[5], 0, pos, &new[k++]);
    }
    new[k] = end;
    return (new);
}

static bool found_diff(int mvt, float cdt1, float cdt2)
{
    if ((mvt == 1 || mvt == 2) && cdt2 < cdt1)
        return (true);
    if ((mvt == 4 || mvt == 3) && cdt2 > cdt1)
        return (true);
    return (false);
}

node_t *ini_path(node_t *node, moove_t *moove, int *nb, float cdt1)
{
    int b = 0;
    float cdt2 = 0;

    cdt2 = (nb[1] == 1 || nb[1] == 4) ? node->attak[nb[0]].vectf.y :
    node->attak[nb[0]].vectf.x;
    for (int i = 0; moove[i].moove; i++) {
        while (found_diff(nb[1], cdt1, cdt2) && b == 0) {
            if (on_rect(moove[i].corner, node->attak[nb[0]].vectf, -1, -1) &&
                b == 0) {
                1 ?node->way[nb[0]] = nb[1], b = 1, reini_node(node, nb[0]) : 0;
                return (node);
            }
            try_down(node, nb[1]);
            cdt2 = (nb[1] == 1 || nb[1] == 4) ? node->attak[nb[0]].vectf.y :
            node->attak[nb[0]].vectf.x;
        }
        reini_node(node, nb[0]);
        cdt2 = (nb[1] == 1 || nb[1] == 4) ? node->attak[nb[0]].vectf.y :
        node->attak[nb[0]].vectf.x;
    }
    return (1 ? reini_node(node, nb[0]), node : 0);
}

node_t *found_attaque_path(node_t *node, moove_t *moove)
{
    int *nb = malloc(sizeof(int) * (4));

    1 ? nb[0] = 2, nb[1] = 1, nb[2] = 0 : 0;
    node = ini_path(node, moove, nb, node->init.y + node->range.y);
    1 ? nb[0] = 3, nb[1] = 4, nb[2] = 0 : 0;
    node = ini_path(node, moove, nb, node->init.y - node->range.y);
    1 ? nb[0] = 0, nb[1] = 2, nb[2] = 0 : 0;
    node = ini_path(node, moove, nb, node->init.y + node->range.x);
    1 ? nb[0] = 1, nb[1] = 3, nb[2] = 0 : 0;
    node = ini_path(node, moove, nb, node->init.y - node->range.x);
    free(nb);
    return (node);
}

object_t *create_attaq(node_t *node, sfVector2f pos, int type, moove_t *moove)
{
    char *path = "res/game/arrow_right.png";
    char *path_fire = "res/game/fire_ball.png";
    char *path_stone = "res/game/stone.png";
    object_t *new = NULL;

    pos.y -= 126;
    pos.x += 20;
    new = ini_attaque(pos, type);
    node->way[0] = 0;
    node->way[1] = 0;
    node->way[2] = 0;
    node->way[3] = 0;
    node->init = pos;
    node->fight.range[0] = pos.x + 400;
    node->fight.range[1] = pos.y + 400;
    node->fight.range[2] = pos.x - 400;
    node->fight.range[3] = pos.y - 400;
    node->range.x = pos.x + 300;
    node->range.y = pos.y + 300;
    return (new);
}
