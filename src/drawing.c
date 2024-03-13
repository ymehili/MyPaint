/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** drawing
*/

#include "../include/my_paint.h"

static int findposonlayer(global_t *global, sfVector2i *mousePos,
    drawing_t **drw, layer_t *layer)
{
    if (layer == NULL || !sfMouse_isButtonPressed(sfMouseLeft))
        return 1;
    (*drw)->scale = sfSprite_getScale(layer->sprite);
    (*drw)->spritePos = sfSprite_getPosition(layer->sprite);
    (*drw)->textureSize = sfTexture_getSize(layer->texture);
    if (mousePos->x < (*drw)->spritePos.x || mousePos->y < (*drw)->spritePos.y
        || mousePos->x >= (*drw)->spritePos.x + (*drw)->textureSize.x
        * (*drw)->scale.x || mousePos->y >= (*drw)->spritePos.y +
        (*drw)->textureSize.y * (*drw)->scale.y)
        return 1;
    mousePos->x = (mousePos->x - (*drw)->spritePos.x) / (*drw)->scale.x;
    mousePos->y = (mousePos->y - (*drw)->spritePos.y) / (*drw)->scale.y;
    if (global->pencil->eraser == 1)
        (*drw)->color = sfTransparent;
    else
        (*drw)->color = global->pencil->color;
    (*drw)->image = sfTexture_copyToImage(layer->texture);
    return 0;
}

static sfVector2i calculate_diff(global_t *global, sfVector2i mousePos,
    drawing_t *drw)
{
    sfVector2i diff;

    diff.x = mousePos.x - global->pencil->lastPos.x;
    diff.y = mousePos.y - global->pencil->lastPos.y;
    return diff;
}

static int calculate_steps(drawing_t *drw)
{
    int steps = my_abs(drw->diff.x) > my_abs(drw->diff.y) ?
        my_abs(drw->diff.x) : my_abs(drw->diff.y);

    steps = steps == 0 ? 1 : steps;
    return steps;
}

static sfVector2i interpolate_position(global_t *global, drawing_t *drw, int i)
{
    sfVector2i interpolatedPos;

    interpolatedPos.x = global->pencil->lastPos.x + drw->diff.x * i /
        drw->steps;
    interpolatedPos.y = global->pencil->lastPos.y + drw->diff.y * i /
        drw->steps;
    return interpolatedPos;
}

static void draw_circle(global_t *global, drawing_t *drw)
{
    int dx;
    int dy;

    for (int angle = 0; angle < 360; angle++) {
        dx = global->pencil->size * cos(angle * M_PI / 180.0);
        dy = global->pencil->size * sin(angle * M_PI / 180.0);
        sfImage_setPixel(drw->image, drw->interpolatedPos.x + dx,
            drw->interpolatedPos.y + dy, drw->color);
    }
}

static void set_pixel_if_edge(global_t *global, drawing_t *drw, int dx,
    int dy)
{
    if (dx == -global->pencil->size || dx == global->pencil->size ||
        dy == -global->pencil->size || dy == global->pencil->size)
        sfImage_setPixel(drw->image, drw->interpolatedPos.x + dx,
            drw->interpolatedPos.y + dy, drw->color);
}

static void draw_square(global_t *global, drawing_t *drw)
{
    for (int dx = -global->pencil->size; dx <= global->pencil->size; dx++) {
        for (int dy = -global->pencil->size; dy <= global->pencil->size; dy++)
            set_pixel_if_edge(global, drw, dx, dy);
    }
}

static void drawline(global_t *global, sfVector2i mousePos, drawing_t *drw)
{
    drw->diff = calculate_diff(global, mousePos, drw);
    drw->steps = calculate_steps(drw);
    for (int i = 0; i <= drw->steps; i++) {
        drw->interpolatedPos = interpolate_position(global, drw, i);
        if (global->pencil->shape == 1)
            draw_circle(global, drw);
        else
            draw_square(global, drw);
    }
}

void draw_on_layer(global_t *global, sfVector2i mousePos)
{
    drawing_t *drw = malloc(sizeof(drawing_t));
    layer_t *layer = global->layers;

    for (; layer->selected != 1; layer = layer->next);
    if (findposonlayer(global, &mousePos, &drw, layer) == 1)
        return;
    if (global->pencil->lastPos.x != -1 && global->pencil->lastPos.y != -1) {
        drawline(global, mousePos, drw);
    } else
        sfImage_setPixel(drw->image, mousePos.x, mousePos.y,
            global->pencil->color);
    sfTexture_updateFromImage(layer->texture, drw->image, 0, 0);
    sfImage_destroy(drw->image);
    global->pencil->lastPos = mousePos;
}
