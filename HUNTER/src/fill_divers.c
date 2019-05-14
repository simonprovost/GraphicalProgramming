/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

void fill_divers(d_t *d)
{
	char *n = "Epi_Duck / 2017-2018";

	d->mode.width = 800;
	d->mode.height = 600;
	d->mode.bitsPerPixel = 32;
	d->clock = sfClock_create();
	d->clock_since_zero = sfClock_create();
	d->rect.top = 0;
	d->rect.left = 0;
	d->rect.width = 110;
	d->rect.height = 110;
	d->window = sfRenderWindow_create(d->mode, n, sfResize | sfClose, NULL);
}
