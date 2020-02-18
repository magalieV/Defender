/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** __CHANGE THE SCORE OF THE GAME__
*/

#include "defender.h"

char *reverse_str(char const *path)
{
    char *new = NULL;
    int size = 0;
    int cp = 0;

    if (!path)
        return (NULL);
    for (size = 0; path[size]; size++);
    cp = size;
    new = malloc(sizeof(char) * (size + 1));
    for (int i = 0; size > 0; i++)
        new[i] = path[--size];
    new[cp] = '\0';
    return (new);
}

void number_of_digit(int nb, int *count)
{
    int copy = nb;

    while (copy > 0) {
        copy /= 10;
        *count += 1;
    }
    if (nb == 0)
        *count = 1;
}

char *nb_to_string(int nb, char *string, int bol)
{
    int count = 0;
    int k = 0;
    char *sc = " : erocs";
    char *new = NULL;

    number_of_digit(nb, &count);
    string = malloc(sizeof(char) * (count + 9));
    for (int i = 0; i < count; i++) {
        string[k++] = nb % 10 + 48;
        nb /= 10;
    }
    if (bol == 1) {
        for (int j = 0; sc[j]; j++)
        string[k++] = sc[j];
    }
    string[k] = '\0';
    new = reverse_str(string);
    free(string);
    return (new);
}

void up_score(sfClock *clock, event_game_t *my_event, game_t window)
{
    sfTime time = {0};
    double speed = 0;
    sfVector2f pos = {0};

    time = sfClock_getElapsedTime(clock);
    speed = time.microseconds / 1000000.0;
    if (speed > 5.0) {
        (*my_event).score += 1;
        sfClock_restart(clock);
    }
    put_nb_on_screen((*my_event).score, window, pos, 1);
}

void put_nb_on_screen(int nb, game_t window, sfVector2f pos, int bol)
{
    sfText *level = {0};
    sfFont *font = {0};
    char *path = NULL;

    font = sfFont_createFromFile("res/text_font.ttf");
    path = nb_to_string(nb, path, bol);
    level = text_create(path, pos.x, pos.y, font);
    sfRenderWindow_drawText(window.basic.window, level, NULL);
    sfText_destroy(level);
    free(path);
    sfFont_destroy(font);
}
