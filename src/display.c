/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** display
*/

#include "../include/my_paint.h"


void display_layers(sfRenderWindow *window, layer_t *layers)
{
    for (layer_t *tmp = layers; tmp != NULL; tmp = tmp->next) {
        if (tmp->displayed) {
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        }
    }
}

void display_layer_button(sfRenderWindow *window, layer_t *layers)
{
    int ypos = 30;

    for (layer_t *tmp = layers; tmp != NULL; tmp = tmp->next) {
        sfRectangleShape_setFillColor(tmp->button->shape,
            tmp->selected ? sfColor_fromRGB(0, 0, 255) :
                sfColor_fromRGB(220, 220, 220));
        if (!tmp->displayed)
            sfRectangleShape_setFillColor(tmp->button->shape,
                sfColor_fromRGB(220, 0, 0));
        sfText_setPosition(tmp->button->text, (sfVector2f){50, ypos + 25});
        sfRectangleShape_setPosition(tmp->button->shape,
            (sfVector2f){0, ypos});
        sfRenderWindow_drawRectangleShape(window, tmp->button->shape,
            NULL);
        sfRenderWindow_drawText(window, tmp->button->text, NULL);
        ypos += 70;
    }
}

static void check_left_click_layer_btn(global_t *global, layer_t *layer,
    sfFloatRect rect, sfVector2i mouse)
{
    if (rect.left < mouse.x && rect.left + rect.width > mouse.x &&
        rect.top < mouse.y && rect.top + rect.height > mouse.y &&
        sfMouse_isButtonPressed(sfMouseRight) && layer->button->delay < 0) {
        layer->displayed = !layer->displayed;
        layer->button->delay = 10;
    }
}

void check_layer(global_t *global)
{
    layer_t *layer = global->layers;
    sfRectangleShape *btn;
    sfFloatRect rect;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->window);

    for (; layer != NULL; layer = layer->next) {
        layer->button->delay--;
        btn = layer->button->shape;
        rect = sfRectangleShape_getGlobalBounds(btn);
        check_left_click_layer_btn(global, layer, rect, mouse);
        if (!(rect.left < mouse.x && rect.left + rect.width > mouse.x &&
            rect.top < mouse.y && rect.top + rect.height > mouse.y &&
            sfMouse_isButtonPressed(sfMouseLeft) && layer->button->delay < 0))
            continue;
        for (layer_t *tmp = global->layers; tmp != NULL; tmp = tmp->next)
            tmp->selected = 0;
        layer->selected = 1;
    }
}

int display(global_t *global)
{
    button_t *tmp = global->menubar->buttons;
    int click = 0;

    display_layers(global->window, global->layers);
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
    check_layer(global);
    return 0;
}
