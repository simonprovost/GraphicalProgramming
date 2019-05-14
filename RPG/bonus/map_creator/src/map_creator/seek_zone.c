/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** seek_zone
*/

#include "map_editor.h"

int seek_zone_horizontaly(my_w_t *window, char *zone_name)
{
	for (; ZONE_COOR_X != ZONE_TAB_X; ZONE_COOR_X++) {
		if (ZONE_NAME && !my_strcmp(zone_name, ZONE_NAME))
			return (1);
	}
	return (0);
}

int seek_zone(my_w_t *window, char *zone_name)
{
	ZONE_COOR_X = 0;
	ZONE_COOR_Y = 0;
	for (; ZONE_COOR_Y != ZONE_TAB_Y; ZONE_COOR_Y++) {
		if (seek_zone_horizontaly(window, zone_name) != 0)
			return (1);
	}
	return (0);
}