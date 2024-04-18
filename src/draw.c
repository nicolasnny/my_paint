/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-nicolas.nunney
** File description:
** draw.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <string.h>
#include "struct.h"
#include "my_paint.h"

void clear_surface(surface_t *surface)
{
    sfUint8 *pixel_array = malloc(sizeof(sfUint8) * RGBA *
        SURFACE_WIDTH * SURFACE_HEIGHT + 1);

    sfImage_destroy(surface->surface_image);
    sfTexture_destroy(surface->surface_texture);
    sfSprite_destroy(surface->surface_sprite);
    memset(pixel_array, 255, sizeof(sfUint8) * RGBA * SURFACE_WIDTH *
        SURFACE_HEIGHT + 1);
    surface->surface_image = sfImage_createFromPixels(SURFACE_WIDTH,
        SURFACE_HEIGHT, pixel_array);
    surface->surface_texture =
        sfTexture_createFromImage(surface->surface_image, NULL);
    surface->surface_sprite = sfSprite_create();
    sfSprite_setTexture(surface->surface_sprite,
        surface->surface_texture, sfTrue);
    sfSprite_setPosition(surface->surface_sprite, (sfVector2f){X_OFFSET,
        Y_OFFSET});
}

surface_t *init_surface(void)
{
    surface_t *surface = malloc(sizeof(surface_t));
    sfUint8 *pixel_array = malloc(sizeof(sfUint8) * RGBA *
        SURFACE_WIDTH * SURFACE_HEIGHT + 1);

    memset(pixel_array, 255, sizeof(sfUint8) * RGBA * SURFACE_WIDTH *
        SURFACE_HEIGHT + 1);
    surface->surface_image = sfImage_createFromPixels(SURFACE_WIDTH,
        SURFACE_HEIGHT, pixel_array);
    surface->surface_texture =
        sfTexture_createFromImage(surface->surface_image, NULL);
    surface->surface_sprite = sfSprite_create();
    sfSprite_setTexture(surface->surface_sprite,
        surface->surface_texture, sfTrue);
    sfSprite_setPosition(surface->surface_sprite, (sfVector2f){X_OFFSET,
        Y_OFFSET});
    surface->color = sfBlack;
    surface->last_color = surface->color;
    surface->brush_size = DEFAULT_BRUSH_SIZE;
    return surface;
}

static void color_pixels(surface_t *surface, sfVector2i *coords, int size)
{
    for (int i = coords->x; i != coords->x + size; i++) {
        for (int j = coords->y; j != coords->y + size &&
            j + size < DEFAULT_HEIGHT - BOTTOM_GAP; j++)
            sfImage_setPixel(surface->surface_image, i, j, surface->color);
    }
    sfTexture_updateFromImage(surface->surface_texture,
        surface->surface_image, 0, 0);
}

bool check_pixel_coord(surface_t *surface, sfVector2i *coords,
    int image_coords[2])
{
    if (coords->x == image_coords[0] && coords->y == image_coords[1]) {
        color_pixels(surface, coords, surface->brush_size);
        return true;
    }
    return false;
}

void draw_on_image(surface_t *surface, sfVector2i *coords)
{
    bool pixel_found = false;
    int image_coords[2];

    for (int i = 0; i < SURFACE_WIDTH && !pixel_found; i++) {
        for (int j = 0; j < SURFACE_HEIGHT && !pixel_found; j++) {
            image_coords[0] = i;
            image_coords[1] = j;
            pixel_found = check_pixel_coord(surface, coords, image_coords);
        }
    }
}

void check_drawing(surface_t *surface, sfWindow *window)
{
    sfVector2i mouse_coords = sfMouse_getPosition(window);
    sfVector2i adjusted_coords;

    adjusted_coords.x = mouse_coords.x - X_OFFSET;
    adjusted_coords.y = mouse_coords.y - Y_OFFSET;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        draw_on_image(surface, &adjusted_coords);
}
