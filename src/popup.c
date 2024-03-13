/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** popup
*/

#include "../include/my_paint.h"

static void initcolorandsizebuttons(popup_t *popup)
{
    popup->colors[0] = sfRed;
    popup->colors[1] = sfBlack;
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
}

static void initcolorandshapebuttons(popup_t *popup)
{
    for (int i = 0; i < 10; i++) {
        popup->color_buttons[i] = initbutton((sfVector2f){100, i * 50},
            (sfVector2f){50, 50}, "");
        sfRectangleShape_setFillColor(popup->color_buttons[i]->button,
            popup->colors[i]);
    }
    popup->shape_buttons[0] = initbutton((sfVector2f){200, 50},
        (sfVector2f){150, 50}, "Circle");
    popup->shape_buttons[1] = initbutton((sfVector2f){200, 100},
        (sfVector2f){150, 50}, "Rectangle");
}

static void initpopupandbuttons(popup_t *popup, global_t *global)
{
    popup->popup = create_window(500, 500);
    initcolorandsizebuttons(popup);
    initcolorandshapebuttons(popup);
}

static void setfillcolorforbuttons(popup_t *popup, global_t *global)
{
    sfRectangleShape_setFillColor(popup->shape_buttons[0]->button, sfGreen);
    sfRectangleShape_setFillColor(popup->shape_buttons[1]->button, sfGreen);
    sfRectangleShape_setFillColor(popup->size_buttons[0]->button, sfGreen);
    sfRectangleShape_setFillColor(popup->size_buttons[1]->button, sfGreen);
    sfRectangleShape_setFillColor(popup->size_buttons[2]->button, sfGreen);
}

void handleanddisplayevents(popup_t *popup, global_t *global)
{
    sfRenderWindow_setFramerateLimit(popup->popup, 60);
    while (sfRenderWindow_isOpen(popup->popup)) {
        handleevents(popup, global);
        displaybuttons(popup);
        sfRenderWindow_display(global->window);
    }
}

void pencilpopup(global_t *global)
{
    popup_t *popup = malloc(sizeof(popup_t));

    initpopupandbuttons(popup, global);
    setfillcolorforbuttons(popup, global);
    handleanddisplayevents(popup, global);
}
