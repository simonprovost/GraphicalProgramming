/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int check_undefined_scene(bucket_t *scene, char *asked_list)
{
	if (!scene) {
		my_printf("WARNING: YOU ASKED FOR '%s' DATA BUT SCENE ISN'T ",
		asked_list);
		my_printf("DEFINED !\n");
		return (84);
	}
	return (0);
}

int check_undefined_texture(bucket_t *texture, char *data)
{
	if (!texture) {
		my_printf("WARNING: YOU ASKED FOR '%s' ", data);
		my_printf("DATA BUT TEXTURE ISN'T DEFINED !\n");
		return (84);
	}
	return (0);
}

int check_undefined_list(hashmap_t *current_list, char *obj)
{
	if (!current_list) {
		my_printf("WARNING: YOU TRIED TO CREATE '%s' ", obj);
		my_printf("BUT YOU DIDN'T SPECIFIED A LIST !\n");
		return (84);
	}
	return (0);
}

int check_undefined_area(my_w_t *window)
{
	if (AREA_COOR_X == -1 || AREA_COOR_Y == -1) {
		my_printf("WARNING: YOU TRIED TO ADD A TILE AT %d/%d BUT",
		TILE_COOR_X, TILE_COOR_Y);
		my_printf(" YOU DIDN'T SPECIFIED AN AREA IN ZONE '%s' !\n",
		ZONE_NAME);
		return (84);
	}
	return (0);
}

int check_undefined_tile(my_w_t *window)
{
	if (TILE_COOR_X == -1 || TILE_COOR_Y == -1) {
		my_printf("WARNING: YOU TRIED TO ADD TEXTURE '%s' BUT YOU ");
		my_printf("DIDN'T SPECIFIED A TILE FOR AREA '%s' !\n",
		AREA_NAME);
		return (84);
	}
	return (0);
}
