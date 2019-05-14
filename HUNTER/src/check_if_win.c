/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void verif_next_win(b_t *var, d_t *d)
{
	int a = 0;
	char *tmp = "lol";

	if (var->click >= 10){
		sfClock_restart(d->clock_since_zero);
		sfMusic_pause(var->music);
		a = menu(d->window, var, 0);
		if (a != 0)
			main(999, &tmp);
		else
			exit (0);
	}
}

void check_if_win(b_t *var, d_t *d)
{
	int a = 0;
	char *tmp = "lol";

	if (var->stock_ball == 0 && var->click <= 10) {
		sfClock_restart(d->clock_since_zero);
		sfMusic_pause(var->music);
		a = menu(d->window, var, 1);
		if (a != 0)
			main(999, &tmp);
		else
			exit (0);
	}
	verif_next_win(var, d);
}
