/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void destroy_clock(public_class_t *all)
{
	sfClock_destroy(all->csfml_object->clock);
	sfClock_destroy(all->csfml_object->clock_since_zero);
}
