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
#include "include/my_paint.h"
#include "include/struct.h"

void check_events(sfRenderWindow *window, drop_menu_list_t *menu_list)
{
    sfEvent *event = malloc(sizeof(sfEvent));

    while (sfRenderWindow_pollEvent(window, event)){
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        check_menu_list_event(event, menu_list);
    }
}

int init(void)
{
    sfRenderWindow *paint = sfRenderWindow_create(
        (sfVideoMode){1920, 1080, 32}, "paint", sfResize | sfClose, NULL);
    button_t *file_button = init_button((sfVector2f){100, -100},
        (sfVector2f){200, 100});
    button_t *edit_button = init_button((sfVector2f){-200, -100},
        (sfVector2f){200, 100});
    drop_menu_list_t *menu_list = new_drop_menu_list();
    s_gui_drop_menu_t *file_menu = new_drop_menu(file_button);
    s_gui_drop_menu_t *edit_menu = new_drop_menu(edit_button);

    file_menu->insert_option(file_menu, init_button((sfVector2f){100, -300},
        (sfVector2f){200, 100}));
    file_menu->insert_option(file_menu, init_button((sfVector2f){100, -500},
        (sfVector2f){200, 100}));
    edit_menu->insert_option(edit_menu, init_button((sfVector2f){-200, -300},
        (sfVector2f){200, 100}));
    edit_menu->insert_option(edit_menu, init_button((sfVector2f){-200, -500},
        (sfVector2f){200, 100}));
    menu_list->insert_menu(menu_list, file_menu);
    menu_list->insert_menu(menu_list, edit_menu);
    while (sfRenderWindow_isOpen(paint)) {
        sfRenderWindow_clear(paint, sfWhite);
        check_events(paint, menu_list);
        check_menu_disp(paint, menu_list);
        sfRenderWindow_drawRectangleShape(paint,
            edit_menu->button->rect, NULL);
        sfRenderWindow_drawRectangleShape(paint,
            file_menu->button->rect, NULL);
        sfRenderWindow_display(paint);
    }
    return 0;
}
