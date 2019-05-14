/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void show_second_scale(public_class_t *all)
{
	if (all->csfml_object->seconds_s_z >= 10)
		sfText_setPosition(all->csfml_object->show_second,
				   (sfVector2f){90, 0});
	else if (all->csfml_object->seconds_s_z >= 100)
		sfText_setPosition(all->csfml_object->show_second,
				   (sfVector2f){150, 0});
}
