/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void clock_time_beginning(d_t *d, b_t *var)
{
	d->time_since_zero = sfClock_getElapsedTime(d->clock_since_zero);
	var->seconds_s_z = d->time_since_zero.microseconds / 1000000.00;
}
