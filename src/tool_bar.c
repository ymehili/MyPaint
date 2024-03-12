/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** tool_bar
*/

#include "../include/my_paint.h"

void handle_size_button(global_t *global, popup_t *popup, int i,
    sfVector2f mousePos)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(popup->size_buttons[i]->button);
    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        global->pencil->size = i + 1;
}

void handle_color_button(global_t *global, popup_t *popup, int i,
    sfVector2f mousePos)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(popup->color_buttons[i]->button);
    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        global->pencil->color = popup->colors[i];
}

void handle_shape_button(global_t *global, popup_t *popup, int i,
    sfVector2f mousePos)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(popup->shape_buttons[i]->button);
    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        global->pencil->shape = i;
}

void initPopupAndButtons(popup_t *popup, global_t *global) {
    popup->popup = create_window(500, 500);
    popup->colors[0] = sfBlack;
    popup->colors[1] = sfWhite;
    popup->colors[2] = sfRed;
    popup->colors[3] = sfGreen;
    popup->colors[4] = sfBlue;
    popup->colors[5] = sfYellow;
    popup->colors[6] = sfMagenta;
    popup->colors[7] = sfCyan;
    popup->colors[8] = sfTransparent;
    popup->colors[9] = sfColor_fromRGB(255, 165, 0);
    for (int i = 0; i < 3; i++){
        popup->size_buttons[i] = initbutton((sfVector2f){50, i * 50},
            (sfVector2f){50, 50}, my_putnbr_in_str(i + 1));
    }
    for (int i = 0; i < 10; i++) {
        popup->color_buttons[i] = initbutton((sfVector2f){100, i * 50},
            (sfVector2f){50, 50}, "");
        sfRectangleShape_setFillColor(popup->color_buttons[i]->button,
            popup->colors[i]);
    }
    popup->shape_buttons[0] = initbutton((sfVector2f){200, 50}, (sfVector2f){150, 50},
        "Circle");
    popup->shape_buttons[1] = initbutton((sfVector2f){200, 100}, (sfVector2f){150, 50},
        "Rectangle");
}

void setFillColorForButtons(popup_t *popup, global_t *global) {
    sfRectangleShape_setFillColor(popup->shape_buttons[0]->button, sfGreen);
    sfRectangleShape_setFillColor(popup->shape_buttons[1]->button, sfGreen);
    sfRectangleShape_setFillColor(popup->size_buttons[0]->button, sfGreen);
    sfRectangleShape_setFillColor(popup->size_buttons[1]->button, sfGreen);
    sfRectangleShape_setFillColor(popup->size_buttons[2]->button, sfGreen);
}

void handleAndDisplayEvents(popup_t *popup, global_t *global) {
    sfVector2f mousePos = (sfVector2f){popup->event.mouseButton.x,
        popup->event.mouseButton.y};

    sfRenderWindow_setFramerateLimit(popup->popup, 60);
    while (sfRenderWindow_isOpen(popup->popup)){
        while (sfRenderWindow_pollEvent(popup->popup, &popup->event))
        {
            if (popup->event.type == sfEvtClosed)
                sfRenderWindow_close(popup->popup);
            if (popup->event.type == sfEvtMouseButtonPressed) {
                for (int i = 0; i < 3; i++)
                    handle_size_button(global, popup, i, mousePos);
                for (int i = 0; i < 10; i++)
                    handle_color_button(global, popup, i, mousePos);
                for (int i = 0; i < 2; i++)
                    handle_shape_button(global, popup, i, mousePos);
            }
            sfRenderWindow_clear(popup->popup, sfBlack);
            for (int i = 0; i < 3; i++)
                display_button(popup->popup, popup->size_buttons[i]);
            for (int i = 0; i < 10; i++)
                display_button(popup->popup, popup->color_buttons[i]);
            for (int i = 0; i < 2; i++)
                display_button(popup->popup, popup->shape_buttons[i]);
            sfRenderWindow_display(popup->popup);
        }
    }
}

void pencilpopup(global_t *global) {
    popup_t *popup = malloc(sizeof(popup_t));

    initPopupAndButtons(popup, global);
    setFillColorForButtons(popup, global);
    handleAndDisplayEvents(popup, global);
}