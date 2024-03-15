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

void check_menu_disp(sfRenderWindow *window, drop_menu_list_t *menu_list)
{
    drop_menu_list_t *temp = menu_list;

    while (temp) {
        sfRenderWindow_drawRectangleShape(window,
            temp->menu->button->rect, NULL);
        if (temp->menu->button->name)
            sfRenderWindow_drawText(window, temp->menu->button->name, NULL);
        disp_drop_menu(window, temp->menu);
        temp = temp->next;
    }
}

int delete_menu(drop_menu_list_t **bar, int menu_id)
{
    drop_menu_list_t *temp = *bar;
    drop_menu_list_t *prev = NULL;

    while (temp && temp->id != menu_id) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
        return ERROR_EXIT;
    if (prev == NULL)
        *bar = temp->next;
    else
        prev->next = temp->next;
    temp->menu->delete_menu(temp->menu);
    free(temp);
    return SUCCESS_EXIT;
}

int delete_menu_list(drop_menu_list_t *bar)
{
    int i = 0;

    while (bar->delete_menu(&bar, i) != ERROR_EXIT)
        i++;
    free(bar->menu);
    free(bar);
    return 0;
}

static int insert_menu(drop_menu_list_t *bar, s_gui_drop_menu_t *menu)
{
    static int id = 0;
    drop_menu_list_t *new_drop_menu = malloc(sizeof(drop_menu_list_t));

    if (bar->menu) {
        new_drop_menu->menu = menu;
        new_drop_menu->id = id;
        new_drop_menu->next = bar->next;
        bar->next = new_drop_menu;
        id++;
    } else {
        bar->menu = menu;
        free(new_drop_menu);
    }
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
