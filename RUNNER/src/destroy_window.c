/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void destroy_window(public_class_t *all)
{
	sfRenderWindow_destroy(all->csfml_object->window);
}
