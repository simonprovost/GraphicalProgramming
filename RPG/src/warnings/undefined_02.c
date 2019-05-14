/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_undefined(bucket_t *data, char *data_name, char *data_type)
{
	if (!data) {
		my_printf("WARNING: YOU ASKED FOR '%s' ", data_name);
		my_printf("DATA BUT %s ISN'T DEFINED !\n", data_type);
		return (84);
	}
	return (0);
}

int check_undefined_item(bucket_t *item, char *data)
{
	if (!item) {
		my_printf("WARNING: YOU ASKED FOR '%s' ", data);
		my_printf("DATA BUT ITEM ISN'T DEFINED !\n");
		return (84);
	}
	return (0);
}

int check_undefined_monster(bucket_t *monster, char *data)
{
	if (!monster) {
		my_printf("WARNING: YOU ASKED FOR '%s' ", data);
		my_printf("DATA BUT MONSTER ISN'T DEFINED !\n");
		return (84);
	}
	return (0);
}

int check_undefined_zone_line(int y, char *zone_name, game_t *game)
{
	for (int x = 0; x != ZONE_TAB_X; x++) {
		if (my_strcmp(MAP.zones[y][x].name, zone_name) == 0)
			return (0);
	}
	return (84);
}

int check_undefined_zone(char *zone_name, game_t *game)
{
	int my_errno = 0;

	for (int y = 0; y != ZONE_TAB_Y; y++)
		my_errno += check_undefined_zone_line(y, zone_name, game);
	if (my_errno == 0) {
		my_printf("WARNING: YOU ARE TRYING TO PUT A MONSTER ");
		my_printf("IN '%s' BUT ZONE IS UNDEFINED !\n",
		zone_name);
		return (84);
	}
	return (0);
}