/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_scene(managed_scene_t *scene, window_t *window, game_t *game)
{
	if (my_strcmp(scene->name, MAP_SCENE_NAME) == 0)
		if (display_map(window, game) != 0)
			return (84);
	if (display_objs(scene->scene->objs, window) != 0)
		return (84);
	if (read_hashmap(window, NULL, scene->scene->texts,
		&display_texts) != 0)
		return (84);
	return (0);
}
