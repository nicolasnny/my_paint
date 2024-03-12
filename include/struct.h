/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <SFML/Graphics.h>

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
    enum e_gui_state state;
}button_t;

typedef struct s_gui_options_s {
    int id;
    button_t *option;
    struct s_gui_options_s *next;
}s_gui_options_t;

typedef struct s_gui_drop_menu_s {
    struct button_t *button;
    struct s_gui_options_s *options;
    int (*insert_option)(struct s_gui_drop_menu_s *menu, button_t *new_option);
    int (*delete_option)(struct s_gui_drop_menu_s **menu, int option_id);
    int (*delete_menu)(struct s_gui_drop_menu_s *menu);
}s_gui_drop_menu_t;

#endif /*   STRUCT_H   */
