/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

sfText *text_create(char const *path, int x, int y, sfFont *font)
{
    sfText *text = {0};
    sfVector2f pos = {0};

    pos.x = x;
    pos.y = y;
    text = sfText_create();
    sfText_setString(text, path);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 80);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    return (text);
}

sfText *text_creation(char **tab, int i, sfColor color, sfVector2f pos)
{
    sfText *text = {0};
    sfFont *font = sfFont_createFromFile(tab[2]);

    text = sfText_create();
    if (!font || !text)
        return (NULL);
    sfText_setString(text, tab[i]);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, my_getnbr(tab[1]));
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    return (text);
}

int create_text(char **tab, text_t *text)
{
    int nb = my_getnbr(tab[0]);
    sfVector2f pos = {0};
    sfText *end = {0};
    int i = 0;
    int k = 0;
    sfColor color = {0};

    (*text).text = malloc(sizeof(sfText *) * (nb + 1));
    if (!(*text).text || nb <= 0)
        return (84);
    for (i = 3; tab[i]; i++) {
        1 ? pos.x = my_getnbr(tab[i + 1]), pos.y = my_getnbr(tab[i + 2]) : 0;
        color = sfColor_fromRGB(my_getnbr(tab[i + 3]), my_getnbr(tab[i + 4]),
        my_getnbr(tab[i + 5]));
        (*text).text[k++] = text_creation(tab, i, color, pos);
        if (!(*text).text[k - 1])
            return (84);
        i += 5;
    }
    (*text).text[k] = end;
    return (0);
}
