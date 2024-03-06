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
    sfText_setPosition(button->text, (sfVector2f){pos.x + 10, pos.y});
    return button;
}

int check_click_btn(global_t *global, button_t *btn)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->window);
    sfVector2f btn_pos = sfRectangleShape_getPosition(btn->button);
    sfVector2f btn_size = sfRectangleShape_getSize(btn->button);

    if (btn->click_func == NULL)
        return 0;
    if (mouse.x > btn_pos.x && mouse.x < btn_pos.x + btn_size.x &&
        mouse.y > btn_pos.y && mouse.y < btn_pos.y + btn_size.y &&
        sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        btn->click_func(global, btn->click_param);
        return 1;
    }
    return 0;
}

int check_hover_btn(global_t *global, button_t *btn)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->window);
    sfVector2f btn_pos = sfRectangleShape_getPosition(btn->button);
    sfVector2f btn_size = sfRectangleShape_getSize(btn->button);

    if (btn->hover_func == NULL)
        return 0;
    if (mouse.x > btn_pos.x && mouse.x < btn_pos.x + btn_size.x &&
        mouse.y > btn_pos.y && mouse.y < btn_pos.y + btn_size.y) {
        btn->hover_func(global, btn->hover_param);
        return 1;
    }
    return 0;
}
