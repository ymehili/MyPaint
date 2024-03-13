/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** popup
*/

#include "../include/my_paint.h"

static void initcolorandsizebuttons(popup_t *popup, global_t *global)
{
    popup->colors[0] = sfWhite;
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
        popup->size_buttons[i] = initbutton((sfVector2f){100 + 50 * i,
            global->windowSize.y - 50}, (sfVector2f){50, 50},
            my_putnbr_in_str(i + 1));
    }
}

static void initcolorandshapebuttons(popup_t *popup, global_t *global)
{
    for (int i = 0; i < 10; i++) {
        popup->color_buttons[i] = initbutton((sfVector2f){300 + 50 * i,
            global->windowSize.y - 50}, (sfVector2f){50, 50}, "");
        sfRectangleShape_setFillColor(popup->color_buttons[i]->button,
            popup->colors[i]);
    }
    popup->shape_buttons[0] = initbutton((sfVector2f){900,
        global->windowSize.y - 50}, (sfVector2f){150, 50}, "Circle");
    popup->shape_buttons[1] = initbutton((sfVector2f){1100,
        global->windowSize.y - 50}, (sfVector2f){150, 50}, "Rectangle");
}

static void initpopupandbuttons(popup_t *popup, global_t *global)
{
    initcolorandsizebuttons(popup, global);
    initcolorandshapebuttons(popup, global);
}

static void setfillcolorforbuttons(popup_t *popup, global_t *global)
{
    sfColor color = sfColor_fromRGB(220, 220, 220);

    sfRectangleShape_setFillColor(popup->shape_buttons[0]->button, color);
    sfRectangleShape_setFillColor(popup->shape_buttons[1]->button, color);
    sfRectangleShape_setFillColor(popup->size_buttons[0]->button, color);
    sfRectangleShape_setFillColor(popup->size_buttons[1]->button, color);
    sfRectangleShape_setFillColor(popup->size_buttons[2]->button, color);
    sfText_setFillColor(popup->shape_buttons[0]->text, sfBlack);
    sfText_setFillColor(popup->shape_buttons[1]->text, sfBlack);
    sfText_setFillColor(popup->size_buttons[0]->text, sfBlack);
    sfText_setFillColor(popup->size_buttons[1]->text, sfBlack);
    sfText_setFillColor(popup->size_buttons[2]->text, sfBlack);
}

void displaypopup(popup_t *popup, global_t *global)
{
    handlepopupevents(popup, global);
    displaybuttons(popup, global);
}

void pencilpopup(global_t *global)
{
    global->popup = malloc(sizeof(popup_t));

    initpopupandbuttons(global->popup, global);
    setfillcolorforbuttons(global->popup, global);
}
