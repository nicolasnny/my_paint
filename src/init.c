/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** init.c
*/

#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_paint.h"
#include "struct.h"

static void check_file_events(sfRenderWindow *window,
    surface_t *surface, drop_menu_list_t *file_buttons, sfEvent *event)
{
    check_menu_clicked(file_buttons, event, surface, window);
}

static void check_edit_events(sfRenderWindow *window,
    surface_t *surface, drop_menu_list_t *edit_buttons, sfEvent *event)
{
    check_menu_clicked(edit_buttons, event, surface, window);
}

static void check_color_events(sfRenderWindow *window,
    surface_t *surface, drop_menu_list_t *colors, sfEvent *event)
{
    if (colors->menu->button->is_clicked(colors->menu->button,
            &event->mouseButton)) {
            set_color(surface, window, colors->menu->button);
    }
    if (event->type == sfEvtMouseMoved)
        colors->menu->button->is_hover(colors->menu->button,
            &event->mouseMove);
    check_drawing(surface, (sfWindow *)window);
}

static button_list_t *init_buttons(void)
{
    button_list_t *buttons = malloc(sizeof(button_list_t));

    buttons->edit_buttons = init_edit_buttons();
    buttons->colors = init_color_buttons();
    buttons->file_buttons = init_file_buttons();
    return buttons;
}

static void check_events(sfRenderWindow *window, surface_t *surface,
    button_list_t *buttons)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        check_file_events(window, surface, buttons->file_buttons, &event);
        check_color_events(window, surface, buttons->colors, &event);
        check_edit_events(window, surface, buttons->edit_buttons, &event);
    }
    check_menu_disp(window, buttons->file_buttons);
    check_menu_disp(window, buttons->colors);
    check_menu_disp(window, buttons->edit_buttons);
}

int init(void)
{
    sfRenderWindow *window = sfRenderWindow_create(
        (sfVideoMode){DEFAULT_WIDTH, DEFAULT_HEIGHT, 32}, PROG_NAME,
            sfResize | sfClose, NULL);
    surface_t *surface = init_surface();
    button_list_t *buttons = init_buttons();

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfColor_fromRGB(158, 158, 158));
        check_events(window, surface, buttons);
        sfRenderWindow_drawSprite(window, surface->surface_sprite, NULL);
        sfRenderWindow_display(window);
    }
    return 0;
}
