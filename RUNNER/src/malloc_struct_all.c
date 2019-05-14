/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void malloc_struct_all(public_class_t *all)
{
	all->player = malloc(sizeof(p_assets_t));
		all->csfml_object = malloc(sizeof(d_t));
		all->var = malloc(sizeof(b_t));
		all->my_object = malloc(sizeof(game_object_t *) * 5);
		all->my_pers = malloc(sizeof(game_object_t *) * 5);
}