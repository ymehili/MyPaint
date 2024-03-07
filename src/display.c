/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** display
*/

#include "../include/my_paint.h"

int display(global_t *global)
{
    button_t *tmp = global->menubar->buttons;

    display_menubar(global->window, global->menubar);
    for (; tmp != NULL; tmp = tmp->next) {
        if (check_hover_btn(global, tmp))
            ((dropdown_menu_t *)tmp->hover_param)->displayed = 10;
        if (tmp->hover_param != NULL)
            check_dropdown_hover(global, tmp->hover_param);
    }
    sfRenderWindow_drawSprite(global->window, global->layers->sprite, NULL);
    return 0;
}
