/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** Created by remipeyras,
*/

#include "defender.h"

void set_volume(music_t *music)
{
    for (int n = 0; music->music[n]; n++)
        sfMusic_setVolume(music->music[n], music->mus_vol);
    for (int n = 0; music->sound[n]; n++)
        sfMusic_setVolume(music->sound[n], music->snd_vol);
}

static int create_music(music_t *music, char **t1, char **t2)
{
    int nb = my_getnbr(t1[0]);

    if (!(music->music = malloc(sizeof(sfMusic *) * (nb + 1))))
        return (-1);
    for (int n = 0; n < nb; n++)
        music->music[n] = sfMusic_createFromFile(t1[n + 1]);
    music->music[nb] = NULL;
    nb = my_getnbr(t2[0]);
    if (!(music->sound = malloc(sizeof(sfMusic *) * (nb + 1))))
        return (-1);
    for (int n = 0; n < nb; n++)
        music->sound[n] = sfMusic_createFromFile(t2[n + 1]);
    music->sound[nb] = NULL;
    return (0);
}

int set_struct_music(music_t *music)
{
    char **tab_mus = read_file("res/file/music.txt");
    char **tab_sound = read_file("res/file/sound.txt");

    if (!tab_mus || !tab_sound)
        return (-1);
    if (create_music(music, tab_mus, tab_sound) == -1)
        return (-1);
    free_tab(tab_mus, tab_sound);
    music->mus_vol = 25;
    music->snd_vol = 100;
    set_volume(music);
    return (0);
}

void destroy_music(music_t music)
{
    for (int n = 0; music.music[n]; n++)
        sfMusic_destroy(music.music[n]);
    for (int n = 0; music.sound[n]; n++)
        sfMusic_destroy(music.sound[n]);
    free(music.music);
    free(music.sound);
}