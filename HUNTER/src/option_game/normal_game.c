/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void normal_game(b_t *var, s_t *s, v_t *v, d_t *d)
{
	clock_time_beginning(d, var);
	sfRenderWindow_clear(d->window, sfBlack);
	poll_event(d, v, var);
	position_cible(d, v, s);
	time_clock(d, var, 100000.0);
	new_position_duck(v, var, var->variant, s);
	show_new_window(d, s);
	check_my_amazing_duck(var, d, s, v);
	draw_display(d, s, var);
}
