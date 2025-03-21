/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** btn_func
*/

#include "../include/my_paint.h"

int close_btn(global_t *global, void *param)
{
    sfRenderWindow_close(global->window);
    return 0;
}

int pick_eraser(global_t *global, void *param)
{
    global->pencil->pencil = 0;
    global->pencil->eraser = 1;
    return 0;
}

int pick_pencil(global_t *global, void *param)
{
    global->pencil->pencil = 1;
    global->pencil->eraser = 0;
    return 0;
}
