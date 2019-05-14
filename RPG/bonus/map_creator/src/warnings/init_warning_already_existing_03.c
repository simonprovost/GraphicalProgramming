/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int seek_area_name(char *name, int y, my_w_t *window)
{
	for (int x = 0; x != AREA_TAB_X; x++)
		if (my_fastcmp(window->map.areas[y][x].name, name) == 0)
			return (84);
	return (0);
}

int check_already_existing_area_name(char *name, my_w_t *window)
{
	for (int y = 0; y != AREA_TAB_Y; y++)
		if (seek_area_name(name, y, window) != 0) {
			my_printf("WARNING: AREA '%s' IS REDECLARED !\n", name);
			return (84);
		}
	return (0);
}

int check_already_existing_area_coords(char *name, my_w_t *window)
{
	if (AREA_NAME != NULL) {
		my_printf("WARNING: YOU ARE TRYING TO PUT AREA '%s'", name);
		my_printf(" AT AREA '%s' COORDINATES !\n", AREA_NAME);
		return (84);
	}
	return (0);
}

int check_already_existing_tile_coords(my_w_t *window)
{
	if (TILE_COOR_X != -1 && TILE_LIST != NULL) {
		my_printf("WARNING: YOU ARE TRYING TO PUT 2 TILES AT ");
		my_printf("COORDINATES (%d/%d) IN AREA '%s' !\n",
		TILE_COOR_X, TILE_COOR_Y, AREA_NAME);
		return (84);
	}
	return (0);
}
