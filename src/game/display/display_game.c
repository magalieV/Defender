/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

void draw_all_anim(game_t window, link_t *link, link_t *monster, sfClock *cl)
{
    draw_fire(link, window);
    draw_monster(monster, window, cl);
}

void display_element(game_t window, my_button_t **button, object_t *castle,
    event_game_t my_event)
{
    display_button(window, button[1]);
    display_button(window, button[2]);
    display_button(window, button[0]);
    sfRenderWindow_drawSprite(window.basic.window,
        castle[my_event.castle].sprite, NULL);
}

void display_text(game_t window, event_game_t *event, sfClock *score,
    node_t *node)
{
    sfVector2f pos = {1550, 950};

    print_tower(node, window);
    up_score(score, event, window);
    put_nb_on_screen(event->money, window, pos, 0);
    win_money(event);
}

void print_tower(node_t *node, game_t window)
{
    int i = 0;

    while (node && node->prev)
        node = node->prev;
    while (node && node->next != NULL) {
        sfRenderWindow_drawSprite(window.basic.window,
            node->object.sprite, NULL);
        node = node->next;
    }
    if (node) {
        sfRenderWindow_drawSprite(window.basic.window,
            node->object.sprite, NULL);
    }
}

void display_object_after_mouse(event_game_t *my_event, game_t window,
    object_t **essaie, sfClock *cl)
{
    static int boll = 0;

    if ((*my_event).bol > 0 || (*my_event).bol == -1 || (*my_event).fire != 0)
        boll = (*my_event).fire != 0 ? 4 : (*my_event).bol;
    if (boll > 0)
        what_tower(boll, essaie[2], window, cl);
    use_button(window, my_event);
}
