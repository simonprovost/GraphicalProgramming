/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int stats(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	return (button_display_hide_scene(STATS_GAME,
		&update_stats, game, "GAME"));
}
