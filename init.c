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

void check_events(sfRenderWindow *window, button_t *button)
{
    sfEvent *event = malloc(sizeof(sfEvent));

    while (sfRenderWindow_pollEvent(window, event)){
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (button->is_hover(button, &event->mouseMove))
            printf("hovered\n");
        if (event->type == sfEvtMouseButtonPressed &&
            button->is_clicked(button, &event->mouseButton)) {
                continue;
        }
    }
}

int init(void)
{
    sfRenderWindow *paint = sfRenderWindow_create(
        (sfVideoMode){1920, 1080, 32}, "paint", sfResize | sfClose, NULL);
    button_t *play_button = init_button((sfVector2f){100, -100},
        (sfVector2f){200, 100});
    s_gui_drop_menu_t *file_menu = new_drop_menu(play_button);

    while (sfRenderWindow_isOpen(paint)) {
        sfRenderWindow_clear(paint, sfWhite);
        check_events(paint, play_button);
        sfRenderWindow_drawRectangleShape(paint, play_button->rect, NULL);
        sfRenderWindow_display(paint);
    }
}
