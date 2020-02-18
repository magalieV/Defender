/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** get_next_line
*/

#include "gnl.h"
#include "my.h"

static char *my_charcat(char *dest, char src)
{
    int len = -1;
    char *result;

    while (dest[++len]);
    result = malloc(len + 2);
    if (!result)
        return (NULL);
    for (int i = 0 ; i <= len ; i++)
        result[i] = dest[i];
    result[len] = src;
    result[len + 1] = '\0';
    free(dest);
    return (result);
}

static char read_input(int fd)
{
    static char buffer[READ_SIZE];
    static int nb_read;
    static int n;

    if (!nb_read && (n = -1) && (nb_read = read(fd, buffer, READ_SIZE)) <= 0)
        return (0);
    nb_read--;
    return (buffer[++n]);
}

char *gnl(int fd)
{
    int i = 0;
    char c;
    char *str = malloc(1);

    if (!(str) || !(c = read_input(fd)) || (!(*str = '\0')
    && !(str = my_charcat(str, c))))
        return (NULL);
    for (;c != '\n' && c; i++)
        if ((c = read_input(fd)) != '\n' && !(str = my_charcat(str, c)))
            return (NULL);
    str[i] = '\0';
    return (str);
}
