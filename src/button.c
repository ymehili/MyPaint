/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-lucas.leclerc
** File description:
** button
*/

#include "../include/my_paint.h"

button_t *initbutton(sfVector2f pos, sfVector2f size, char *text)
{
    button_t *button = my_malloc(sizeof(button_t));
    sfFont *font = sfFont_createFromFile(FONT_PATH);

    button->string = text;
    button->text = sfText_create();
    button->button = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->button, pos);
    sfRectangleShape_setSize(button->button, size);
    sfText_setString(button->text, button->string);
    sfText_setCharacterSize(button->text, 24);
    sfText_setFont(button->text, font);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 18, pos.y});
    return button;
}
