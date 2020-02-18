/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

int set_basic(base_t *base)
{
    base->mode.width = 1920;
    base->mode.height = 1080;
    base->mode.bitsPerPixel = 32;
    if (!(base->window = sfRenderWindow_create(base->mode, "Daenery's game",
        sfResize | sfClose, NULL)))
        return (-1);
    return (0);
}

int create_menu_font(object_t **menu_font)
{
    object_t end = {0};
    sfVector2f vect = {0};
    object_t tmp = {0};
    object_t tmp2 = {0};
    int bol = 0;

    *menu_font = malloc(sizeof(object_t) * (4));
    bol += create_object("res/menu/font.jpg", 0, vect, menu_font[0]);
    bol += create_object("res/menu/menu_part_one.jpg", 0, vect, &tmp);
    vect.x = 960;
    vect.y = 0;
    (*menu_font)[1] = tmp;
    bol += create_object("res/menu/menu_part_two.jpg", 0, vect, &tmp2);
    (*menu_font)[2] = tmp2;
    (*menu_font)[3] = end;
    return (bol < 0 ? -1 : 0);
}

static int init_window(object_t *load, object_t **menu_font, win_t *wind)
{
    sfVector2f tmp = {0};
    int bol = 0;

    (*wind).buffer = frame_buffer_create(1920, 1080);
    (*wind).x = 0;
    (*wind).y = 0;
    (*wind).max_x = 1920;
    (*wind).max_y = 1080;
    (*wind).color = sfBlack;
    (*wind).texture = sfTexture_create(1920, 1080);
    if (!((*wind).texture))
        return (84);
    (*wind).sprite = sfSprite_create();
    sfSprite_setTexture((*wind).sprite, (*wind).texture, sfTrue);
    bol += create_menu_font(menu_font);
    bol += create_object("res/dragon_load.jpg", 0, tmp, load);
    return (bol < 0 ? 84 : 0);
}

int my_defender(void)
{
    game_t window = {0};
    object_t *menu_font = NULL;
    object_t load = {0};

    if (set_basic(&window.basic) == -1)
        return (84);
    if (init_window(&load, &menu_font, &window.wind) == 84)
        return (84);
    if (set_struct_music(&window.music) == -1)
        return (84);
    sfRenderWindow_setFramerateLimit(window.basic.window, 60);
    load_page(window, menu_font, load);
    return (0);
}

int main(void)
{
    return (my_defender());
}
