/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** destroy.c
*/

#include "include/my_paint.h"
#include "include/struct.h"

static void destroy_buttons(button_list_t *buttons)
{
    buttons->colors->delete_list(buttons->colors);
    buttons->edit_buttons->delete_list(buttons->edit_buttons);
    buttons->file_buttons->delete_list(buttons->file_buttons);
}

static void destroy_surface(surface_t *surface)
{
    sfTexture_destroy(surface->surface_texture);
    sfSprite_destroy(surface->surface_sprite);
    sfImage_destroy(surface->surface_image);
}

void destroy_all(sfRenderWindow *window, button_list_t *buttons,
    surface_t *surface)
{
    sfRenderWindow_destroy(window);
    destroy_buttons(buttons);
    destroy_surface(surface);
}
