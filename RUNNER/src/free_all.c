/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void free_all(public_class_t *all)
{
	free(all->var->map);
	free(all->my_object[0]);
	free(all->my_object[1]);
	free(all->my_object[2]);
	free(all->my_object[3]);
	free(all->my_object[4]);
	free(all->my_pers[0]);
	free(all->my_object);
	free(all->my_pers);
	free(all->csfml_object);
	free(all->player);
	free(all->var);
	free(all->enemy);
	free(all);
}