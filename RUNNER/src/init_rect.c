/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void next_init_rect(public_class_t *all)
{
	all->my_object[3]->rect.top = 0;
	all->my_object[3]->rect.left = 0;
	all->my_object[3]->rect.width = 0;
	all->my_object[3]->rect.height = 0;
	all->my_object[4]->rect.top = 0;
	all->my_object[4]->rect.left = 0;
	all->my_object[4]->rect.width = 0;
	all->my_object[4]->rect.height = 0;
}

void init_rect(public_class_t *all)
{
	all->my_object[0]->rect.top = 0;
	all->my_object[0]->rect.left = 0;
	all->my_object[0]->rect.width = 0;
	all->my_object[0]->rect.height = 0;
	all->my_object[1]->rect.top = 0;
	all->my_object[1]->rect.left = 0;
	all->my_object[1]->rect.width = 0;
	all->my_object[1]->rect.height = 0;
	all->my_object[2]->rect.top = 0;
	all->my_object[2]->rect.left = 0;
	all->my_object[2]->rect.width = 0;
	all->my_object[2]->rect.height = 0;
	next_init_rect(all);
}