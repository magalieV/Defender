/*
** EPITECH PROJECT, 2018
** my_strdump
** File description:
** export lib, got my_getnbr, my_strlen, my_strcpy, my_strdup, and free tab
*/

#include "my.h"

int my_getnbr(char const *str)
{
    long n = 0;
    int i = 0;
    int neg = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg = neg * (-1);
        i++;
    }
    while ('0' <= str[i] && str[i] <= '9') {
        n *= 10;
        n += str[i] - '0';
        i++;
        if (n > 2147483648)
            return (0);
    }
    n *= neg;
    if (n == 2147483648)
        return (0);
    return (n);
}

int my_strlen(char const *str)
{
    int n = 0;

    if (!str)
        return (0);
    for (; str[n]; n++);
    return (n);
}

static char *my_strcpy(char *dest, char const *src)
{
    int i = -1;

    if (src == NULL)
        return (NULL);
    while (src[++i])
        dest[i] = src[i];
    dest[i] = 0;
    return (dest);
}

char *my_strdup(char const *src)
{
    char *tmp = malloc(sizeof(char) * my_strlen(src) + 1);

    if (!src)
        return (NULL);
    tmp = my_strcpy(tmp, src);
    return (tmp);
}

void free_tab(char **t1, char **t2)
{
    if (t1) {
        for (int i = 0; t1[i]; i++)
            free(t1[i]);
        free(t1);
    }
    if (t2) {
        for (int i = 0; t2[i]; i++)
            free(t2[i]);
        free(t2);
    }
}
