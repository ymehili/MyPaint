/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** save_file
*/

#include "../include/my_paint.h"

static void save_file_2(sfImage *layer_img, int i, sfImage *img)
{
    sfColor col;

    for (int j = 0; j < sfImage_getSize(img).y; j++) {
        col = sfImage_getPixel(layer_img, i, j);
        if (col.a != 0)
            sfImage_setPixel(img, i, j, col);
    }
}

int save_file(global_t *global, void *param)
{
    layer_t *layer = global->layers;
    sfImage *img = sfTexture_copyToImage(global->layers->texture);
    sfImage *layer_img;

    for (; layer != NULL; layer = layer->next) {
        layer_img = sfTexture_copyToImage(layer->texture);
        for (int i = 0; i < sfImage_getSize(img).x; i++) {
            save_file_2(layer_img, i, img);
        }
        sfImage_destroy(layer_img);
    }
    sfImage_saveToFile(img, "save.png");
    return 0;
}
