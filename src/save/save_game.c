/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

void draw_info_boucle(int i, sfRenderWindow *win, transport_s tran)
{
    for (int n = 0; tran.selection[i].obj[n].sprite; n++)
        sfRenderWindow_drawSprite(win, tran.selection[i].obj[n].sprite, NULL);
    draw_txt(tran.selection[i].text, win);
}

void draw_info(game_t win, transport_s tran)
{
    sfVector2i new = check_pos_mouse(win.basic.window);

    for (int i = 0; i < 11; i++) {
        if (sfIntRect_contains(&tran.button[i].rect, new.x, new.y) == true) {
            if (tran.selection[i].obj)
                draw_info_boucle(i, win.basic.window, tran);
        }
    }
}

void build_draw_assit(game_t win, transport_s tran, int k)
{
    display_render(win, win.obj);
    sfRenderWindow_drawSprite(win.basic.window, tran.back.sprite, NULL);
    display_button(win, tran.button);
    for (int n = 0; tran.info[n].sprite; n++)
        sfRenderWindow_drawSprite(win.basic.window, tran.info[n].sprite, NULL);
    draw_txt(tran.name, win.basic.window);
}

int option_build(game_t win, sfEvent *event, transport_s tran)
{
    int k = 0;

    if (sfRenderWindow_pollEvent(win.basic.window, event)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            k = check_button(tran.button, win.basic.window);
            return (k == 1 || k == 11 ? -1 : k);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return (0);
    }
}

int draw_test_building(game_t window, transport_s trans)
{
    bool bl = 0;
    int bol[2] = {0};
    sfClock *clock = sfClock_create();
    sfTime time;
    sfEvent event;

    while (sfRenderWindow_isOpen(window.basic.window)) {
        bl == false ? build_draw_assit(window, trans, 0) : 0;
        time = sfClock_getElapsedTime(clock);
        time.microseconds / 1000000.0 >= 0.005 ? window.obj = close_back(window,
            window.obj, clock, bl) : 0;
        if (window.obj[2].vectf.x == 960)
            break;
        bl = ((bol[0] = option_build(window, &event, trans)) < 0) ? true : bl;
        bl == false ? draw_info(window, trans) : 0;
        bol[1] = bol[0] < 0 ? bol[0] : bol[1];
    }
    sfClock_destroy(clock);
    return (bol[1]);
}