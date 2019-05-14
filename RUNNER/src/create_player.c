/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void create_player(public_class_t *all)
{
	all->my_pers[0] = create_object("ressources/mouse_fly.png",
					(sfVector2f){20, 450},
					(sfIntRect){0,0, (162), 156});
}