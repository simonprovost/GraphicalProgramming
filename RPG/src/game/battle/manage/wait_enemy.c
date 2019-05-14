/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** wait_enemy
*/

#include "rpg.h"

int check_timer_enemy(window_t *window, game_t *game, int *a)
{
	get_time(&window->clocker);
	if (*a == 1 && window->clocker.seconds >= 2) {
		*a = 0;
		clean_displayed_scene_name(game, "ENEMY_TURN");
		enemy_attack(window, game);
		return (1);
	}
	return (0);
}

int wait_for_enemy_attack(window_t *window, game_t *game, bool wait)
{
	bucket_t *special = NULL;
	static int a = 0;

	if (check_timer_enemy(window, game, &a) == 1)
		return (0);
	if (!wait)
		return (0);
	special = hm_get_bucket(SCENES, "ENEMY_TURN");
	if (!special)
		return (84);
	add_scene_to_display_list(special, game);
	sfClock_restart(window->clocker.clock);
	a = 1;
	return (1);
}