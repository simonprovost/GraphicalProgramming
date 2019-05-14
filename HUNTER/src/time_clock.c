/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

void time_clock(d_t *d, b_t *var, int len)
{
	d->time = sfClock_getElapsedTime(d->clock);
	var->seconds = d->time.microseconds / len;
	if (var->seconds > 1.0) {
		if (var->offset >= 330)
			var->offset = 0;
		move_rect(&d->rect, var);
		var->offset += 110;
		sfClock_restart(d->clock);
	}
}
