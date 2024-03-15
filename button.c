/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** button.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/my_paint.h"
#include "include/struct.h"

sfBool is_hover(button_t *button, sfMouseMoveEvent *event)
{
    sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_bounds, event->x, event->y) &&
        event->type == sfEvtMouseMoved) {
        button->state = HOVER;
        sfRectangleShape_setOutlineColor(button->rect, sfRed);
        return sfTrue;
    }
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);
    button->state = NONE;
    return sfFalse;
}

sfBool is_clicked(button_t *button, sfMouseButtonEvent *event)
{
    sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&button_bounds, event->x, event->y) &&
        event->type == sfEvtMouseButtonPressed) {
        sfRectangleShape_setOutlineColor(button->rect, sfBlue);
        button->state = PRESSED;
        return sfTrue;
    }
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);
    button->state = NONE;
    return sfFalse;
}

int set_button_text(button_t *button, char *button_text)
{
    sfFont *font = sfFont_createFromFile(
            "font/Madimi_One/MadimiOne-Regular.ttf");

    if (button->image)
        return ERROR_EXIT;
    if (button->name)
        sfText_destroy(button->name);
    button->name = sfText_create();
    sfText_setPosition(button->name,
        (sfVector2f){button->position.x * -1, button->position.y * -1});
    sfText_setString(button->name, button_text);
    sfText_setFont(button->name, font);
    sfText_setColor(button->name, sfBlack);
    return SUCCESS_EXIT;
}

int set_button_image(button_t *button, char *image_filepath)
{
    sfTexture *image_texture;

    if (button->name)
        return ERROR_EXIT;
    if (button->image)
        sfImage_destroy(button->image);
    button->image = sfImage_createFromFile(image_filepath);
    image_texture = sfTexture_createFromImage(button->image, NULL);
    if (!image_texture)
        return ERROR_EXIT;
    sfRectangleShape_setTexture(button->rect, image_texture, sfTrue);
    return SUCCESS_EXIT;
}

button_t *init_button(sfVector2f position, sfVector2f size,
    int (*functionnality)(surface_t *, sfRenderWindow *))
{
    button_t *new_button = malloc(sizeof(button_t));

    new_button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(new_button->rect, size);
    sfRectangleShape_setOrigin(new_button->rect, position);
    new_button->position = position;
    new_button->size = size;
    new_button->is_clicked = &is_clicked;
    new_button->is_hover = &is_hover;
    if (functionnality)
        new_button->functionnality = functionnality;
    else
        new_button->functionnality = NULL;
    new_button->collidable = false;
    new_button->state = NONE;
    new_button->image = NULL;
    new_button->name = NULL;
    sfRectangleShape_setOutlineColor(new_button->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(new_button->rect, 2.5);
    return new_button;
}
