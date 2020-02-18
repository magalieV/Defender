/*
** EPITECH PROJECT, 2018
** defender_reset
** File description:
** transform int to str
*/

#include "defender.h"

static char *my_revstr(char *str, int len)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) * (len + 1));

    if (str == NULL)
        return (NULL);
    if (str[i] == '-') {
        temp[i] = '-';
        i++;
        j++;
    }
    for (; str[i]; i++)
        temp[i] = str[i];
    temp[i] = 0;
    i--;
    for (; temp[j]; j++, i--)
        str[j] = temp[i];
    free(temp);
    return (str);
}

static int digits(int nb)
{
    int n = 0;

    if (nb == 0)
        return (1);
    if (nb < 0)
        nb *= -1;
    while (nb > 0) {
        n++;
        nb /= 10;
    }
    return (n);
}

char *my_itoa(int nb)
{
    int nb_digits = digits(nb);
    char *str = malloc(sizeof(char) * (nb_digits + 2));
    int i = 0;

    if (nb < 0) {
        str[i] = '-';
        i++;
        nb *= -1;
    }
    if (nb == 0) {
        str[0] = '0';
        str[1] = 0;
        return (str);
    }
    while (nb > 0) {
        str[i] = (nb % 10 + '0');
        nb /= 10;
        i++;
    }
    str[i] = 0;
    return (my_revstr(str, my_strlen(str)));
}
