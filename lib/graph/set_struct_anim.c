/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** file for create struct anim
*/

#include "defender.h"

sfIntRect set_int_rect(int left, int top, int width, int heigh)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = heigh;
    return (rect);
}

int *fill_rect(char **tab, int n)
{
    int *rect = malloc(sizeof(float) * 4);

    rect[0] = my_getnbr(tab[n + 4]);
    rect[1] = my_getnbr(tab[n + 5]);
    rect[2] = my_getnbr(tab[n + 6]);
    rect[3] = my_getnbr(tab[n + 7]);
    return (rect);
}

int set_anim(char **tab, anim_t *anim)
{
    sfVector2f pos;

    pos.x = my_getnbr(tab[1]);
    pos.y = my_getnbr(tab[2]);
    if (create_object(tab[0], 0, pos, &anim->obj) == -1)
        return (-1);
    anim->offset = my_getnbr(tab[3]);
    anim->rect = set_int_rect((int)my_getnbr(tab[4]),
        (int)my_getnbr(tab[5]), (int)my_getnbr(tab[6]), (int)my_getnbr(tab[7]));
    anim->clock = sfClock_create();
    return (0);
}

void draw_anim(anim_t *anim, sfRenderWindow *win)
{
    sfTime time = sfClock_getElapsedTime(anim->clock);
    float second = time.microseconds / 100000.0;

    sfSprite_setTextureRect(anim->obj.sprite, anim->rect);
    sfRenderWindow_drawSprite(win, anim->obj.sprite, NULL);
    if (second > 1.00) {
        anim->rect.left += anim->rect.width;
        if (anim->rect.left == anim->offset)
            anim->rect.left = 0;
        sfClock_restart(anim->clock);
    }
    return;
}

void destroy_anim(anim_t anim)
{
    destroy_object(&anim.obj);
    sfClock_destroy(anim.clock);
}
