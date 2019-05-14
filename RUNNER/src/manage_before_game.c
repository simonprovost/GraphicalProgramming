/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void manage_before_game(public_class_t *all)
{
	malloc_struct_all(all);
	fill_all(all);
	create_player(all);
	init_rect(all);
}