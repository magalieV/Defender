/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

sfIntRect assign_moove(int x, int y, sfIntRect corner)
{
    corner.left = x * 180;
    corner.width = y * 180;
    corner.top = 180;
    corner.height = 180;
    return (corner);
}

sfVector2f found_pos_path(char **map, int *nb, bool *bol)
{
    int tab[8] = {1, 0, 0, 1, -1, 0, 0, -1};
    sfVector2f pos = {0};

    if (verify_end(map, nb[0], nb[1])) {
        *bol = true;
        return (pos);
    }
    for (int i = 0; i < 8; i++) {
        pos.x = nb[0] + tab[i];
        pos.y = nb[1] + tab[i + 1];
        if (map[(int)(pos.y)] && map[(int)(pos.y)][(int)(pos.x)]
        && map[(int)(pos.y)][(int)(pos.x)] == '2'
        && (pos.y != nb[3] || pos.x != nb[2]))
            return (pos);
        i++;
    }
    *bol = true;
    return (pos);
}

int found_moove(int x, int y, int x_next, int y_next)
{
    if (y > y_next)
        return (4);
    if (y < y_next)
        return (1);
    if (x < x_next)
        return (2);
    if (x > x_next)
        return (3);
    return (4);
}

void found_start(int *y, int *x, char **map)
{
    int i = 0;
    int j = 0;

    for (i = 0; map[i]; i++) {
        for (j = 0; map[i][j]; j++) {
            if (map[i][j] == 'S') {
                *x = j;
                *y = i;
                return;
            }
        }
    }
    *x = j;
    *y = i;
}

moove_t *found_path(char **tab)
{
    read_t rd = {0};
    moove_t *path = NULL;
    int k = 0;
    int i = 0;
    int j = 0;
    bool bol = false;
    int *nb = malloc(sizeof(int) * (4));

    if (alloc_place_board(NULL, &rd, "2S") == -1)
        return (NULL);
    if ((path = malloc(sizeof(moove_t) * (rd.nb + 1))) == NULL)
        return (NULL);
    found_start(&i, &j, tab);
    path[k].moove = 4;
    path[k].corner = assign_moove(j, i, path[k].corner);
    k++;
    1 ? nb[0] = j, nb[1] = i, nb[2] = k, nb[3] = 0 : 0;
    path = follow_path(path, nb, tab);
    path = assign_moovt_path(path);
    free(nb);
    return (path);
}
