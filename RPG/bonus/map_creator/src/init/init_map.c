/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

void unload_my_tiles(my_w_t *window)
{
	if (AREA_NAME != NULL)
		clean_displayed_tiles(window);
}

void unload_my_area(my_w_t *window)
{
	TILE_COOR_X = 0;
	TILE_COOR_Y = 0;
	for (; TILE_COOR_Y != TILE_TAB_Y; TILE_COOR_Y++)
		for (; TILE_COOR_X != TILE_TAB_X; TILE_COOR_X++)
			unload_my_tiles(window);

}

void unload_my_zone(my_w_t *window)
{
	sfVector2i area_pos = {.x = AREA_COOR_X, .y= AREA_COOR_Y};
	sfVector2i tile_pos = {.x = TILE_COOR_X, .y= TILE_COOR_Y};

	AREA_COOR_X = 0;
	AREA_COOR_Y = 0;
	for (; AREA_COOR_Y != AREA_TAB_Y; AREA_COOR_Y++)
		for (; AREA_COOR_X != AREA_TAB_X; AREA_COOR_X++)
			unload_my_area(window);
	AREA_COOR_X = area_pos.x;
	AREA_COOR_Y = area_pos.y;
	TILE_COOR_X = tile_pos.x;
	TILE_COOR_Y = tile_pos.y;
}

int load_my_zone(my_w_t *window)
{
	const key_word_t zone_keys[] = {
	{"AREA", 3, &get_an_area, (char *[]) {"ENCOUNTER", "X", "Y", NULL}},
	{"TILE", 3, &get_a_tile, (char *[]) {"BLOCK", "X", "Y", NULL}},
	{"TEXTURE", 0, &get_a_tile_texture, NULL}, {NULL, 0, NULL, NULL}};
	get_infos_t infos = {ZONE_FILEPATH, INIT_INDICATOR, zone_keys,
		&map_savior};
	sfVector2f zone_pos = (sfVector2f){ZONE_COOR_X, ZONE_COOR_Y};

	if (check_unexisting_zone(ZONE_NAME) != 0)
		return (84);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		ZONE_COOR_X = zone_pos.x;
		ZONE_COOR_Y = zone_pos.y;
		my_printf("WARNING: ERROR IN ZONE '%s' INIT !\n", ZONE_NAME);
		return (84);
	}
	ZONE_COOR_X = zone_pos.x;
	ZONE_COOR_Y = zone_pos.y;
	return (0);
}

int init_map(my_w_t *window)
{
	const key_word_t map_keys[] = {
	{"ZONE", 3, &get_a_map, (char *[]) {"FILEPATH", "X", "Y", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/map.pcf", INIT_INDICATOR, map_keys,
	&map_savior};

	for (int y = 0; y != ZONE_TAB_Y; y++)
		for (int x = 0; x != ZONE_TAB_X; x++) {
			window->map.zones[y][x].name = NULL;
			window->map.zones[y][x].filepath = NULL;
		}
	for (int y = 0; y != AREA_TAB_Y; y++)
		for (int x = 0; x != AREA_TAB_X; x++)
			window->map.areas[y][x].name = NULL;
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN MAP INIT !\n");
		return (84);
	}
	return (0);
}
