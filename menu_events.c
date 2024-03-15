/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** menu_events.c
*/

#include "include/my_paint.h"
#include "include/struct.h"

static void check_options_clicked(drop_menu_list_t *menu,
    surface_t *surface, sfEvent *event, sfRenderWindow *window)
{
    s_gui_options_t *temp;

    if (menu->menu->options)
        temp = menu->menu->options;
    while (temp) {
        if (temp->option)
            temp->option->is_clicked(temp->option, &event->mouseButton);
        if (temp->option && temp->option->state == PRESSED &&
            temp->option->functionnality && temp->option->collidable)
            temp->option->functionnality(surface, window);
        if (temp->option && event->type == sfEvtMouseMoved)
            temp->option->is_hover(temp->option, &event->mouseMove);
        temp = temp->next;
    }
}

static void change_collidable(button_t *button)
{
    if (button->collidable)
        button->collidable = false;
    else
        button->collidable = true;
}

static void change_options_state(s_gui_options_t *options)
{
    s_gui_options_t *temp = options;

    while (temp) {
        if (temp->option)
            change_collidable(temp->option);
        temp = temp->next;
    }
}

void check_menu_clicked(drop_menu_list_t *menu_list, sfEvent *event,
    surface_t *surface, sfRenderWindow *window)
{
    drop_menu_list_t *temp_menu_list = menu_list;

    while (temp_menu_list) {
        temp_menu_list->menu->button->is_clicked(
            temp_menu_list->menu->button, &event->mouseButton);
        if (temp_menu_list->menu->button->state == PRESSED)
            change_options_state(temp_menu_list->menu->options);
        if (temp_menu_list->menu->button->state == PRESSED &&
                    temp_menu_list->menu->button->functionnality)
            temp_menu_list->menu->button->functionnality(surface, window);
        if (temp_menu_list->menu->button && event->type == sfEvtMouseMoved)
            temp_menu_list->menu->button->is_hover(
                    temp_menu_list->menu->button, &event->mouseMove);
        check_options_clicked(temp_menu_list, surface, event, window);
        temp_menu_list = temp_menu_list->next;
    }
}
