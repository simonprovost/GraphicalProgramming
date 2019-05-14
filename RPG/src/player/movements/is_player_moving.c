/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** is_player_moving.c created: 19/04/18
*/

#include <rpg.h>

bool is_player_moving(game_t *game)
{
	if (is_pressing_controls(game))
		return (true);
	return (false);
}

void update_moving_state(game_t *game)
{
	game->movement.is_moving = is_player_moving(game);
}