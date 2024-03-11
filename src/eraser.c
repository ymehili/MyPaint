/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** eraser
*/

#include "../include/my_paint.h"

static int finderaseonlayer(global_t *global, sfVector2i *mousePos,
    drawing_t **drw)
{
    if (global->layers == NULL || !sfMouse_isButtonPressed(sfMouseLeft))
        return 1;
    (*drw)->scale = sfSprite_getScale(global->layers->sprite);
    (*drw)->spritePos = sfSprite_getPosition(global->layers->sprite);
    (*drw)->textureSize = sfTexture_getSize(global->layers->texture);
    if (mousePos->x < (*drw)->spritePos.x || mousePos->y < (*drw)->spritePos.y
        || mousePos->x >= (*drw)->spritePos.x + (*drw)->textureSize.x
        * (*drw)->scale.x || mousePos->y >= (*drw)->spritePos.y +
        (*drw)->textureSize.y * (*drw)->scale.y)
        return 1;
    mousePos->x = (mousePos->x - (*drw)->spritePos.x) / (*drw)->scale.x;
    mousePos->y = (mousePos->y - (*drw)->spritePos.y) / (*drw)->scale.y;
    (*drw)->color = sfTransparent;
    (*drw)->image = sfTexture_copyToImage(global->layers->texture);
    return 0;
}

static void eraseline(global_t *global, sfVector2i mousePos, drawing_t *drw)
{
    drw->diff.x = mousePos.x - global->lastPos.x;
    drw->diff.y = mousePos.y - global->lastPos.y;
    drw->steps = my_abs(drw->diff.x) > my_abs(drw->diff.y) ?
        my_abs(drw->diff.x) : my_abs(drw->diff.y);
    drw->steps = drw->steps == 0 ? 1 : drw->steps;
    for (int i = 0; i <= drw->steps; i++) {
        drw->interpolatedPos.x = global->lastPos.x + drw->diff.x * i
            / drw->steps;
        drw->interpolatedPos.y = global->lastPos.y + drw->diff.y * i
            / drw->steps;
        sfImage_setPixel(drw->image, drw->interpolatedPos.x,
            drw->interpolatedPos.y, drw->color);
    }
}

void erase_on_layer(global_t *global, sfVector2i mousePos)
{
    drawing_t *drw = malloc(sizeof(drawing_t));

    if (finderaseonlayer(global, &mousePos, &drw) == 1)
        return;
    if (global->lastPos.x != -1 && global->lastPos.y != -1) {
        eraseline(global, mousePos, drw);
    } else
        sfImage_setPixel(drw->image, mousePos.x, mousePos.y, drw->color);
    sfTexture_updateFromImage(global->layers->texture, drw->image, 0, 0);
    sfImage_destroy(drw->image);
    global->lastPos = mousePos;
}