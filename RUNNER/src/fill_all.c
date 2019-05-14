/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void fill_all(public_class_t *all)
{
	fill_divers(all->csfml_object);
	fill_var(all->var);
	fill_assets_player(all->player);
	fill_object(all->my_object);
	add_type(all->my_object);
}
