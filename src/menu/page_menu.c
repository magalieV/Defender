/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

void draw_back_anim(anim_t *anim, sfRenderWindow *win)
{
    sfTime time = sfClock_getElapsedTime(anim->clock);
    float second = time.microseconds / 100000.0;

    sfSprite_setTextureRect(anim->obj.sprite, anim->rect);
    sfRenderWindow_drawSprite(win, anim->obj.sprite, NULL);
    if (second > 25.00) {
        anim->rect.left += anim->rect.width;
        if (anim->rect.left == anim->offset)
            anim->rect.left = 0;
        sfClock_restart(anim->clock);
    }
    return;
}

int how_to_use(game_t *win)
{
    char **tab = read_file("res/file/back_tuto.txt");
    int ret = 0;
    anim_t anim;

    if (set_tuto(win) == 84)
        return (84);
    if (set_anim(tab, &anim) == -1)
        return (84);
    ret = draw_tuto(win, anim);
    destroy_tuto(*win);
    destroy_anim(anim);
    return (ret);
}

sfText **create_sound(sfText **vol, sfFont *font)
{
    sfColor C2 = sfColor_fromRGB(40, 3, 23);

    if (!(vol = malloc(sizeof(sfText *) * (3))))
        return (NULL);
    vol[0] = sfText_create();
    vol[1] = sfText_create();
    sfText_setFont(vol[0], font);
    sfText_setFont(vol[1], font);
    sfText_setCharacterSize(vol[0], 65);
    sfText_setCharacterSize(vol[1], 65);
    sfText_setPosition(vol[0], (sfVector2f){930, 390});
    sfText_setPosition(vol[1], (sfVector2f){930, 590});
    sfText_setColor(vol[0], C2);
    sfText_setColor(vol[1], C2);
    vol[2] = NULL;
    return (vol);
}

int option(game_t *win)
{
    int ret = 0;
    sfFont *font = sfFont_createFromFile("res/text_font.ttf");
    sfText **vol = create_sound(vol, font);

    if (set_option(win) == 84)
        return (84);
    if (!vol)
        return (84);
    ret = draw_option(win, vol);
    destroy_option(*win);
    sfFont_destroy(font);
    sfText_destroy(vol[0]);
    sfText_destroy(vol[1]);
    return (ret);
}

int credit(game_t *win)
{
    int ret = 0;
    object_t obj = {0};

    if (set_credit(win, &obj) == 84)
        return (84);
    ret = draw_credit(win, &obj);
    destroy_object(&obj);
    destroy_credit(win);
    return (ret);
}
