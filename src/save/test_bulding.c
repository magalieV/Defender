/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** Created by remipeyras,
*/

#include "defender.h"

int create_assit(transport_s *trans)
{
    char **tab = NULL;
    char **object = read_file("res/file/building/global_tower.txt");
    char **text = read_file("res/file/building/global_text.txt");
    trans->selection = malloc(sizeof(assit_s) * 11);
    assit_s end = {0};

    if (!trans->selection)
        return (-1);
    for (int n = 0; object[n]; n++) {
        tab = read_file(object[n]);
        trans->selection[n].obj = create_multi_object(tab);
        destroy_doub_tab(tab);
    }
    for (int n = 0; text[n]; n++) {
        tab = read_file(text[n]);
        if (create_text(tab, &trans->selection[n].text) == 84)
            return (-1);
    }
    trans->selection[10] = end;
    free_tab(object, text);
    return (0);
}

int create_tran(transport_s *tran)
{
    char **tab[4] = {read_file("res/file/boutton_building.txt"),
        read_file("res/file/menu_building.txt"),
        read_file("res/file/text_build.txt"), NULL};

    tran->button = create_my_button(tab[0], tran->button);
    tran->info = create_multi_object(tab[1]);
    if (create_object("res/game/3.png", 0, (sfVector2f)
    {334, 0}, &tran->back) == -1)
        return (-1);
    if (tran->info == NULL)
        return (-1);
    for (int n = 0; tran->info[n].sprite; n++)
        sfSprite_setScale(tran->info[n].sprite, (sfVector2f) {0.15, 0.15});
    if (create_text(tab[2], &tran->name) == 84)
        return (-1);
    if (tran->button->end == true)
        return (-1);
    if (create_assit(tran) == -1)
        return (-1);
    return (0);
}

void destroy_test_building(transport_s trans)
{
    destroy_my_button(trans.button);
    destroy_object(&trans.back);
    for (int n = 0; trans.info[n].sprite; n++)
        destroy_object(&trans.info[n]);
    free(trans.info);
    for (int n = 0; trans.selection[n].obj; n++) {
        for (int m = 0; trans.selection[n].obj[m].sprite; m++)
            destroy_object(&trans.selection[n].obj[m]);
        free(trans.selection[n].obj);
    }
    return;
}

void test_building(game_t win, event_game_t *my_event)
{
    transport_s tran;

    if (create_tran(&tran) == -1)
        return;
    win.obj[2].vectf.x = 1920;
    win.obj[1].vectf.x = -960;
    sfSprite_setPosition(win.obj[2].sprite, win.obj[2].vectf);
    sfSprite_setPosition(win.obj[1].sprite, win.obj[1].vectf);
    draw_test_building(win, tran);
    destroy_test_building(tran);
    return;
}
