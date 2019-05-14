/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int quit(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, QUIT_GAME);
	if (check_unexisting_scene(CURRENT_BUCKET, QUIT_GAME) != 0)
		return (84);
	if (clean_displayed_scenes_and_add_back(game, QUIT_GAME) != 0)
		return (84);
	(void)window;
	return (1);
}
