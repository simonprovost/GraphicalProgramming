/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void map_savior(game_t *game)
{
	ZONE_COOR_X = -1;
	ZONE_COOR_Y = -1;
	AREA_COOR_X = -1;
	AREA_COOR_Y = -1;
	TILE_COOR_X = -1;
	TILE_COOR_Y = -1;
}

void list_savior(game_t *game)
{
	CURRENT_BUCKET = NULL;
}
