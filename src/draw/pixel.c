/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "defender.h"

void draw_square(sfColor color, win_t wind)
{
    sfVector2i a;
    sfVector2i b;

    for (int x = wind.x; x < wind.max_x; x++) {
        for (int y = wind.y; y < wind.max_y; y++) {
            my_put_pixel(wind.buffer, x, y, wind.color);
        }
    }
}

void my_put_pixel(frame_buffer_t *b, unsigned int x, unsigned int y, sfColor c)
{
    b->pixels[(b->width * y + x) * 4] = c.r;
    b->pixels[(b->width * y + x) * 4 + 1] = c.g;
    b->pixels[(b->width * y + x) * 4 + 2] = c.b;
    b->pixels[(b->width * y + x) * 4 + 3] = c.a;
}

void frame_buffer_destroy(frame_buffer_t *buffer)
{
    free(buffer->pixels);
    free(buffer);
}

frame_buffer_t *frame_buffer_create(unsigned int width, unsigned int height)
{
    frame_buffer_t *list = malloc(sizeof(frame_buffer_t));

    list->width = width;
    list->height = height;
    list->pixels = malloc(width * height * 4 * sizeof(sfUint8));
    return (list);
}
