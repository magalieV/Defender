/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** Created by remipeyras,
*/

#include "defender.h"
#include "found_menu.h"

void display_render(game_t win, object_t *obj)
{
    sfRenderWindow_display(win.basic.window);
    for (int i = 0; obj[i].sprite; i++)
        sfRenderWindow_drawSprite(win.basic.window, obj[i].sprite, NULL);
}

object_t *open_back(game_t window, object_t *menu_font, sfClock *clock,
    bool bolean)
{
    sfVector2f new_pos[2] = {0};

    if (bolean == true) {
        if (sfMusic_getStatus(window.music.sound[1]) == 0)
            sfMusic_play(window.music.sound[1]);
        new_pos[0] = menu_font[1].vectf;
        new_pos[1] = menu_font[2].vectf;
        new_pos[0].x -= 10;
        new_pos[1].x += 10;
        sfSprite_setPosition(menu_font[1].sprite, new_pos[0]);
        menu_font[1].vectf = new_pos[0];
        sfSprite_setPosition(menu_font[2].sprite, new_pos[1]);
        menu_font[2].vectf = new_pos[1];
        sfClock_restart(clock);
    }
    return (menu_font);
}

object_t *close_back(game_t window, object_t *menu_font, sfClock *clock,
    bool bol)
{
    sfVector2f new_pos[2] = {0};

    if (bol == true) {
        if (sfMusic_getStatus(window.music.sound[1]) == 0)
            sfMusic_play(window.music.sound[1]);
        new_pos[0] = menu_font[1].vectf;
        new_pos[1] = menu_font[2].vectf;
        new_pos[0].x += 10;
        new_pos[1].x -= 10;
        sfSprite_setPosition(menu_font[1].sprite, new_pos[0]);
        menu_font[1].vectf = new_pos[0];
        sfSprite_setPosition(menu_font[2].sprite, new_pos[1]);
        menu_font[2].vectf = new_pos[1];
        sfClock_restart(clock);
    }
    return (menu_font);
}

int found_menu_ad(game_t window, int level)
{
    bool k = sfRenderWindow_isOpen(window.basic.window);

    if (k == 0)
        return (-1);
    for (int i = 0; SEPARATION_TAB[i].sort; i++) {
        if (SEPARATION_TAB[i].number == level) {
            level = SEPARATION_TAB[i].sort(&window);
            if (level == -1)
                return (-1);
            if (level == 84)
                return (84);
            i = -1;
        }
    }
    return (-1);
}
