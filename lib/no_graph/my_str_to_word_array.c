/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

int if_alphnum(char const *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z')
        return (1);
    else if ((str[i] >= 'A' && str[i] <= 'Z') || str[i] == ' ')
        return (1);
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
        return (1);
    else if (str[i] == '/' || str[i] == '.' || str[i] == '_')
        return (1);
    return (0);
}

int alloc_mem(char const *str)
{
    int i = 0;
    int k = 0;

    while (str[i]) {
        if (if_alphnum(str, i) && !if_alphnum(str, i + 1))
            k++;
        i++;
    }
    return (k);
}

char **my_str_to_word_array(char const *str)
{
    char **dest = NULL;
    int i = 0;
    int g = 0;
    int n = 0;

    dest = malloc(sizeof(char *) * (alloc_mem(str) + 1) + 1);
    while (str[g]) {
        if (!if_alphnum(str, g))
            g++;
        for (n = g; if_alphnum(str, n); n++);
        dest[i] = (char *)malloc((n - g) + 2);
        dest[i][0] = 0;
        for (n = 0; if_alphnum(str, g); n++)
            dest[i][n] = str[g++];
        dest[i][n] = '\0';
        if (dest[i][0])
            i++;
    }
    dest[i] = 0;
    return (dest);
}
