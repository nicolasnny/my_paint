/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <stdbool.h>
    #include <SFML/Graphics.h>

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct surface_s {
    sfImage *surface_image;
    sfTexture *surface_texture;
    sfSprite *surface_sprite;
    sfColor color;
    sfColor last_color;
    int brush_size;
}surface_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
    int (*functionnality)(surface_t *, sfRenderWindow *);
    enum e_gui_state state;
    bool collidable;
    sfText *name;
    sfImage *image;
    sfVector2f position;
    sfVector2f size;
}button_t;

typedef struct s_gui_options_s {
    int id;
    button_t *option;
    struct s_gui_options_s *next;
}s_gui_options_t;

typedef struct s_gui_drop_menu_s {
    button_t *button;
    struct s_gui_options_s *options;
    int (*insert_option)(struct s_gui_drop_menu_s *menu, button_t *new_option);
    int (*delete_option)(struct s_gui_drop_menu_s **menu, int option_id);
    int (*delete_menu)(struct s_gui_drop_menu_s *menu);
}s_gui_drop_menu_t;

typedef struct drop_menu_list_s {
    int id;
    s_gui_drop_menu_t *menu;
    int (*insert_menu)(struct drop_menu_list_s *bar,
        s_gui_drop_menu_t *menu);
    int (*delete_menu)(struct drop_menu_list_s **bar, int menu_id);
    int (*delete_list)(struct drop_menu_list_s *bar);
    struct drop_menu_list_s *next;
} drop_menu_list_t;

typedef struct button_list_s {
    drop_menu_list_t *colors;
    drop_menu_list_t *edit_buttons;
    drop_menu_list_t *file_buttons;
} button_list_t;


#endif /*   STRUCT_H   */
