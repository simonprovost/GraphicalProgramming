/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_runner.h"

void move_player(sfIntRect *rect_player, b_t *var)
{
	rect_player->top = 0;
	rect_player->left = var->offset_player;
	rect_player->width = (170);
	rect_player->height = 400;
}

void time_clock(d_t *d, b_t *var, int len)
{
	d->time = sfClock_getElapsedTime(d->clock);
	var->seconds = d->time.microseconds / len;
	if (var->seconds > 1.0) {
		if (var->offset_player >= 750)
			var->offset_player = 0;
		move_player(&d->rect_player, var);
		var->offset_player += 190;
		sfClock_restart(d->clock);
	}
}