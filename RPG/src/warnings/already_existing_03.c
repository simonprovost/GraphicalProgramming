/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int seek_area_name(char *name, int y, game_t *game)
{
	for (int x = 0; x != AREA_TAB_X; x++)
		if (my_fastcmp(MAP.areas[y][x].name, name) == 0)
			return (84);
	return (0);
}

int check_already_existing_area_name(char *name, game_t *game)
{
	for (int y = 0; y != AREA_TAB_Y; y++)
		if (seek_area_name(name, y, game) != 0) {
			my_printf("WARNING: AREA '%s' IS REDECLARED !\n", name);
			return (84);
		}
	return (0);
}

int check_already_existing_area_coords(char *name, game_t *game)
{
	if (AREA_NAME != NULL) {
		my_printf("WARNING: YOU ARE TRYING TO PUT AREA '%s'", name);
		my_printf(" AT AREA '%s' COORDINATES !\n", AREA_NAME);
		return (84);
	}
	return (0);
}

int check_already_existing_tile_coords(game_t *game)
{
	if (TILE_LIST != NULL) {
		my_printf("WARNING: YOU ARE TRYING TO PUT 2 TILES AT ");
		my_printf("COORDINATES (%d/%d) IN AREA '%s' !\n",
		TILE_COOR_X, TILE_COOR_Y, AREA_NAME);
		return (84);
	}
	return (0);
}

int check_already_existing_item(hashmap_t *hashmap, char *item_name)
{
	item_t *item = hm_get(hashmap, item_name);

	if (item != NULL) {
		my_printf("WARNING: ITEM '%s' REDECLARED IN ITEMS.PCF !\n",
		item_name);
		return (84);
	}
	return (0);
}
