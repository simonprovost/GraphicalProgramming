/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int quetes(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	return (button_display_hide_scene(QUESTS_GAME, NULL, game, "GAME"));
}
