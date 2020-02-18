/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** Created by remipeyras,
*/

#include "defender.h"

music_t *check_volum(music_t *music)
{
    if (music->mus_vol <= 0)
        music->mus_vol = 0;
    else if (music->mus_vol >= 100)
        music->mus_vol = 100;
    if (music->snd_vol <= 0)
        music->snd_vol = 0;
    else if (music->snd_vol >= 100)
        music->snd_vol = 100;
    return (music);
}

int button_click(music_t *music, int k)
{
    k == 2 ? music->mus_vol -= 2.5 : 0;
    k == 4 ? music->mus_vol += 2.5 : 0;
    k == 5 ? music->snd_vol -= 2.5 : 0;
    k == 7 ? music->snd_vol += 2.5 : 0;
    music = check_volum(music);
    set_volume(music);
    if (k == 1)
        return (0);
    else if (k == -1)
        return (-1);
    else
        return (1);
}

int check_key(game_t *win, my_button_t *butt)
{
    sfVector2i new = check_pos_mouse(win->basic.window);

    if (sfIntRect_contains(&butt[2].rect, new.x, new.y) == true) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            return (2);
        else if (sfKeyboard_isKeyPressed(sfKeyRight))
            return (4);
    }
    if (sfIntRect_contains(&butt[5].rect, new.x, new.y) == true
    && sfKeyboard_isKeyPressed(sfKeyLeft)) {
        return (5);
    } else if (sfIntRect_contains(&butt[5].rect, new.x, new.y) == true
    && sfKeyboard_isKeyPressed(sfKeyRight)) {
        return (7);
    }
    return (-2);
}

int option_event(game_t *win, sfEvent *event)
{
    int k = 0;

    if (sfRenderWindow_pollEvent(win->basic.window, event)) {
        if (event->type == sfEvtClosed) {
            sfRenderWindow_close(win->basic.window);
            return (-1);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            k = check_button(win->butt, win->basic.window);
            return (button_click(&win->music, k));
        }
        if (sfKeyboard_isKeyPressed(sfKeyRight)
        || sfKeyboard_isKeyPressed(sfKeyLeft)) {
            k = check_key(win, win->butt);
            return (button_click(&win->music, k));
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return (0);
    }
    return (1);
}
