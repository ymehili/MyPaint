/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** new_file
*/

#include "../include/my_paint.h"

int new_file(global_t *global, void *param)
{
    layer_t *layers = global->layers;
    layer_t *tmp = NULL;

    for (; layers != NULL; layers = layers->next) {
        if (tmp != NULL)
            free(tmp);
        tmp = layers;
        if (layers->sprite != NULL)
            sfSprite_destroy(layers->sprite);
        if (layers->texture != NULL)
            sfTexture_destroy(layers->texture);
        sfRectangleShape_destroy(layers->button->shape);
        sfText_destroy(layers->button->text);
        free(layers->button);
    }
    global->nb_layers = 1;
    global->layers = initlayers();
    global->filename = NULL;
    return 0;
}
