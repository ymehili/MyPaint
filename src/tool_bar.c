/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** tool_bar
*/

#include "../include/my_paint.h"

static void handle_size_button(global_t *global, popup_t *popup, int i,
    sfVector2i mousePos)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(popup->size_buttons[i]->button);

    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        global->pencil->size = i + 1;
}

static void handle_color_button(global_t *global, popup_t *popup, int i,
    sfVector2i mousePos)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(popup->color_buttons[i]->button);

    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        global->pencil->color = popup->colors[i];
}

static void handle_shape_button(global_t *global, popup_t *popup, int i,
    sfVector2i mousePos)
{
    sfFloatRect bounds =
        sfRectangleShape_getGlobalBounds(popup->shape_buttons[i]->button);

    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y))
        global->pencil->shape = i;
}

static void handlebuttons(popup_t *popup, global_t *global,
    sfVector2i mousePos)
{
    for (int i = 0; i < 3; i++)
        handle_size_button(global, popup, i, mousePos);
    for (int i = 0; i < 10; i++)
        handle_color_button(global, popup, i, mousePos);
    for (int i = 0; i < 2; i++)
        handle_shape_button(global, popup, i, mousePos);
}

void handleevents(popup_t *popup, global_t *global)
{
    sfVector2i mousePos;

    while (sfRenderWindow_pollEvent(popup->popup, &popup->event)) {
        if (popup->event.type == sfEvtClosed)
            sfRenderWindow_close(popup->popup);
        if (popup->event.type == sfEvtMouseButtonPressed) {
            mousePos = sfMouse_getPositionRenderWindow(popup->popup);
            handlebuttons(popup, global, mousePos);
        }
    }
}

void displaybuttons(popup_t *popup)
{
    sfRenderWindow_clear(popup->popup, sfBlack);
    for (int i = 0; i < 3; i++)
        display_button(popup->popup, popup->size_buttons[i]);
    for (int i = 0; i < 10; i++)
        display_button(popup->popup, popup->color_buttons[i]);
    for (int i = 0; i < 2; i++)
        display_button(popup->popup, popup->shape_buttons[i]);
    sfRenderWindow_display(popup->popup);
}
