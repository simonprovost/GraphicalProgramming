/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void destroy_all(public_class_t *all)
{
	destroy_clock(all);
	destroy_sprite(all);
	destroy_texture(all);
	destroy_window(all);
}