/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** file_managment.c
*/

#include "my_paint.h"
#include "struct.h"

int save_file(surface_t *surface, sfRenderWindow *window)
{
    (void)window;
    (void)surface;
    sfImage_saveToFile(surface->surface_image, "paint_image.jpg");
    return SUCCESS_EXIT;
}

int new_file(surface_t *surface, sfRenderWindow *window)
{
    (void)window;
    (void)surface;
    clear_surface(surface);
    return SUCCESS_EXIT;
}

int open_file(surface_t *surface, sfRenderWindow *window)
{
    (void)window;
    (void)surface;
    return SUCCESS_EXIT;
}
