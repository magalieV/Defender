/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"
#include "menu_play.h"

int f_pro(game_t game, int event)
{
    return (-1);
}

int infi_game(game_t game, int bol)
{
    event_game_t event = {0};

    event.nb_mob = 30;
    ini_back_game(game, event);
}

int lvl(game_t game, int bol)
{
    event_game_t event = {0};

    event.nb_mob = (bol - 2) * 20;
    ini_back_game(game, event);
}

int use_event(int event, game_t window)
{
    if (event == -1)
        return (-1);
    for (int i = 0; SEPARATION_MEN[i].sort; i++)
        if (SEPARATION_MEN[i].event == event)
            return (SEPARATION_MEN[i].sort(window, event));
}

int play_menu(game_t *window)
{
    char **tab = read_doub_file("res/file/play.txt");
    my_button_t *button = create_my_button(tab, button);
    sfVector2f vect = {0};
    object_t font = {0};
    int k = 0;
    char **txt = read_doub_file("res/file/text_play.txt");

    if (!txt || (create_text(txt, &(*window).text) == 84) ||
    create_object("res/menu/font.jpg", 0, vect, &font) == -1)
        return (84);
    while (sfRenderWindow_isOpen(window->basic.window)) {
        sfRenderWindow_display(window->basic.window);
        sfRenderWindow_drawSprite(window->basic.window, font.sprite, NULL);
        display_button(*window, button);
        draw_txt((*window).text, (*window).basic.window);
        if ((k = get_event_menu(*window, button)) != 0)
            break;
    }
    (*window).bol = 1;
    display_molten((*window), font, NULL, 0);
    return (use_event(k, (*window)));
}
