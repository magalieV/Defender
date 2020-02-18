/*
** EPITECH PROJECT, 2018
** defender_reset
** File description:
** create read file who cat str, and pass it to tab, free set if needed
*/

#include "defender.h"

int free_set(char **tab, int leave)
{
    if (tab)
        free_tab(tab, NULL);
    return (leave);
}

static char *strcat_mall(char const *dest, char const *cpy)
{
    int size_dest = 0;
    int size_cpy = 0;
    char *cat = NULL;
    int k = 0;

    if (dest)
        for (; dest[size_dest]; size_dest++);
    if (cpy)
        for (; cpy[size_cpy]; size_cpy++);
    cat = malloc(sizeof(char) * (size_cpy + size_dest + 2));
    if (dest) {
        for (int i = 0; dest[i]; i++)
            cat[k++] = dest[i];
    }
    for (int j = 0; cpy[j]; j++)
        cat[k++] = cpy[j];
    cat[k++] = ':';
    cat[k] = 0;
    return (cat);
}

static char **read_file_to_tab(char *str, int fd, char **tab)
{
    tab = str_to_tab(str);
    free(str);
    close(fd);
    return (tab);
}

char *clean_end(char *str)
{
    for (int n = 0; str[n]; n++)
        if (str[n] == ':' && str[n + 1] == 0)
            str[n] = 0;
    return (str);
}

char **read_file(char const *path)
{
    char *tmp = NULL;
    char *end = NULL;
    int fd = open(path, O_RDONLY);
    char **tab = NULL;

    if (fd == -1)
        return (NULL);
    tmp = gnl(fd);
    if (!tmp)
        return (NULL);
    while (tmp) {
        end = strcat_mall(end, tmp);
        free(tmp);
        tmp = gnl(fd);
    }
    end = clean_end(end);
    tab = read_file_to_tab(end, fd, tab);
    return (tab);
}
