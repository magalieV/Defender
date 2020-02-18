/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

void draw_but_txt_anim(game_t window, my_button_t *but, anim_t *anim)
{
    display_button(window, but);
    draw_txt(window.text, window.basic.window);
    draw_anim(anim, window.basic.window);
}

void destroy_inter(my_button_t *butt, anim_t anim, text_t text)
{
    destroy_my_button(butt);
    destroy_txt(text);
    destroy_anim(anim);
}

int display_function(game_t win, object_t *obj, anim_t anim, my_button_t *butt)
{
    sfTime time;
    int bol[2] = {0};
    bool bl = 0;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(win.basic.window)) {
        display_render(win, obj);
        time = sfClock_getElapsedTime(clock);
        time.microseconds / 1000000.0 >= 0.005 ?
        obj = open_back(win, obj, clock, bl) : 0;
        bl == false ? draw_but_txt_anim(win, butt, &anim) : 0;
        bl = obj[2].vectf.x >= 1920 ? false : bl;
        if (obj[2].vectf.x >= 1920) {
            destroy_inter(butt, anim, win.text);
            break;
        }
        bl = ((bol[0] = get_event_menu(win, butt)) != 0) ? true : bl;
        bol[1] = bol[0] != 0 ? bol[0] : bol[1];
    }
    return (bol[1]);
}

int display_menu(game_t *window)
{
    sfClock *clock = sfClock_create();
    char **tab = read_doub_file("res/file/button.txt");
    char **r_anim = read_file("res/file/menu_anim.txt");
    char **r_txt = read_file("res/file/menu_text.txt");
    my_button_t *butt = create_my_button(tab, butt);
    anim_t anim = {0};
    text_t text = {0};
    int bol = 0;

    if (butt->end == true || !tab)
        return (84);
    if (set_text(r_txt, &text) == -1 || !r_txt)
        return (84);
    if (set_anim(r_anim, &anim) == -1 || !r_anim)
        return (84);
    window->text = text;
    bol = display_function(*window, window->obj, anim, butt);
    return (bol);
}
