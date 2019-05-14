/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int hide_scene(char *scene_name, game_t *game, char *old_scene)
{
	make_sound("CURSOR_SOUND", game);
	CURRENT_BUCKET = hm_get_bucket(SCENES, old_scene);
	if (check_unexisting_scene(CURRENT_BUCKET, old_scene) != 0)
		return (84);
	clean_displayed_scene_name(game, scene_name);
	return (0);
}

int button_display_hide_scene(char *scene_name, void (*fptr)(), game_t *game,
				char *old_scene)
{
	managed_scene_t *displayed_scene = get_scene_from_displayed(scene_name,
	game);
	scene_t *scene = hm_get(SCENES, scene_name);

	if (displayed_scene) {
		if (hide_scene(scene_name, game, old_scene) != 0)
			return (84);
	} else {
		CURRENT_BUCKET = hm_get_bucket(SCENES, scene_name);
		if (check_unexisting_scene(CURRENT_BUCKET, scene_name) != 0)
			return (84);
		if (fptr)
			fptr(scene, game);
		if (add_scene_to_display_list(hm_get_bucket(SCENES, scene_name),
		game) != 0 || make_sound("CURSOR_SOUND", game) == 2)
			return (84);
	}
	return (0);
}
