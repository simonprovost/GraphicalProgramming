/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void poll_event(d_t *d)
{
	while (sfRenderWindow_pollEvent(d->window, &d->event)) {
		sfRenderWindow_clear(d->window, sfBlack);
		if (d->event.type == sfEvtClosed)
			sfRenderWindow_close(d->window);
	}
}