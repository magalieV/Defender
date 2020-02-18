/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

char **read_doub_file(char const *str)
{
    char *tmp = NULL;
    char **button = NULL;

    if (!str)
        return (NULL);
    tmp = my_read_file(str);
    if (tmp == NULL)
        return (NULL);
    button = my_str_to_word_array(tmp);
    free(tmp);
    return (button);
}

char *strcat_mall(char const *dest, char const *cpy)
{
    int size_dest = 0;
    int size_cpy = 0;
    char *new = NULL;
    int k = 0;

    if (dest)
        for (size_dest = 0; dest[size_dest]; size_dest++);
    if (cpy)
        for (size_cpy = 0; cpy[size_cpy]; size_cpy++);
    new = malloc(sizeof(char) * (size_cpy + size_dest + 2));
    if (dest) {
        for (int i = 0; dest[i]; i++)
            new[k++] = dest[i];
    }
    for (int j = 0; cpy[j]; j++)
        new[k++] = cpy[j];
    new[k++] = '\n';
    new[k] = '\0';
    return (new);
}

char *my_read_file(char const *str)
{
    char *tmp = NULL;
    char *fin = NULL;
    int op = 0;

    op = open(str, O_RDONLY);
    if (op == -1)
        return (NULL);
    while (tmp = get_next_line(op)) {
        fin = strcat_mall(fin, tmp);
        free(tmp);
    }
    close(op);
    return (fin);
}

int found_cara(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

int alloc_place_board(object_t **place, read_t *read, char *c)
{
    char **tab = NULL;
    int test = 0;
    sfVector2f end = {0};

    tab = read_doub_file("src/game/board.txt");
    for (int i = 0; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++)
            (*read).nb += (found_cara(c, tab[i][j])) ? 1 : 0;
    if (read->nb <= 0)
        return (-1);
    (*read).vect = malloc(sizeof(sfVector2f) * ((*read).nb + 1));
    for (int i = 0; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++)
            if (found_cara(c, tab[i][j])) {
                (*read).vect[test].x = j * 180;
                (*read).vect[test].y = i * 180;
                test++;
            }
    (*read).vect[test] = end;
    destroy_doub_tab(tab);
    return (0);
}
