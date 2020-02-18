/*
** EPITECH PROJECT, 2018
** defender_reset
** File description:
** str to tab function
*/

#include "defender.h"

void my_put_error(char const *str)
{
    write(2, str, my_strlen(str));
}

static int count_word(char const *str)
{
    int n = 0;

    for (int m = 0; str[m]; m++)
        if (str[m] == ':' || (7 <= str[m] && str[m] <= 13))
            n++;
    n++;
    return (n);
}

static char **remove_separator(char **tab)
{
    for (int n = 0; tab[n]; n++)
        for (int m = 0; tab[n][m]; m++)
            if (tab[n][m] == ':' || (7 <= tab[n][m] && tab[n][m] <= 13))
                tab[n][m] = 0;
    return (tab);
}

char **str_to_tab(char const *str)
{
    int nb_word = count_word(str);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int n = 1;

    tab[0] = NULL;
    while (*str) {
        if (!tab[0])
            tab[0] = my_strdup(str);
        if (*str == ':' || (7 <= *str && *str <= 13)) {
            tab[n] = my_strdup(++str);
            n++;
        }
        ++str;
    }
    tab[nb_word] = NULL;
    tab = remove_separator(tab);
    return (tab);
}
