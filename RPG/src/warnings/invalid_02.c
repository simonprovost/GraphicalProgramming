/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_invalid_animated(sfBool animated)
{
	if (animated != sfTrue && animated != sfFalse) {
		my_printf("WARNING: ANIMATED VALUE CAN ONLY BE '0' ");
		my_printf("FOR FALSE OR '1' FOR TRUE !\n");
		return (84);
	}
	return (0);
}

int check_invalid_quest(sfBool quest)
{
	if (quest != sfTrue && quest != sfFalse) {
		my_printf("WARNING: QUEST VALUE CAN ONLY BE '0' ");
		my_printf("FOR FALSE OR '1' FOR TRUE !\n");
		return (84);
	}
	return (0);
}

int check_invalid_area_coords(char *name, game_t *game)
{
	if (AREA_ENCOUNTER != sfTrue && AREA_ENCOUNTER != sfFalse) {
		my_printf("WARNING: AREA '%s' ENCOUNTER IS %d BUT",
		AREA_NAME, AREA_ENCOUNTER);
		my_printf(" SHOULD BE 0 OR 1 !\n");
		return (84);
	}
	if (AREA_COOR_X < 0 || AREA_COOR_X >= AREA_TAB_X
		|| AREA_COOR_Y < 0 || AREA_COOR_Y >= AREA_TAB_Y) {
		my_printf("WARNING: INVALID AREA '%s' COORDS", name);
		my_printf(". HAVE TO BE 0 < X < %d AND 0 < Y < %d !\n",
		AREA_TAB_X, AREA_TAB_Y);
		return (84);
	}
	return (0);
}

int check_invalid_tile_coords(char *name, game_t *game)
{
	if (TILE_BLOCK != sfTrue && TILE_BLOCK != sfFalse) {
		my_printf("WARNING: IN AREA '%s', TILE BLOCK IS %d BUT",
		AREA_NAME, TILE_BLOCK);
		my_printf(" SHOULD BE 0 OR 1 !\n");
		return (84);
	}
	if (TILE_COOR_X < 0 || TILE_COOR_X >= TILE_TAB_X
		|| TILE_COOR_Y < 0 || TILE_COOR_Y >= TILE_TAB_Y) {
		my_printf("WARNING: INVALID TILE COORDS IN ZONE '%s'", name);
		my_printf(". HAVE TO BE 0 < X < %d AND 0 < Y < %d !\n",
		TILE_TAB_X, TILE_TAB_Y);
		return (84);
	}
	return (0);
}

int check_invalid_priority(int priority, char *texture_name)
{
	if (priority < 0 || priority > PRIORITY_MAX) {
		my_printf("WARNING: INVALID PRIORITY FOR THE TEXTURE");
		my_printf(" '%s'. HAVE TO STICK BETWEEN 0 AND %d",
		texture_name, PRIORITY_MAX);
		return (84);
	}
	return (0);
}
