/*
** EPITECH PROJECT, 2018
** defender_reset
** File description:
** fonction for create the struct object_t, and for destroy it
*/

#include "defender.h"

int create_object(char const *fp, float speed, sfVector2f pos,
    object_t *obj)
{
    if (!(obj->texture = sfTexture_createFromFile(fp, NULL)))
        return (-1);
    obj->vectf = pos;
    obj->speed = speed;
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->vectf);
    return (0);
}

object_t *create_multi_object(char **tab)
{
    object_t *object = NULL;
    sfVector2f pos = {0};
    object_t end = {0};
    int k = 0;

    if (!(object = malloc(sizeof(object_t) * (my_getnbr(tab[0]) + 1))))
        return (NULL);
    for (int i = 1; tab[i]; i += 3, k++) {
        pos.x = my_getnbr(tab[i + 1]);
        pos.y = my_getnbr(tab[i + 2]);
        if (create_object(tab[i], 0, pos, &object[k]) == -1)
            return (NULL);
    }
    object[k] = end;
    return (object);
}

void destroy_object(object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
}
