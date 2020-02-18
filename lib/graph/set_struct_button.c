/*
** EPITECH PROJECT, 2018
** defender_reset
** File description:
** file for create button
*/

#include "defender.h"

static int assign_rect(char **tab, int i, sfIntRect *rect)
{
    if (!tab[i + 5] || !tab[i + 2] || !tab[i + 3] || !tab[i + 4])
        return (84);
    (*rect).left = my_getnbr(tab[i + 2]);
    (*rect).width = my_getnbr(tab[i + 4]);
    (*rect).top = my_getnbr(tab[i + 3]);
    (*rect).height = my_getnbr(tab[i + 5]);
}

my_button_t *create_my_button(char **tab, my_button_t *button)
{
    sfVector2f vect = {0};
    my_button_t end = {0};
    int i = 0;
    int k = 0;

    button = malloc(sizeof(my_button_t) * (my_getnbr(tab[0]) + 1));
    if (!button)
        return (button->end = true, button);
    for (i = 1; tab[i]; i++) {
        vect.x = my_getnbr(tab[i + 3]);
        vect.y = my_getnbr(tab[i + 4]);
        if (create_object(tab[i], 0, vect, &button[k].butt) == -1
            || create_object(tab[i + 1], 0, vect, &button[k].press) == -1
            || create_object(tab[i + 2], 0, vect, &button[k].hover) == -1
            || assign_rect(tab, i + 1, &button[k].rect) == 84)
                return (button->end = true, button);
        i += 6;
        k++;
    }
    button[k] = end;
    return (button->end = false, button);
}

void display_button(game_t window, my_button_t *butt)
{
    sfVector2i new = {0};

    new = check_pos_mouse(window.basic.window);
    for (int i = 0; butt[i].butt.sprite; i++) {
        if (sfIntRect_contains(&butt[i].rect, new.x, new.y) == false)
            sfRenderWindow_drawSprite(window.basic.window, butt[i].butt.sprite,
                NULL);
        else {
            sfRenderWindow_drawSprite(window.basic.window, butt[i].press.sprite,
                NULL);
            if (sfMusic_getStatus(window.music.sound[0]) == 0)
                sfMusic_play(window.music.sound[0]);
        }
    }
}

void destroy_my_button(my_button_t *button)
{
    for (int i = 0; button[i].rect.top; i++) {
        destroy_object(&button[i].butt);
        destroy_object(&button[i].press);
    }
    free(button);
}
