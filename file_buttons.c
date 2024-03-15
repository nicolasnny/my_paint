/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** file_buttons.c
*/

#include "include/my_paint.h"
#include "include/struct.h"

s_gui_drop_menu_t *init_file_menu(void)
{
    s_gui_drop_menu_t *file_menu;
    button_t *file_menu_button = init_button((sfVector2f){0, 0},
        (sfVector2f){150, 70}, NULL);
    button_t *new_file_button = init_button((sfVector2f){0, -70},
        (sfVector2f){150, 50}, &new_file);
    button_t *open_file_button = init_button((sfVector2f){0, -120},
        (sfVector2f){150, 50}, &open_file);
    button_t *save_file_button = init_button((sfVector2f){0, -165},
        (sfVector2f){150, 50}, &save_file);

    set_button_text(file_menu_button, "FILE");
    set_button_text(new_file_button, "NEW FILE");
    set_button_text(open_file_button, "OPEN FILE");
    set_button_text(save_file_button, "SAVE FILE");
    file_menu = new_drop_menu(file_menu_button);
    file_menu->insert_option(file_menu, new_file_button);
    file_menu->insert_option(file_menu, open_file_button);
    file_menu->insert_option(file_menu, save_file_button);
    return file_menu;
}

s_gui_drop_menu_t *init_edit_menu(void)
{
    s_gui_drop_menu_t *edit_menu;
    button_t *edit_menu_button = init_button((sfVector2f){-170, 0},
        (sfVector2f){150, 70}, NULL);
    button_t *pencil_button = init_button((sfVector2f){-170, -70},
        (sfVector2f){150, 70}, NULL);
    button_t *rubber_button = init_button((sfVector2f){-170, -140},
        (sfVector2f){150, 70}, &set_rubber);

    set_button_text(edit_menu_button, "EDIT");
    set_button_image(pencil_button, "assets/pencil.png");
    set_button_image(rubber_button, "assets/rubber.png");
    edit_menu = new_drop_menu(edit_menu_button);
    edit_menu->insert_option(edit_menu, pencil_button);
    edit_menu->insert_option(edit_menu, rubber_button);
    return edit_menu;
}

s_gui_drop_menu_t *init_help_menu(void)
{
    s_gui_drop_menu_t *help_menu;
    button_t *help_menu_button = init_button((sfVector2f){-340, 0},
        (sfVector2f){150, 70}, NULL);
    button_t *about_button = init_button((sfVector2f){-340, -70},
        (sfVector2f){150, 70}, &disp_about);
    button_t *help_button = init_button((sfVector2f){-340, -140},
        (sfVector2f){150, 70}, &disp_help);

    set_button_text(help_menu_button, "HELP");
    set_button_text(about_button, "ABOUT");
    set_button_text(help_button, "HELP");
    help_menu = new_drop_menu(help_menu_button);
    help_menu->insert_option(help_menu, about_button);
    help_menu->insert_option(help_menu, help_button);
    return help_menu;
}

drop_menu_list_t *init_file_buttons(void)
{
    drop_menu_list_t *file_menu_list = new_drop_menu_list();
    s_gui_drop_menu_t *file_menu = init_file_menu();
    s_gui_drop_menu_t *edit_menu = init_edit_menu();
    s_gui_drop_menu_t *about_menu = init_help_menu();

    file_menu_list->insert_menu(file_menu_list, file_menu);
    file_menu_list->insert_menu(file_menu_list, edit_menu);
    file_menu_list->insert_menu(file_menu_list, about_menu);
    return file_menu_list;
}
