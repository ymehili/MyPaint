/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** open_file
*/

#include "../include/my_paint.h"

static int check_filepath_2(sfRenderWindow *new_window,
    char *filename, global_t *global)
{
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        display_error("File doesn't exists", global);
        close(fd);
        return 0;
    }
    close(fd);
    return 1;
}

static void check_filepath(global_t *global, char *filename,
    sfRenderWindow *new_window)
{
    int i = 0;

    if (strlen(filename) == 0)
        display_error("Filename can't be empty", global);
    for (; filename[i] != '.' && filename[i] != '\0'; i++);
    if (my_strcmp(&filename[i], ".png") != 0 &&
        my_strcmp(&filename[i], ".jpg") != 0 &&
        my_strcmp(&filename[i], ".bmp") != 0) {
        display_error("Filename must end with .png \nor .jpg or .bmp", global);
        return;
    }
    if (check_filepath_2(new_window, filename, global))
        sfRenderWindow_close(new_window);
}

int open_file(global_t *global, void *param)
{
    sfImage *image;
    layer_t *layers = my_malloc(sizeof(layer_t));

    get_filename(global, &check_filepath);
    if (global->filename == NULL)
        return 0;
    image = sfImage_createFromFile(global->filename);
    global->layerSize = (sfVector2i){sfImage_getSize(image).x,
        sfImage_getSize(image).y};
    layers->texture = sfTexture_create(sfImage_getSize(image).x,
        sfImage_getSize(image).y);
    layers->name = my_strdup("Layer 1");
    layers->selected = 1;
    layers->displayed = 1;
    sfTexture_updateFromImage(layers->texture, image, 0, 0);
    sfImage_destroy(image);
    set_layer_sprite(layers);
    initlayerbutton(layers);
    global->layers = layers;
    return 1;
}
