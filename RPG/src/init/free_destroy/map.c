/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void map_destroy(game_t *game)
{
	unload_my_zone(game);
	for (int y = 0; y != ZONE_COOR_Y; y++) {
		for (int x = 0; x != ZONE_COOR_X; x++) {
			free(MAP.zones[y][x].name);
			free(MAP.zones[y][x].filepath);
		}
	}
}