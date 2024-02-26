/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <SFML/Graphics.h>


typedef struct button_s{
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s*, sfMouseButtonEvent*);
    sfBool (*is_hover)(struct button_s*, sfMouseButtonEvent*);
} button_t;


#endif /*   STRUCT_H   */