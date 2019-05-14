/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_scene(char **infos, char **type, hashmap_t **current_list,
	game_t *game)
{
	(void)infos;
	*current_list = SCENES;
	if (init_scene_lists(infos, game) != 0)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(*current_list, type[1]);
	return (0);
}

int get_list(char **infos, char **type, hashmap_t **current_list,
	game_t *game)
{
	scene_t *current_scene;

	if (check_undefined_scene(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	if (my_strcmp(type[1], "TEXTS") == 0) {
		current_scene = CURRENT_BUCKET->value;
		*current_list = current_scene->texts;
	}
	if (my_strcmp(type[1], "OBJS") == 0) {
		current_scene = CURRENT_BUCKET->value;
		*current_list = current_scene->objs;
	}
	(void)current_list;
	return (0);
}

int get_obj(char **infos, char **type, hashmap_t **current_list,
	game_t *game)
{
	if (check_undefined_scene(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	if (check_undefined_list(*current_list, infos[0]) != 0)
		return (84);
	if (init_an_obj(infos, game, *current_list) != 0)
		return (84);
	(void)type;
	return (0);
}

int get_text(char **infos, char **type, hashmap_t **current_list,
	game_t *game)
{
	if (check_undefined_scene(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	if (check_undefined_list(*current_list, infos[0]) != 0)
		return (84);
	if (init_a_text(infos, game, *current_list) != 0)
		return (84);
	(void)type;
	return (0);
}
