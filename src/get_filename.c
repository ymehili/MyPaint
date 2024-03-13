/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** get_filename
*/

#include "../include/my_paint.h"

void handle_event(global_t *global,
    sfRenderWindow *new_window, sfText *filename,
    void (*check)(global_t *, char *, sfRenderWindow *))
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(new_window, &event)) {
        sfText_setString(filename, global->filename);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn)
            check(global, global->filename, new_window);
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(new_window);
            global->filename = NULL;
        }
        if (event.type != sfEvtTextEntered)
            continue;
        if (event.text.unicode == 8 && my_strlen(global->filename) > 0) {
            global->filename[strlen(global->filename) - 1] = '\0';
            continue;
        }
        if (event.text.unicode < 128 && my_strlen(global->filename) < 30)
            global->filename = my_strcat(global->filename,
                (char[2]){event.text.unicode, '\0'});
    }
}

void get_filename(global_t *global,
    void (*check)(global_t *, char *, sfRenderWindow *))
{
    sfRenderWindow *new_window = create_window(400, 200);
    sfText *text = create_text("Enter filename :",
        (sfVector2f){40, 50}, FONT_PATH, 30);
    sfText *filename = create_text("", (sfVector2f){10, 100}, FONT_PATH, 22);

    global->filename = my_malloc(sizeof(char) * 31);
    sfRenderWindow_setFramerateLimit(new_window, 60);
    while (sfRenderWindow_isOpen(new_window)) {
        sfRenderWindow_clear(new_window, sfWhite);
        sfRenderWindow_drawText(new_window, text, NULL);
        sfRenderWindow_drawText(new_window, filename, NULL);
        if (global->error_delay > 0 && global->error_txt != NULL) {
            sfRenderWindow_drawText(new_window, global->error_txt, NULL);
            global->error_delay--;
        }
        sfRenderWindow_display(new_window);
        sfRenderWindow_display(global->window);
        handle_event(global, new_window, filename, check);
    }
    sfRenderWindow_destroy(new_window);
}
