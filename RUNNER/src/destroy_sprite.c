/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void destroy_sprite(public_class_t *all)
{
	sfSprite_destroy(all->my_pers[0]->my_sprite);
	sfSprite_destroy((all->my_object[0]->my_sprite));
	sfSprite_destroy((all->my_object[1]->my_sprite));
	sfSprite_destroy((all->my_object[2]->my_sprite));
	sfSprite_destroy((all->my_object[3]->my_sprite));
	sfSprite_destroy((all->my_object[4]->my_sprite));
}
