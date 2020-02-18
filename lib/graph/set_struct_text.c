/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** Created by remipeyras,
*/

#include "defender.h"

static void assign_txt(sfText **text, int size, sfVector2f pos, sfFont *font)
{
    sfColor C2 = sfColor_fromRGB(40, 3, 23);

    *text = sfText_create();
    sfText_setFont(*text, font);
    sfText_setCharacterSize(*text, size);
    sfText_setPosition(*text, pos);
    sfText_setColor(*text, C2);
}

static sfVector2f set_pos(char *x, char *y)
{
    sfVector2f pos = {0};

    pos.x = (float)my_getnbr(x);
    pos.y = (float)my_getnbr(y);
    return (pos);
}

int set_text(char **tab, text_t *txt)
{
    int nb = my_getnbr(tab[0]);
    int sz = my_getnbr(tab[1]);
    int k = 0;
    sfVector2f pos = {0};
    bool bol = false;

    if (!(txt->font = sfFont_createFromFile(tab[2])))
        return (-1);
    if (!(txt->text = malloc(sizeof(sfText *) * (nb + 1))))
        return (-1);
    for (int n = 3; tab[n]; n += 3, k++) {
        pos = set_pos(tab[n + 1], tab[n + 2]);
        sz = tab[n + 6] == NULL && sz == my_getnbr(tab[1]) ? sz * 3 : sz;
        assign_txt(&txt->text[k], sz, pos, txt->font);
        sfText_setString(txt->text[k], tab[n]);
    }
    txt->text[nb] = NULL;
    sfText_setColor(txt->text[nb - 1], sfWhite);
    sfText_setColor(txt->text[nb - 2], sfWhite);
    free_tab(tab, NULL);
    return (0);
}

void draw_txt(text_t txt, sfRenderWindow *win)
{
    for (int n = 0; txt.text[n]; n++)
        sfRenderWindow_drawText(win, txt.text[n], NULL);
}

void destroy_txt(text_t txt)
{
    for (int n = 0; txt.text[n]; n++)
        sfText_destroy(txt.text[n]);
    free(txt.text);
    sfFont_destroy(txt.font);
}