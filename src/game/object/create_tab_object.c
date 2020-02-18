/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

my_button_t *create_button_tab(char *path, char *path2, read_t read,
    sfVector2f size)
{
    char **tab = NULL;
    int i = 0;
    int k = 0;
    my_button_t *butt = NULL;

    if ((tab = malloc(sizeof(char *) * (read.nb * 7 + 2))) == NULL)
        return (NULL);
    tab[i] = nb_to_string(read.nb, tab[i], 0);
    for (i = 1; i < read.nb * 7 + 1; i++) {
        tab[i] = path;
        tab[i + 1] = path2;
        tab[i + 2] = path2;
        tab[i + 3] = nb_to_string(read.vect[k].x, tab[i + 2], 0);
        tab[i + 4] = nb_to_string(read.vect[k].y, tab[i + 3], 0);
        tab[i + 5] = nb_to_string(size.x, tab[i + 4], 0);
        tab[i + 6] = nb_to_string(size.y, tab[i + 5], 0);
        k++;
        i += 6;
    }
    tab[i] = 0;
    return (create_my_button(tab, butt));
}

object_t **tab_game(object_t **picture, char **tab, game_t *wd)
{
    int a = 0;

    picture = on_tab(picture, tab, &a);
    picture[a] = create_place_object(picture[a], "res/game/Place.png", "1", wd);
    picture[++a] = malloc(sizeof(object_t) * (wd->read.nb + 1));
    picture[a] = 0;
    return (picture);
}

object_t **on_tab(object_t **picture, char **tab, int *z)
{
    sfVector2f ps = {0};
    object_t end = {0};
    int b = 0;
    int nb[2] = {0};

    if (!tab)
        return (NULL);
    picture = malloc(sizeof(object_t *) * (my_getnbr(tab[0]) + 1));
    for (int k = 1; tab[k]; k++) {
        nb[0] = my_getnbr(tab[k++]);
        picture[nb[1]] = malloc(sizeof(object_t) * (nb[0] + 1));
        for (b = 0; b < nb[0]; b++) {
            1 ? ps.x = my_getnbr(tab[k + 1]), ps.y = my_getnbr(tab[k + 2]) : 0;
            1 ? create_object(tab[k], 0, ps, &picture[nb[1]][b]), k += 3 : 0;
        }
        k -= 1;
        picture[nb[1]][b] = end;
        nb[1] += 1;
    }
    picture[nb[1]] = 0;
    return (*z = nb[1], picture);
}
