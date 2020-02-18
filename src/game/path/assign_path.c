/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

moove_t *follow_path(moove_t *path, int *tb, char **map)
{
    bool end = false;
    int x = 0;
    int y = 0;
    sfVector2f pos = {0};
    moove_t tmp = {0};
    int *nb = malloc(sizeof(int) * (5));

    1 ? x = tb[0], y = tb[1] : 0;
    while (end == false) {
        1 ? nb[0] = tb[0], nb[1] = tb[1], nb[2] = x, nb[3] = y, nb[4] = 0 : 0;
        pos = found_pos_path(map, nb, &end);
        if (end)
            break;
        path[tb[2]].moove = 4;
        path[tb[2]].corner = assign_moove(pos.x, pos.y, path[tb[2]].corner);
        tb[0] = pos.x, tb[1] = pos.y;
        x = path[tb[2] - 1].corner.left / 180;
        1 ? y = path[tb[2] - 1].corner.width / 180, tb[2]++ : 0;
    }
    1 ? path[tb[2]] = tmp, free(nb) : 0;
    return (path);
}

int verify_end(char **map, int x, int y)
{
    int tab[8] = {1, 0, 0, 1, -1, 0, 0, -1};
    int bol = 0;
    sfVector2f pos = {0};

    if (map[y][x] == 'S')
        return (0);
    for (int i = 0; i < 8; i++) {
        pos.x = x + tab[i];
        pos.y = y + tab[i + 1];
        if (map[(int)(pos.y)] && map[(int)(pos.y)][(int)(pos.x)]
        && map[(int)(pos.y)][(int)(pos.x)] == 'E')
            return (1);
        if (map[(int)(pos.y)] && map[(int)(pos.y)][(int)(pos.x)]
        && map[(int)(pos.y)][(int)(pos.x)] == '2')
            bol++;
        else if (map[(int)(pos.y)] && map[(int)(pos.y)][(int)(pos.x)]
        && map[(int)(pos.y)][(int)(pos.x)] == 'S')
            bol++;
        i++;
    }
    return (bol == 1 ? 1 : 0);
}

moove_t *assign_moovt_path(moove_t *path)
{
    int x = 0;
    int y = 0;

    for (int i = 1; path[i].moove; i++) {
        if (path[i + 1].moove) {
            x = path[i + 1].corner.left;
            y = path[i + 1].corner.width;
            path[i].bol = 0;
            path[i].moove = found_moove(path[i].corner.left,
                path[i].corner.width, x, y);
        } else {
            path[i].moove = path[i - 1].moove;
            path[i].bol = 1;
        }
    }
    return (path);
}
