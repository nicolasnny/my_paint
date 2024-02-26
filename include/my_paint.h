/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** my_paint.h
*/

#ifndef MY_PAINT
    #define MY_PAINT
    #include <SFML/Graphics.h>
    #include "struct.h"

sfBool is_hover(button_t *button, sfMouseButtonEvent *event);
sfBool is_clicked(button_t *button, sfMouseButtonEvent *event);
button_t *init_button(sfVector2f position, sfVector2f size);
int init(void);

#endif /* MY_PAINT */