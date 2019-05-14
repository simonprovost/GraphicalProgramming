/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int new_game(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	(void)window;
	CURRENT_BUCKET = hm_get_bucket(SCENES, "NEW_GAME");
	if (check_unexisting_scene(CURRENT_BUCKET, "NEW_GAME") != 0)
		return (84);
	if (clean_displayed_scenes_and_add_back(game, "NEW_GAME") != 0)
		return (84);
	return (1);
}
