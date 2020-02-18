/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** Created by remipeyras,
*/

#include "defender.h"

void draw_back_anim(anim_t *, sfRenderWindow *);

int set_tuto(game_t *win)
{
    char **tab = read_file("res/file/button_tuto.txt");
    char **r_anim = read_file("res/file/tuto_anim.txt");
    char **r_txt = read_file("res/file/tuto_text.txt");

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

void draw_set_tuto(game_t *win, anim_t *anim)
{
    draw_back_anim(anim, win->basic.window);
    draw_anim(&win->anim, win->basic.window);
    display_button(*win, win->butt);
    draw_txt(win->text, win->basic.window);
}

int tuto_event(game_t *win, sfEvent *event)
{
    int k = 0;

    if (sfRenderWindow_pollEvent(win->basic.window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(win->basic.window);
            return (-1);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            k = check_button(win->butt, win->basic.window);
            return (k == -1 ? -1 : 1);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return (0);
    }
}

int draw_tuto(game_t *w, anim_t anim)
{
    bool bl = 0;
    int bol[2] = {0};
    sfClock *clock = sfClock_create();
    sfTime time;
    sfEvent event;

    while (sfRenderWindow_isOpen(w->basic.window)) {
        display_render(*w, w->obj);
        bl == false ? draw_set_tuto(w, &anim) : 0;
        time = sfClock_getElapsedTime(clock);
        time.microseconds / 1000000.0 >= 0.005 ?
        w->obj = close_back(*w, w->obj, clock, bl) : 0;
        if (w->obj[2].vectf.x == 960)
            break;
        bl = ((bol[0] = tuto_event(w, &event)) != 0) ? true : bl;
        bol[1] = bol[0] != 0 ? bol[0] : bol[1];
    }
    sfClock_destroy(clock);
    return (bol[1] == 1 ? 0 : bol[1]);
}

void destroy_tuto(game_t win)
{
    destroy_txt(win.text);
    destroy_anim(win.anim);
    destroy_my_button(win.butt);
}
