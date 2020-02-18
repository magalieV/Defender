/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** Created by remipeyras,
*/

#include "defender.h"

int set_option(game_t *win)
{
    char **tab = read_file("res/file/button_option.txt");
    char **r_anim = read_file("res/file/tuto_anim.txt");
    char **r_txt = read_file("res/file/option_text.txt");

    win->butt = create_my_button(tab, win->butt);
    if (win->butt->end == true || !tab)
        return (84);
    if (set_text(r_txt, &win->text) == -1 || !r_txt)
        return (84);
    if (set_anim(r_anim, &win->anim) == -1 || !r_anim)
        return (84);
    (*win).obj[2].vectf.x = 1920;
    sfSprite_setPosition(win->obj[2].sprite, win->obj[2].vectf);
    (*win).obj[1].vectf.x = -960;
    sfSprite_setPosition(win->obj[1].sprite, win->obj[1].vectf);
    return (0);
}

void draw_set_option(game_t *win, sfText ***import)
{
    sfText **vol = *import;
    char *mus = my_itoa((int)win->music.mus_vol);
    char *sound = my_itoa((int)win->music.snd_vol);

    sfText_setString(vol[0], mus);
    sfText_setString(vol[1], sound);
    draw_anim(&win->anim, win->basic.window);
    display_button(*win, win->butt);
    draw_txt(win->text, win->basic.window);
    for (int n = 0; vol[n]; n++)
        sfRenderWindow_drawText(win->basic.window, vol[n], NULL);
    free(sound);
    free(mus);
}

int draw_option(game_t *w, sfText **vol)
{
    bool bl = 0;
    int bol[2] = {0};
    sfClock *clock = sfClock_create();
    sfTime time;
    sfEvent event;

    while (sfRenderWindow_isOpen(w->basic.window)) {
        display_render(*w, w->obj);
        bl == false ? draw_set_option(w, &vol) : 0;
        time = sfClock_getElapsedTime(clock);
        time.microseconds / 1000000.0 >= 0.005 ?
        w->obj = close_back(*w, w->obj, clock, bl) : 0;
        if (w->obj[2].vectf.x == 960)
            break;
        bl = ((bol[0] = option_event(w, &event)) <= 0) ? true : bl;
        bol[1] = bol[0] != 0 ? bol[0] : bol[1];
    }
    sfClock_destroy(clock);
    return (bol[1] == 1 ? 0 : bol[1]);
}

void destroy_option(game_t win)
{
    destroy_txt(win.text);
    destroy_anim(win.anim);
    destroy_my_button(win.butt);
}
