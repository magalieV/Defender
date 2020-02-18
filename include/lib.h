/*
** EPITECH PROJECT, 2018
** defender_reset
** File description:
** Created by remipeyras,
*/
#ifndef DEFENDER_RESET_LIB_H
#define DEFENDER_RESET_LIB_H

//------------------------lib <<no graph>>------------------------
char *gnl(int);
char *my_itoa(int);
int my_getnbr(char const *);
int my_strlen(char const *);
char *my_strdup(char const *);
void free_tab(char **, char **);
void my_put_error(char const *);
int free_set(char **, int);
char **read_file(char const *);
//------------------------lib <<graph>>------------------------
//set_struct_object
int create_object(char const *, float, sfVector2f, object_t *);
object_t *create_multi_object(char **tab);
void destroy_object(object_t *);
//set_struct_anim
sfIntRect set_int_rect(int, int, int, int);
int *fill_rect(char **, int);
int set_anim(char **, anim_t *);
void draw_anim(anim_t *, sfRenderWindow *);
void destroy_anim(anim_t);
//set_struct_text
void draw_txt(text_t, sfRenderWindow *);
int set_text(char **, text_t *);
void destroy_txt(text_t);
//set_struct_music
void set_volume(music_t *);
int set_struct_music(music_t *);
void destroy_music(music_t);

#endif //DEFENDER_RESET_LIB_H
