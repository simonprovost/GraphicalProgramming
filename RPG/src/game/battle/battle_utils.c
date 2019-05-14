/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** battle_utils
*/

#include "rpg.h"

int all_enemies_dead(game_t *game)
{
	if (!game->battle.enemy[0]
	&& !game->battle.enemy[1]
	&& !game->battle.enemy[2])
		return (1);
	return (0);
}

int check_last_enemy(game_t *game, int i)
{
	if (i == 0) {
		if (!game->battle.enemy[1] && !game->battle.enemy[2])
			return (1);
	} else if (i == 1) {
		if (!game->battle.enemy[2])
			return (1);
	} else
		return (1);
	return (0);
}

int first_enemy_available(game_t *game)
{
	if (game->battle.enemy[0])
		return (0);
	if (game->battle.enemy[1])
		return (1);
	return (2);
}

int reset_enemy_turn(window_t *window, game_t *game)
{
	bucket_t *bucket = hm_get_bucket(SCENES, "BATTLE_BASIC_BUTTONS");

	if (PLAYER_HEALTH <= 0) {
		sfClock_restart(window->clocker.clock);
		game->battle.lose = 1;
		return (0);
	}
	if (!bucket)
		return (84);
	if (LAST_ENEMY_TURN && !SPECIAL_HIT) {
		PLAYER_TURN = 1;
		ENEMY_TURN = 0;
		add_scene_to_display_list(bucket, game);
	} else if (!SPECIAL_HIT)
		enemy_turn(window, game);
	return (0);
}

int reset_player_turn(window_t *window, game_t *game)
{
	if (all_enemies_dead(game)) {
		sfClock_restart(window->clocker.clock);
		game->battle.win = 1;
		return (0);
	}
	if (!SPECIAL_HIT) {
		if (enemy_turn(window, game) == 84)
			return (84);
		PLAYER_TURN = 0;
		ENEMY_TURN = 1;
	}
	return (0);
}