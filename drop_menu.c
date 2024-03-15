/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** drop_menu.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"
#include "include/my_paint.h"

void disp_drop_menu(sfRenderWindow *window, s_gui_drop_menu_t *menu)
{
    s_gui_options_t *temp = menu->options;

    while (temp) {
        if (temp->option && temp->option->collidable)
            sfRenderWindow_drawRectangleShape(window, temp->option->rect,
                NULL);
        if (temp->option && temp->option->collidable && temp->option->name)
            sfRenderWindow_drawText(window, temp->option->name, NULL);
        temp = temp->next;
    }
}

static int delete_menu(s_gui_drop_menu_t *menu)
{
    s_gui_drop_menu_t *temp = menu;

    while (temp->options->next) {
        sfRectangleShape_destroy(temp->options->option->rect);
        free(temp->options->option);
        temp->options = temp->options->next;
    }
    free(temp);
    return 0;
}

static int delete_option(s_gui_drop_menu_t **menu, int option_id)
{
    s_gui_drop_menu_t *temp = *menu;

    if (temp->options->id == option_id) {
        free((*menu)->options->option);
        (*menu)->options = (*menu)->options->next;
        return SUCCESS_EXIT;
    }
    while (temp->options->next && temp->options->id != option_id)
        temp->options = temp->options->next;
    if (temp->options->next) {
        free(temp->options->option);
        temp->options->next = temp->options->next->next;
        return SUCCESS_EXIT;
    }
    return ERROR_EXIT;
}

static int insert_option(s_gui_drop_menu_t *menu, button_t *new_option)
{
    static int id = 0;
    s_gui_options_t *new_option_list = malloc(sizeof(s_gui_options_t));

    if (!menu || !new_option)
        return ERROR_EXIT;
    if (!menu->options->option)
        new_option_list->next = NULL;
    else
        new_option_list->next = menu->options;
    new_option_list->option = malloc(sizeof(s_gui_options_t));
    new_option_list->option = new_option;
    new_option_list->id = id;
    id++;
    menu->options = new_option_list;
    return SUCCESS_EXIT;
}

s_gui_drop_menu_t *new_drop_menu(button_t *menu_button)
{
    s_gui_drop_menu_t *new_menu = malloc(sizeof(s_gui_drop_menu_t));

    new_menu->button = malloc(sizeof(button_t));
    new_menu->options = malloc(sizeof(s_gui_options_t));
    new_menu->button = menu_button;
    new_menu->options->option = NULL;
    new_menu->options->next = NULL;
    new_menu->insert_option = &insert_option;
    new_menu->delete_menu = &delete_menu;
    new_menu->delete_option = &delete_option;
    return new_menu;
}
