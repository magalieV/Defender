/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

int found_cara(char *str, char c);

object_t *add_life_monster(sfVector2f pos)
{
    object_t *life = malloc(sizeof(object_t) * 4);
    object_t end = {0};

    pos.x += 256;
    create_object("res/game/good.png", 0, pos, &life[0]);
    create_object("res/game/middle.png", 0, pos, &life[1]);
    create_object("res/game/bad.png", 0, pos, &life[2]);
    life[3] = end;
    return (life);
}

anim_t *create_mstr(game_t window, moove_t *moove)
{
    anim_t *anim = malloc(sizeof(anim_t) * (5));
    anim_t end = {0};
    int k = 0;
    char **tab_an = NULL;
    sfVector2f pos = {0};

    pos.x = moove[0].corner.left;
    pos.y = moove[0].corner.width - 10;
    for (int i = 0; i <= 12; i++) {
        tab_an = create_tab_fire(pos, "res/file/anim_dragon.txt", i, 1);
        i += 3;
        set_anim(tab_an, &anim[k]);
        free(tab_an);
        k++;
    }
    anim[k] = end;
    return (anim);
}

link_t *create_link_monster(link_t *list, event_game_t *event, game_t window,
    moove_t *moove)
{
    sfVector2f pos_f = {0};
    link_t *link = NULL;
    anim_t *anim = NULL;
    anim_t tmp = {0};

    while (list && list->next)
        list = list->next;
    anim = create_mstr(window, moove);
    link = add_link(link, tmp, 0, anim);
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

link_t *add_monster(link_t *list, event_game_t *event, game_t window,
    game_play_t pl)
{
    sfTime time = {0};
    float speed = 0;
    static int nb_vague = 0;

    time = sfClock_getElapsedTime(pl.cl[1]);
    speed = time.microseconds / 1000000.0;
    if (nb_vague < 5 && speed > 1.0 && event->nb_mob > 0) {
        list = create_link_monster(list, event, window, pl.mvt);
        event->nb_mob -= 1;
        nb_vague++;
        sfClock_restart(pl.cl[1]);
    } else if (nb_vague >= 5 && speed > 5.0) {
        nb_vague = 0;
        sfClock_restart(pl.cl[1]);
    }
    while (list && list->prev != NULL)
        list = list->prev;
    return (list);
}
