/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

bool pause_loop(game_t window, my_button_t *button, int *bol)
{
    while (sfRenderWindow_pollEvent(window.basic.window, &window.event)) {
        if (window.event.type == sfEvtClosed) {
            sfRenderWindow_close(window.basic.window);
            return (false);
        } else if (window.event.type == sfEvtKeyPressed
            && window.event.key.code == sfKeyEscape)
            return (false);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            *bol = check_button(button, window.basic.window);
            if (*bol == -1)
                return (false);
            }
        }
    return (true);
}

void draw_menu_pause(game_t *win, object_t font, my_button_t *button,
    text_t my_txt)
{
    sfRenderWindow_display((*win).basic.window);
    draw_load((*win), font, NULL);
    display_button((*win), button);
    draw_txt(my_txt, (*win).basic.window);
}

void display_pause_menu(game_t *win, event_game_t *event, object_t font,
    my_button_t *button)
{
    bool bol = false;
    char **txt = NULL;
    text_t my_txt = {0};
    int is_button = 0;

    if ((*win).event.type == sfEvtKeyPressed
        && (*win).event.key.code == sfKeyEscape) {
        1 ? txt = read_doub_file("res/file/text_pause.txt"), bol = true : 0;
        if (create_text(txt, &my_txt) == 84)
            return;
    }
    (*win).wind.color.a = 200;
    while (bol) {
        draw_menu_pause(win, font, button, my_txt);
        bol = pause_loop((*win), button, &is_button);
        if (is_button == 1) {
            option(win);
            return;
        } else if (is_button == 2)
            return;
    }
}
