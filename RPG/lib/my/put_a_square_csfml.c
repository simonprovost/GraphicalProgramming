/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (put_a_square of a given size a a given place)
*/

#include "../../include/my.h"

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
	sfColor color)
{
	int i = (y * framebuffer->width + x) * 4;

	framebuffer->pixels[i] = color.r;
	framebuffer->pixels[i + 1] = color.g;
	framebuffer->pixels[i + 2] = color.b;
	framebuffer->pixels[i + 3] = color.a;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
	unsigned int i = 0;

	framebuffer->width = width;
	framebuffer->height = height;
	framebuffer->pixels = malloc(width * height * 32 / 4);
	while (i < (width * height * 32 / 4)) {
		framebuffer->pixels[i] = 0;
		i++;
	}
	return (framebuffer);
}

framebuffer_t *draw_square(sfVector2f *size, sfColor *color)
{
	framebuffer_t *framebuffer = framebuffer_create(size->x, size->y);
	int x = 0;
	int y = 0;

	for (int i = 0; i < size->y; i++) {
		for (int j = 0; j < size->x; j++) {
			my_put_pixel(framebuffer, x, y, *color);
			x++;
		}
		x = size->x;
		y += 1;
	}
	return (framebuffer);
}

void place_a_square(sfVector2f *size, sfVector2f *pos,
	sfRenderWindow *window, sfColor *color)
{
	sfTexture *texture = sfTexture_create(size->x, size->y);
	sfSprite *sprite = sfSprite_create();
	framebuffer_t *framebuffer = draw_square(size, color);

	sfTexture_updateFromPixels(texture, framebuffer->pixels,
	size->x, size->y, 0, 0);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, *pos);
	sfRenderWindow_drawSprite(window, sprite, NULL);
}
