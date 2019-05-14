/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

void poll_event(d_t *d, v_t *v, b_t *var)
{
	while (sfRenderWindow_pollEvent(d->window, &d->event)) {
		sfRenderWindow_clear(d->window, sfBlack);
		if (d->event.type == sfEvtClosed)
			sfRenderWindow_close(d->window);
		if (d->event.type == sfEvtMouseButtonPressed)
			var->check_duck = manage_mouse_click(d->window, v);
	}
}
