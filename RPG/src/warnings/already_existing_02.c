/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int check_already_existing_scene(bucket_t *scene, char *scene_name)
{
	if (scene != NULL) {
		my_printf("WARNING: SCENE '%s' IS REDECLARED !\n", scene_name);
		return (84);
	}
	return (0);
}

int check_already_existing_music(sfMusic *music, char *music_name)
{
	if (music != NULL) {
		my_printf("WARNING: SCENE CAN CONTAIN ONLY ONE MUSIC");
		my_printf(", PLEASE REMOVE '%s' !\n", music_name);
		return (84);
	}
	return (0);
}

int seek_zone_name(char *name, int y, game_t *game)
{
	for (int x = 0; x != ZONE_TAB_X; x++)
		if (my_fastcmp(MAP.zones[y][x].name, name) == 0)
			return (84);
	return (0);
}

int check_already_existing_zone_name(char *name, game_t *game)
{
	for (int y = 0; y != ZONE_TAB_Y; y++)
		if (seek_zone_name(name, y, game) != 0) {
			my_printf("WARNING: ZONE '%s' IS REDECLARED !\n", name);
			return (84);
		}
	return (0);
}

int check_already_existing_zone_coords(char *name, game_t *game)
{
	if (ZONE_NAME != NULL || ZONE_FILEPATH != NULL) {
		my_printf("WARNING: YOU ARE TRYING TO PUT ZONE '%s'", name);
		my_printf(" AT ZONE '%s' COORDINATES !\n", ZONE_NAME);
		return (84);
	}
	return (0);
}
