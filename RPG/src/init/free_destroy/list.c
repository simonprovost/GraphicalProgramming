/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** list.c
*/

#include "rpg.h"

void destroy_managed_scene(managed_scene_t *managed)
{
	if (managed) {
		if (managed->name) {
			free(managed->name);
		}
		free(managed);
	}
}