/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

int castle_dead(int *life, moove_t *moove, link_t *monster)
{
    int size = 0;
    sfVector2f pos = {0};

    if (!monster)
        return (0);
    for (size = 0; moove[size].moove; size++);
    while (monster && monster->prev != NULL)
        monster = monster->prev;
    while (monster) {
        pos.x = monster->anim_tab[0].obj.vectf.x;
        pos.y = monster->anim_tab[0].obj.vectf.y;
        if (on_rect(moove[size - 1].corner, pos, -1, -1) && monster->life > 0)
            *life -= 1;
        if (!monster->next)
            break;
        monster = monster->next;
    }
    while (monster && monster->prev != NULL)
        monster = monster->prev;
    return (*life <= 0 ? 1 : 0);
}

int all_monster_died(link_t *monster, event_game_t event)
{
    int nb = 0;

    while (monster && monster->prev != NULL)
        monster = monster->prev;
    while (monster) {
        if (monster->life > 0)
            nb++;
        if (!monster->next)
            break;
        monster = monster->next;
    }
    return ((nb == 0 && event.nb_mob == 0) ? 1 : 0);
}

void event_end(game_t window, my_button_t *button)
{
    while (sfRenderWindow_pollEvent(window.basic.window, &window.event)) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            check_button(button, window.basic.window);
        if (window.event.type == sfEvtClosed)
            sfRenderWindow_close(window.basic.window);
    }
}

void display_end(int life, game_t window, object_t font)
{
    char **txt = read_doub_file("res/file/end.txt");
    text_t my_txt = {0};
    sfText *end = {0};
    char **tab = read_doub_file("res/file/end_button.txt");
    my_button_t *button = NULL;
    sfFont *fontt = sfFont_createFromFile("res/text_font.ttf");

    button = create_my_button(tab, button);
    if (create_text(txt, &my_txt) == 84)
        return;
    end = life > 0 ? text_create("You Win!", 880, 310, fontt) :
    text_create("You Loose!", 880, 310, fontt);
    while (sfRenderWindow_isOpen(window.basic.window)) {
        sfRenderWindow_display(window.basic.window);
        sfRenderWindow_drawSprite(window.basic.window, font.sprite, NULL);
        display_button(window, button);
        draw_txt(my_txt, window.basic.window);
        sfRenderWindow_drawText(window.basic.window, end, NULL);
        event_end(window, button);
    }
}
