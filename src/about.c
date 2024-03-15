/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** about
*/

#include "../include/my_paint.h"

static void event(sfRenderWindow *new_window, global_t *global)
{
    while (sfRenderWindow_pollEvent(new_window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(new_window);
    }
}

int about(global_t *global, void *param)
{
    sfRenderWindow *new_window = create_window(800, 400);
    sfText *title = create_text("-< My Paint >-",
        (sfVector2f){240, 20}, FONT_PATH, 40);
    sfText *text = create_text("By Lucas Leclerc and Youssef Mehili\n\n\nV1.2",
        (sfVector2f){75, 150}, FONT_PATH, 30);

    sfText_setColor(title, sfColor_fromRGB(220, 0, 180));
    sfRenderWindow_setFramerateLimit(new_window, 60);
    while (sfRenderWindow_isOpen(new_window)) {
        sfRenderWindow_clear(new_window, sfWhite);
        sfRenderWindow_drawText(new_window, text, NULL);
        sfRenderWindow_drawText(new_window, title, NULL);
        sfRenderWindow_display(new_window);
        sfRenderWindow_display(global->window);
        event(new_window, global);
    }
    sfRenderWindow_destroy(new_window);
    return 0;
}
