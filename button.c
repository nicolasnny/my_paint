/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** button.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"

sfBool is_hover(button_t *button, sfMouseMoveEvent *event)
{
    sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_bounds, event->x, event->y)) {
        button->state = HOVER;
        return sfTrue;
    }
    button->state = NONE;
    return sfFalse;
}

sfBool is_clicked(button_t *button, sfMouseButtonEvent *event)
{
    sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_bounds, event->x, event->y)) {
        button->state = HOVER;
        return sfTrue;
    }
    button->state = NONE;
    return sfFalse;
}

button_t *init_button(sfVector2f position, sfVector2f size)
{
    button_t *new_button = malloc(sizeof(button_t));

    new_button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(new_button->rect, size);
    sfRectangleShape_setOrigin(new_button->rect, position);
    sfRectangleShape_setFillColor(new_button->rect, sfRed);
    new_button->is_clicked = &is_clicked;
    new_button->is_hover = &is_hover;
    return new_button;
}
