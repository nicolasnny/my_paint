/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** edit_buttons.c
*/

#include "include/my_paint.h"
#include "include/struct.h"

int large_size(surface_t *surface, sfRenderWindow *window)
{
    (void)window;
    surface->brush_size = 30;
    return SUCCESS_EXIT;
}

int medium_size(surface_t *surface, sfRenderWindow *window)
{
    (void)window;
    surface->brush_size = 10;
    return SUCCESS_EXIT;
}

int small_size(surface_t *surface, sfRenderWindow *window)
{
    (void)window;
    surface->brush_size = 5;
    return SUCCESS_EXIT;
}

static s_gui_drop_menu_t *init_brush_size(void)
{
    button_t *size_button = init_button((sfVector2f){-1200, -75},
        (sfVector2f){100, 40}, NULL);
    button_t *small_button = init_button((sfVector2f){-1050, -150},
        (sfVector2f){100, 40}, &small_size);
    button_t *medium_button = init_button((sfVector2f){-1200, -150},
        (sfVector2f){120, 40}, &medium_size);
    button_t *large_button = init_button((sfVector2f){-1350, -150},
        (sfVector2f){100, 40}, &large_size);
    s_gui_drop_menu_t *brush_size_menu;

    set_button_text(size_button, "SIZE");
    set_button_text(small_button, "SMALL");
    set_button_text(medium_button, "MEDIUM");
    set_button_text(large_button, "LARGE");
    brush_size_menu = new_drop_menu(size_button);
    brush_size_menu->insert_option(brush_size_menu, small_button);
    brush_size_menu->insert_option(brush_size_menu, medium_button);
    brush_size_menu->insert_option(brush_size_menu, large_button);
    return brush_size_menu;
}

static s_gui_drop_menu_t *init_rubber(void)
{
    button_t *rubber_button = init_button((sfVector2f){-750, -50},
        (sfVector2f){100, 100}, &set_rubber);
    s_gui_drop_menu_t *rubber;

    set_button_image(rubber_button, RUBBER_PATH);
    rubber = new_drop_menu(rubber_button);
    return rubber;
}

static s_gui_drop_menu_t *init_pencil(void)
{
    button_t *pencil_button = init_button((sfVector2f){-600, -50},
        (sfVector2f){100, 100}, &set_pencil);
    s_gui_drop_menu_t *pencil;

    set_button_image(pencil_button, PENCIL_PATH);
    pencil = new_drop_menu(pencil_button);
    return pencil;
}

drop_menu_list_t *init_edit_buttons(void)
{
    drop_menu_list_t *edit_menu = new_drop_menu_list();
    s_gui_drop_menu_t *brush_size_menu = init_brush_size();
    s_gui_drop_menu_t *rubber_menu = init_rubber();
    s_gui_drop_menu_t *pencil_menu = init_pencil();

    edit_menu->insert_menu(edit_menu, brush_size_menu);
    edit_menu->insert_menu(edit_menu, rubber_menu);
    edit_menu->insert_menu(edit_menu, pencil_menu);
    return edit_menu;
}
