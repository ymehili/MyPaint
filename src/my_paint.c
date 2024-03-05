/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** my_paint
*/
#include "../include/my_paint.h"

global_t *initglobal()
{
    global_t *global = malloc(sizeof(global_t));
    global->window = create_window(1920, 1080);
    return (global);
}

int my_paint(int argc, char **argv)
{
    global_t *global = initglobal();

    while (sfRenderWindow_isOpen(global->window)) {
        while (sfRenderWindow_pollEvent(global->window, &global->event)) {
            if (global->event.type == sfEvtClosed)
                sfRenderWindow_close(global->window);
        }
        sfRenderWindow_clear(global->window, sfBlack);
        sfRenderWindow_display(global->window);
    }
    sfRenderWindow_destroy(global->window);
    return 0;
}
