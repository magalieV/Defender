/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** Created by remipeyras,
*/

#include "defender.h"

int set_credit(game_t *win, object_t *obj)
{
    char **tab = read_file("res/file/credit_button.txt");
    char **r_txt = read_file("res/file/credit_text.txt");

    win->butt = create_my_button(tab, win->butt);
    if (win->butt->end == true || !tab)
        return (84);
    if (set_text(r_txt, &win->text) == -1 || !r_txt)
        return (84);
    if (create_object("res/credit_back.png", 0, (sfVector2f)
        {50, 250}, obj) == -1)
        return (84);
    return (0);
}

void draw_set_credit(game_t *win, object_t *obj)
{
    sfRenderWindow_drawSprite(win->basic.window, obj->sprite, NULL);
    display_button(*win, win->butt);
    draw_txt(win->text, win->basic.window);
}

int draw_credit(game_t *win, object_t *obj)
{
    bool bl = 0;
    int bol[2] = {0};
    sfClock *clock = sfClock_create();
    sfTime time;
    sfEvent event;

    while (sfRenderWindow_isOpen(win->basic.window)) {
        display_render(*win, win->obj);
        bl == false ? draw_set_credit(win, obj) : 0;
        time = sfClock_getElapsedTime(clock);
        time.microseconds / 1000000.0 >= 0.005 ?
        win->obj = close_back(*win, win->obj, clock, bl) : 0;
        if (win->obj[2].vectf.x == 960)
            break;
        bl = ((bol[0] = tuto_event(win, &event)) != 0) ? true : bl;
        bol[1] = bol[0] != 0 ? bol[0] : bol[1];
    }
    sfClock_destroy(clock);
    return (bol[1] == 1 ? 0 : bol[1]);
}

void destroy_credit(game_t *win)
{
    destroy_txt(win->text);
    destroy_my_button(win->butt);
}
