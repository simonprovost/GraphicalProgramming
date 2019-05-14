/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void update_stat(int value, char *wanted, scene_t *scene)
{
	char *space = ":  ";
	char *value_string = int_to_str(value);
	char *display = my_strcat(space, value_string);
	sfText *actual = hm_get(scene->texts, wanted);

	if (actual)
		sfText_setString(actual, display);
	free(value_string);
	free(display);
}

void update_stats(scene_t *scene, game_t *game)
{
	update_stat(PLAYER_HEALTH, "HEALTH", scene);
	update_stat(PLAYER_ARMOR, "ARMOR", scene);
	update_stat(PLAYER_SPECIALITY, "SPECIAL", scene);
	update_stat(PLAYER_SPECIALITY, "DAMAGES", scene);
	update_stat(PLAYER_XP, "XP", scene);
	update_stat(PLAYER_LEVEL, "LEVEL", scene);
}
