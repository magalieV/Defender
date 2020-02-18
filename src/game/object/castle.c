/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "defender.h"

object_t *create_castle(void)
{
    char *rng = malloc(0);
    int p = 0;
    char **tab = NULL;
    sfVector2f pos = {0};
    object_t *castle = malloc(sizeof(object_t) * (4));
    object_t end = {0};
    int k = 0;

    if (!castle || ((tab = read_doub_file("res/file/castle.txt")) == NULL))
        return (NULL);
    p = (rand() * ((long)&rng >> 24)) % 2;
    p = (p == 1 || p == 2) ? 9 * p : p;
    free (rng);
    for (int i = p; k <= 2; i += 3) {
        pos.x = 1920 - my_getnbr(tab[i + 1]) + 120;
        if (create_object(tab[i], 0, pos, &castle[k++]) == -1)
            return (NULL);
    }
    destroy_doub_tab(tab);
    return (castle[k] = end, castle);
}

void win_money(event_game_t *event)
{
    static int score = 0;

    if (event->score > score)
        event->money += 50;
    score = event->score;
}
