/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int credits(window_t *window, game_t *game)
{
	int my_errno = 0;

	if (!window || !game)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, CREDITS_GAME);
	if (check_unexisting_scene(CURRENT_BUCKET, CREDITS_GAME) != 0)
		return (84);
	my_errno = clean_displayed_scenes_and_add_back(game, CREDITS_GAME);
	if (my_errno == 84)
		return (84);
	(void)window;
	return (1);
}
