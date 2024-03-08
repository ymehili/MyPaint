/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** drawzone
*/

#include "../include/my_paint.h"

layer_t *initlayers(void)
{
    layer_t *layers = malloc(sizeof(layer_t));
    sfVector2f position;
    sfImage* image;
    sfColor color;

    layers->texture = sfTexture_create(800, 600);
    image = sfImage_create(800, 600);
    color = sfColor_fromRGB(0, 0, 0);
    sfImage_createFromColor(800, 600, color);
    sfTexture_updateFromImage(layers->texture, image, 0, 0);
    sfImage_destroy(image);
    layers->sprite = sfSprite_create();
    sfSprite_setTexture(layers->sprite, layers->texture, sfTrue);
    position.x = 200;
    position.y = 200;
    sfSprite_setPosition(layers->sprite, position);
    layers->next = NULL;
    return (layers);
}

void zoom_in(layer_t *layers, sfVector2i mousePos, int delta)
{
    sfVector2f scale;
    sfVector2f spritePos;

    if (delta > 0) {
        scale = sfSprite_getScale(layers->sprite);
        spritePos = sfSprite_getPosition(layers->sprite);
        scale.x *= 1.1;
        scale.y *= 1.1;
        sfSprite_setScale(layers->sprite, scale);
        spritePos.x -= (mousePos.x - spritePos.x) * 0.1;
        spritePos.y -= (mousePos.y - spritePos.y) * 0.1;
        sfSprite_setPosition(layers->sprite, spritePos);
    }
}

void zoom_out(layer_t *layers, sfVector2i mousePos, int delta)
{
    sfVector2f scale;
    sfVector2f spritePos;

    if (delta < 0) {
        scale = sfSprite_getScale(layers->sprite);
        spritePos = sfSprite_getPosition(layers->sprite);
        scale.x /= 1.1;
        scale.y /= 1.1;
        sfSprite_setScale(layers->sprite, scale);
        spritePos.x += (mousePos.x - spritePos.x) * 0.1;
        spritePos.y += (mousePos.y - spritePos.y) * 0.1;
        sfSprite_setPosition(layers->sprite, spritePos);
    }
}

void reset_lastpos(global_t *global)
{
    global->lastPos.x = -1;
    global->lastPos.y = -1;
}

static int findposonlayer(global_t *global, sfVector2i *mousePos,
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
    (*drw)->color = sfColor_fromRGB(255, 255, 255);
    (*drw)->image = sfTexture_copyToImage(global->layers->texture);
    return 0;
}

static void drawline(global_t *global, sfVector2i mousePos, drawing_t *drw)
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

void draw_on_layer(global_t *global, sfVector2i mousePos)
{
    drawing_t *drw = malloc(sizeof(drawing_t));

    if (findposonlayer(global, &mousePos, &drw) == 1)
        return;
    if (global->lastPos.x != -1 && global->lastPos.y != -1) {
        drawline(global, mousePos, drw);
    } else
        sfImage_setPixel(drw->image, mousePos.x, mousePos.y, drw->color);
    sfTexture_updateFromImage(global->layers->texture, drw->image, 0, 0);
    sfImage_destroy(drw->image);
    global->lastPos = mousePos;
}
