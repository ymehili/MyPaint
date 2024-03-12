/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** tool_bar
*/

#include "../include/my_paint.h"

void pencilpopup(global_t *global) {
    sfRenderWindow *popup = create_window(500, 500);
    sfEvent event;
    button_t *size_buttons[3];
    button_t *color_buttons[10];
    button_t *shape_buttons[2];
    sfColor colors[10] = {sfBlack, sfWhite, sfRed, sfGreen, sfBlue, sfYellow,
        sfMagenta, sfCyan, sfTransparent, sfColor_fromRGB(255, 165, 0)};
    for (int i = 0; i < 3; i++)
        size_buttons[i] = initbutton((sfVector2f){50, i * 50},
            (sfVector2f){50, 50}, my_putnbr_in_str(i + 1));
    for (int i = 0; i < 10; i++) {
        color_buttons[i] = initbutton((sfVector2f){100, i * 50},
            (sfVector2f){50, 50}, "");
        sfRectangleShape_setFillColor(color_buttons[i]->button, colors[i]);
    }
    shape_buttons[0] = initbutton((sfVector2f){200, 50}, (sfVector2f){100, 100},
        "Circle");
    shape_buttons[1] = initbutton((sfVector2f){200, 100}, (sfVector2f){100, 100},
        "Rectangle");
    sfRectangleShape_setFillColor(shape_buttons[0]->button, sfGreen);
    sfRectangleShape_setFillColor(shape_buttons[1]->button, sfGreen);

    sfRectangleShape_setFillColor(size_buttons[0]->button, sfGreen);
    sfRectangleShape_setFillColor(size_buttons[1]->button, sfGreen);
    sfRectangleShape_setFillColor(size_buttons[2]->button, sfGreen);

    while (sfRenderWindow_pollEvent(popup, &event))
    {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(popup);
        sfRenderWindow_clear(popup, sfBlack);
        for (int i = 0; i < 3; i++)
            display_button(popup, size_buttons[i]);
        for (int i = 0; i < 10; i++)
            display_button(popup, color_buttons[i]);
        for (int i = 0; i < 2; i++)
            display_button(popup, shape_buttons[i]);
        sfRenderWindow_display(popup);
    }
}
