/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"
#include "my.h"

int how_to_play(window_t *window, game_t *game)
{
	int my_errno = 0;

	if (!window || !game)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, "HOW_TO_PLAY");
	if (check_unexisting_scene(CURRENT_BUCKET, "HOW_TO_PLAY") != 0)
		return (84);
	my_errno = clean_displayed_scenes_and_add_back(game, "HOW_TO_PLAY");
	if (my_errno == 84)
		return (84);
	(void)window;
	return (1);
}