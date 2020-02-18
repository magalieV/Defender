/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

char **create_tab_fire(sfVector2f pos, char *path, int nb, int bol)
{
    char **tab = NULL;
    char **info = read_doub_file(path);

    if (!info)
        return (NULL);
    tab = malloc(sizeof(char *) * (9));
    tab[0] = info[nb];
    if (bol == 0) {
        tab[1] = nb_to_string(pos.x - (my_getnbr(info[nb + 1]) / 2), tab[1], 0);
        tab[2] = nb_to_string(pos.y - (my_getnbr(info[nb + 2]) / 2), tab[2], 0);
    } else {
        tab[1] = nb_to_string(pos.x, tab[nb + 1], 0);
        tab[2] = nb_to_string(pos.y, tab[nb + 1], 0);
    }
    tab[3] = info[nb + 3];
    tab[4] = "0";
    tab[5] = "0";
    tab[6] = info[nb + 1];
    tab[7] = info[nb + 2];
    tab[8] = 0;
    return (tab);
}

sfVector2f found_pos(my_button_t *road, game_t window)
{
    sfVector2f pos_f = {0};
    sfVector2i pos_one = {0};
    sfVector2f tmp = {0};

    pos_one = check_pos_mouse(window.basic.window);
    pos_f.x = pos_one.x, pos_f.y = pos_one.y;
    for (int i = 0; road[i].butt.sprite; i++) {
        tmp.x = road[i].butt.vectf.x;
        tmp.y = road[i].butt.vectf.y;
        if (pos_f.x >= tmp.x && pos_f.x <= tmp.x + 180
            && pos_f.y >= tmp.y && pos_f.y <= tmp.y + 180) {
            tmp.x += (128 / 2);
            tmp.y += 20;
            return (tmp);
        }
    }
    return (pos_f);
}

link_t *add_link_on_list(link_t *list, event_game_t *event, game_t window,
    my_button_t *road)
{
    sfVector2f pos_f = {0};
    char **tab = NULL;
    link_t *link = NULL;
    anim_t anim = {0};

    pos_f = found_pos(road, window);
    tab = create_tab_fire(pos_f, "res/file/anim_game.txt", 0, 0);
    set_anim(tab, &anim);
    link = add_link(link, anim, 0, NULL);
    link->life = 1;
    link->pos = pos_f;
    connect_links(NULL, NULL, list, link);
    if (!list) {
        list = link;
        list->prev = NULL;
        list->next = NULL;
    }
    while (list && list->prev != NULL)
        list = list->prev;
    return (list);
}

link_t *create_link_fire(link_t *list, event_game_t *event, game_t window,
    my_button_t *road)
{
    if (check_button(road, window.basic.window) == 0 || event->money < 150) {
        event->fire = 0;
        event->fire_repush = 0;
        return (list);
    }
    while (list && list->next)
        list = list->next;
    list = add_link_on_list(list, event, window, road);
    event->fire = 0;
    event->fire_repush = 0;
    event->money -= 150;
    return (list);
}

void draw_fire(link_t *list, game_t window)
{
    sfTime time = {0};
    float speed = 0;

    while (list && list->prev)
        list = list->prev;
    while (list) {
        time = sfClock_getElapsedTime(list->clock);
        speed = time.microseconds / 1000000.0;
        if (speed < 5.0)
            draw_anim(&list->anim, window.basic.window);
        if (list->next == NULL)
            break;
        list = list->next;
    }
}
