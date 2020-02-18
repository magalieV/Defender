/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

void display_font_game(object_t **font, int size, int beg, game_t window)
{
    sfRenderWindow_display(window.basic.window);
    sfRenderWindow_drawSprite(window.basic.window, font[0][0].sprite, NULL);
    sfRenderWindow_drawSprite(window.basic.window, font[1][0].sprite, NULL);
}

void display_object(object_t *object, game_t window)
{
    if (!object)
        return;
    for (int i = 0; object[i].sprite; i++)
        sfRenderWindow_drawSprite(window.basic.window, object[i].sprite, NULL);
}

void use_button(game_t window, event_game_t *my_event)
{
    char **tab = read_doub_file("src/game/board.txt");

    if ((*my_event).button == 2) {
        how_to_use(&window);
    }
    if ((*my_event).button == 1)
        test_building(window, my_event);
}

game_play_t init_game_play(game_t window, object_t **picture,
    event_game_t my_event, my_button_t **button)
{
    game_play_t play = {0};

    play.monster = NULL;
    play.node = NULL;
    play.castle = create_castle();
    play.link = NULL;
    play.life = 1000;
    play.mvt = found_path(window.map);
    play.tmp.place = button[0];
    play.tmp.moove = play.mvt;
    play.cl = malloc(sizeof(sfClock *) * (6));
    for (int i = 0; i < 6; i++)
        play.cl[i] = sfClock_create();
    return (play);
}

void display_background(game_t window, object_t **picture,
    event_game_t my_event, my_button_t **button)
{
    game_play_t pl = init_game_play(window, picture, my_event, button);

    while (sfRenderWindow_isOpen(window.basic.window) && pl.mvt != NULL) {
        pl.monster = add_monster(pl.monster, &my_event, window, pl);
        display_font_game(picture, 3, 3, window);
        display_element(window, button, pl.castle, my_event);
        draw_all_anim(window, pl.link, pl.monster, pl.cl[5]);
        display_text(window, &my_event, pl.cl[0], pl.node);
        event_to_quit_game(&window, &my_event, button, picture[0][0]);
        display_object_after_mouse(&my_event, window, picture, pl.cl[4]);
        pl.node = create_tower(pl.node, &my_event, pl.tmp, window.tower);
        pl.link = create_link(pl.link, &my_event, window, button[1]);
        pl.mvt = place_fire_path(pl.link, pl.mvt);
        pl.monster = moove_monster(pl.monster, window.map, pl.mvt, pl.cl[3]);
        display_attaque(pl.node, window, pl.cl[2]);
        is_monster_touch(pl.monster, pl.node);
        if (castle_dead(&pl.life, pl.mvt, pl.monster) ||
        all_monster_died(pl.monster, my_event))
            break;
    }
    pl.mvt != NULL ? display_end(pl.life, window, picture[0][0]) : 0;
}
