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

void display_error(char *error, global_t *global)
{
    sfText *text = create_text(error, (sfVector2f){40, 150}, FONT_PATH, 18);

    sfText_setColor(text, sfRed);
    global->error_delay = 90;
    global->error_txt = text;
}

char *folder_path(char *filename)
{
    int i = 0;
    char *str;

    for (; filename[i] != '\0'; i++);
    for (; filename[i] != '/' && i > 0; i--);
    if (i == 0)
        return NULL;
    str = my_strdup(filename);
    str[i] = '\0';
    return str;
}

static int check_filename_2(sfRenderWindow *new_window,
    char *filename, global_t *global)
{
    DIR *dir;

    if (folder_path(filename)) {
        dir = opendir(folder_path(filename));
        if (!dir) {
            display_error("wrong path", global);
            closedir(dir);
            return 0;
        } else
            closedir(dir);
    }
    return 1;
}

static void check_filename(global_t *global, char *filename,
    sfRenderWindow *new_window)
{
    int i = 0;

    if (my_strlen(filename) == 0)
        display_error("Filename can't be empty", global);
    for (; filename[i] != '.' && filename[i] != '\0'; i++);
    if (my_strcmp(&filename[i], ".png") != 0 &&
        my_strcmp(&filename[i], ".jpg") != 0 &&
        my_strcmp(&filename[i], ".bmp") != 0) {
        display_error("Filename must end with .png \nor .jpg or .bmp", global);
        return;
    }
    if (check_filename_2(new_window, filename, global))
        sfRenderWindow_close(new_window);
}

int save_file(global_t *global, void *param)
{
    layer_t *layer = global->layers;
    sfImage *img = sfTexture_copyToImage(global->layers->texture);
    sfImage *layer_img;

    if (global->filename == NULL)
        get_filename(global, &check_filename);
    if (global->filename == NULL)
        return 1;
    for (; layer != NULL; layer = layer->next) {
        if (layer->displayed == 0)
            continue;
        layer_img = sfTexture_copyToImage(layer->texture);
        for (int i = 0; i < sfImage_getSize(img).x; i++) {
            save_file_2(layer_img, i, img);
        }
        sfImage_destroy(layer_img);
    }
    sfImage_saveToFile(img, global->filename);
    return 0;
}
