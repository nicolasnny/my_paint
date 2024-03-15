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
    #define DEFAULT_WIDTH 1920
    #define DEFAULT_HEIGHT 1080
    #define SURFACE_WIDTH 1880
    #define SURFACE_HEIGHT 800
    #define DEFAULT_BRUSH_SIZE 10
    #define X_OFFSET DEFAULT_WIDTH / 2 - SURFACE_WIDTH / 2
    #define Y_OFFSET DEFAULT_HEIGHT / 2 - SURFACE_HEIGHT / 2 + 100
    #include <SFML/Graphics.h>
    #include "struct.h"

sfBool is_hover(button_t *button, sfMouseMoveEvent *event);
sfBool is_clicked(button_t *button, sfMouseButtonEvent *event);
button_t *init_button(sfVector2f position, sfVector2f size,
    int (*functionnality)(surface_t *, sfRenderWindow *));
int init(void);
s_gui_drop_menu_t *new_drop_menu(button_t *menu_button);
void disp_drop_menu(sfRenderWindow *window, s_gui_drop_menu_t *menu);
drop_menu_list_t *new_drop_menu_list(void);
void check_menu_disp(sfRenderWindow *window, drop_menu_list_t *menu_list);
void check_menu_list_event(sfEvent *event, drop_menu_list_t *menu_list);
surface_t *init_surface(void);
void check_drawing(surface_t *surface, sfWindow *window);
void check_is_clicked(sfEvent *event, drop_menu_list_t *menu_list,
    surface_t *surface, sfRenderWindow *window);
drop_menu_list_t *init_color_buttons(void);
int set_button_image(button_t *button, char *image_filepath);
int set_button_text(button_t *button, char *button_text);
int set_color(surface_t *surface,
    sfRenderWindow *window, button_t *color_button);
drop_menu_list_t *init_edit_buttons(void);
int set_rubber(surface_t *surface, sfRenderWindow *window);
int small_size(surface_t *surface, sfRenderWindow *window);
int medium_size(surface_t *surface, sfRenderWindow *window);
int large_size(surface_t *surface, sfRenderWindow *window);
void check_menu_clicked(drop_menu_list_t *menu_list, sfEvent *event,
    surface_t *surface, sfRenderWindow *window);
drop_menu_list_t *init_file_buttons(void);
int save_file(surface_t *surface, sfRenderWindow *window);
int new_file(surface_t *surface, sfRenderWindow *window);
int open_file(surface_t *surface, sfRenderWindow *window);
int disp_help(surface_t *surface, sfRenderWindow *window);
int disp_about(surface_t *surface, sfRenderWindow *window);
void clear_surface(surface_t *surface);
int set_pencil(surface_t *surface, sfRenderWindow *window);

#endif /* MY_PAINT */
