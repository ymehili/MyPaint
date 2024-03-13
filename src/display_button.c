/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** display_button
*/

#include "../include/my_paint.h"

void display_button(sfRenderWindow *window, button_t *button)
{
    sfRenderWindow_drawRectangleShape(window, button->button, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}
