/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

void destroy_texture(public_class_t *all)
{
	sfTexture_destroy(all->my_pers[0]->my_texture);
	sfTexture_destroy(all->my_object[0]->my_texture);
	sfTexture_destroy(all->my_object[1]->my_texture);
	sfTexture_destroy(all->my_object[2]->my_texture);
	sfTexture_destroy(all->my_object[3]->my_texture);
	sfTexture_destroy(all->my_object[4]->my_texture);
}
