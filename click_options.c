/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** click_options.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"
#include "include/my_paint.h"

void check_option_clicked(drop_menu_list_t *menu_list,
    surface_t *surface, sfEvent *event, sfRenderWindow *window)
{
    s_gui_options_t *temp = menu_list->menu->options;

    while (temp) {
        temp->option->is_clicked(temp->option, &event->mouseButton);
        if (temp->option->state == PRESSED &&
            temp->option->functionnality)
            temp->option->functionnality(surface, window);
        temp = temp->next;
    }
}

void check_is_clicked(sfEvent *event, drop_menu_list_t *menu_list,
    surface_t *surface, sfRenderWindow *window)
{
    drop_menu_list_t *temp_menu = menu_list;

    while (temp_menu) {
        check_option_clicked(temp_menu, surface, event, window);
        temp_menu = temp_menu->next;
    }
}
