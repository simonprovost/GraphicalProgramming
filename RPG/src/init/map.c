/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "rpg.h"

void init_zone(game_t *game)
{
	for (int y = 0; y != ZONE_TAB_Y; y++)
		for (int x = 0; x != ZONE_TAB_X; x++) {
			MAP.zones[y][x].name = NULL;
			MAP.zones[y][x].filepath = NULL;
		}
}

void init_displayed_tiles(int x, int y, game_t *game)
{
	for (int j = 0; j != TILE_TAB_Y; j++)
		for (int i = 0; i != TILE_TAB_X; i++)
			MAP.areas[y][x].tiles[j][i].displayed_tiles = NULL;
}

void init_area(game_t *game)
{
	for (int y = 0; y != AREA_TAB_Y; y++) {
		for (int x = 0; x != AREA_TAB_X; x++) {
			MAP.areas[y][x].name = NULL;
			init_displayed_tiles(x, y, game);
		}
	}
}

int init_map(game_t *game)
{
	const key_word_t map_keys[] = {
	{"ZONE", 3, &get_map, (char *[]) {"FILEPATH", "X", "Y", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/map.pcf", INIT_CHAR, map_keys,
	&map_savior};

	init_zone(game);
	init_area(game);
	if (analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN MAP INIT !\n");
		return (84);
	}
	return (0);
}
