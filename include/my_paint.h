/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** my_paint.h
*/

#ifndef MY_PAINT
    #define MY_PAINT
    #define ERROR_EXIT 84
    #define SUCCESS_EXIT 0
    #include <SFML/Graphics.h>
    #include "struct.h"



sfBool is_hover(button_t *button, sfMouseMoveEvent *event);
sfBool is_clicked(button_t *button, sfMouseButtonEvent *event);
button_t *init_button(sfVector2f position, sfVector2f size);
int init(void);
s_gui_drop_menu_t *new_drop_menu(button_t *menu_button);
void disp_drop_menu(sfRenderWindow *window, s_gui_drop_menu_t *menu);
drop_menu_list_t *new_drop_menu_list(void);
void check_menu_disp(sfRenderWindow *window, drop_menu_list_t *menu_list);
void check_menu_list_event(sfEvent *event, drop_menu_list_t *menu_list);

#endif /* MY_PAINT */
