/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** drop_menu_list.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"
#include "include/my_paint.h"

void check_menu_list_event(sfEvent *event, drop_menu_list_t *menu_list)
{
    drop_menu_list_t *temp = menu_list;

    while (temp) {
        if (event->type == sfEvtMouseMoved && temp->menu)
            temp->menu->button->is_hover(temp->menu->button,
                &event->mouseMove);
        if (event->type == sfEvtMouseButtonPressed && temp->menu)
            temp->menu->button->is_clicked(temp->menu->button,
                &event->mouseButton);
        temp = temp->next;
    }
}

void check_menu_disp(sfRenderWindow *window, drop_menu_list_t *menu_list)
{
    drop_menu_list_t *temp = menu_list;

    while (temp) {
        if (temp->menu && temp->menu->button->state == HOVER)
            disp_drop_menu(window, temp->menu);
        temp = temp->next;
    }
}

int delete_menu_list(struct drop_menu_list_s *bar)
{
    free(bar->menu);
    free(bar);
    return 0;
}

int delete_menu(struct drop_menu_list_s **bar, int menu_id)
{
    drop_menu_list_t *temp = *bar;
    drop_menu_list_t *prev = NULL;

    while (temp != NULL && temp->id != menu_id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return ERROR_EXIT;
    if (prev == NULL)
        *bar = temp->next;
    else
        prev->next = temp->next;
    temp->menu->delete_menu(temp->menu);
    free(temp);
    return SUCCESS_EXIT;
}

static int insert_menu(drop_menu_list_t *bar, s_gui_drop_menu_t *menu)
{
    static int id = 0;
    drop_menu_list_t *new_drop_menu = malloc(sizeof(drop_menu_list_t));

    new_drop_menu->menu = menu;
    new_drop_menu->id = id;
    new_drop_menu->next = bar->next;
    bar->next = new_drop_menu;
    id++;
    return SUCCESS_EXIT;
}

drop_menu_list_t *new_drop_menu_list(void)
{
    drop_menu_list_t *new_bar = malloc(sizeof(drop_menu_list_t));

    new_bar->menu = NULL;
    new_bar->id = 0;
    new_bar->next = NULL;
    new_bar->insert_menu = &insert_menu;
    new_bar->delete_menu = &delete_menu;
    new_bar->delete_list = &delete_menu_list;
    return new_bar;
}
