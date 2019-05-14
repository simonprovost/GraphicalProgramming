/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int save(window_t *window, game_t *game)
{
	bucket_t *scene = hm_get_bucket(SCENES, SAVE_GAME);

	if (!window || !game || !scene)
		return (0);
	clean_displayed_scene_name(game, PAUSE_GAME);
	if (add_scene_to_display_list(scene, game) != 0)
		return (84);
	(void)window;
	return (1);
}

int yes_save(window_t *window, game_t *game)
{
	bucket_t *scene = hm_get_bucket(SCENES, PAUSE_GAME);

	if (!window || !game || !scene)
		return (0);
	clean_displayed_scene_name(game, SAVE_GAME);
	if (add_scene_to_display_list(scene, game) != 0)
		return (84);
	if (save_game(game) != 0)
		return (84);
	(void)window;
	return (1);
}

int no_save(window_t *window, game_t *game)
{
	bucket_t *scene = hm_get_bucket(SCENES, PAUSE_GAME);

	if (!window || !game || !scene)
		return (0);
	clean_displayed_scene_name(game, SAVE_GAME);
	if (add_scene_to_display_list(scene, game) != 0)
		return (84);
	(void)window;
	return (1);
}