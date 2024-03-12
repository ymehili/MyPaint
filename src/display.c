/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** display
*/

#include "../include/my_paint.h"

void display_layer_button(sfRenderWindow *window, layer_t *layers)
{
    int ypos = 0;

    for (layer_t *tmp = layers; tmp != NULL; tmp = tmp->next) {
        if (tmp->displayed) {
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
            sfText_setPosition(tmp->button->text, (sfVector2f){50, ypos + 50});
            sfRectangleShape_setPosition(tmp->button->shape,
                (sfVector2f){0, ypos});
            sfRenderWindow_drawRectangleShape(window, tmp->button->shape,
                NULL);
            sfRenderWindow_drawText(window, tmp->button->text, NULL);
            ypos += 100;
        }
    }
}

int display(global_t *global)
{
    button_t *tmp = global->menubar->buttons;
    int click = 0;

    display_layer_button(global->window, global->layers);
    display_menubar(global->window, global->menubar);
    for (; tmp != NULL; tmp = tmp->next) {
        if (check_hover_btn(global, tmp))
            ((dropdown_menu_t *)tmp->hover_param)->displayed = 10;
        if (tmp->hover_param != NULL)
            check_dropdown_hover(global, tmp->hover_param);
        if (((dropdown_menu_t *)tmp->hover_param)->displayed > 0)
            click = check_dd_btn(global,
                ((dropdown_menu_t *)tmp->hover_param)->buttons);
        if (click == 1)
            ((dropdown_menu_t *)tmp->hover_param)->displayed = 0;
    }
    return 0;
}
