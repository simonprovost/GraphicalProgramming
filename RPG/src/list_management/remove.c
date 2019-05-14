/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void clean_displayed_tiles(tile_list_t *displayed)
{
	tile_list_t *tmp;

	while (displayed) {
		tmp = displayed;
		displayed = tmp->next;
		obj_destroy(tmp->tile);
		free(tmp);
	}
}

void clean_displayed_scenes(game_t *game)
{
	managed_scene_t *tmp;

	while (MANAGED_SCENES) {
		tmp = MANAGED_SCENES;
		MANAGED_SCENES = tmp->next;
		destroy_managed_scene(tmp);
	}
}

void clean_displayed_scene_name(game_t *game, char *name_scenes)
{
	managed_scene_t *tmp = MANAGED_SCENES;
	managed_scene_t *freed;

	while (tmp) {
		if (tmp->next != NULL &&
		my_strcmp(tmp->next->name, name_scenes) == 0) {
			freed = tmp->next;
			tmp->next = tmp->next->next;
			destroy_managed_scene(freed);
			break;
		}
		tmp = tmp->next;
	}
}

int clean_displayed_scenes_and_add_back(game_t *game, char *scene_name)
{
	managed_scene_t *tmp;
	bucket_t *scene = NULL;
	int already_in = 0;

	while (MANAGED_SCENES) {
		tmp = MANAGED_SCENES;
		MANAGED_SCENES = tmp->next;
		if (my_strcmp(scene_name, tmp->name) != 0) {
			destroy_managed_scene(tmp);
		} else
			already_in = 1;
	}
	if (already_in == 0) {
		scene = hm_get_bucket(SCENES, scene_name);
		MANAGED_SCENES = NULL;
		if (check_unexisting_scene(scene, scene_name) != 0)
			return (84);
		return (add_scene_to_display_list(scene, game));
	}
	return (0);
}
