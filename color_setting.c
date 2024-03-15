/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** color_setting.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"
#include "include/my_paint.h"

int set_rubber(surface_t *surface, sfRenderWindow *window)
{
    (void)window;
    surface->last_color = surface->color;
    surface->color = sfWhite;
    return SUCCESS_EXIT;
}

int set_pencil(surface_t *surface, sfRenderWindow *window)
{
    (void)window;
    surface->color = surface->last_color;
    return SUCCESS_EXIT;
}

int set_color(surface_t *surface, sfRenderWindow *window,
    button_t *color_button)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)window);
    sfVector2f final_pos = {
        (float)(mouse_pos.x - color_button->position.x * -1) /
            color_button->size.x * COLOR_PICKER_WIDTH,
        (float)(mouse_pos.y - color_button->position.y * -1) /
            color_button->size.y * COLOR_PICKER_HEIGHT
    };
    int final_x = (int)final_pos.x;
    int final_y = (int)final_pos.y;

    surface->last_color = surface->color;
    surface->color = sfImage_getPixel(color_button->image, final_x, final_y);
    return SUCCESS_EXIT;
}

drop_menu_list_t *init_color_buttons(void)
{
    drop_menu_list_t *color_button_list = new_drop_menu_list();
    button_t *color_button = init_button((sfVector2f){-1600, -20},
        (sfVector2f){200, 200}, NULL);
    s_gui_drop_menu_t *color_menu;

    set_button_image(color_button, "assets/color_palette.png");
    color_menu = new_drop_menu(color_button);
    color_button_list->insert_menu(color_button_list, color_menu);
    return color_button_list;
}
