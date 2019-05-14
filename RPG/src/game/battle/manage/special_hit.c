/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** special_hit
*/

#include "rpg.h"

void check_timer_special_enemy(window_t *window, game_t *game,
							int *a, char *save)
{
	get_time(&window->clocker);
	if (*a == 1 && window->clocker.seconds >= 2) {
		*a = 0;
		SPECIAL_HIT = 0;
		if (!game->battle.lose)
			reset_enemy_turn(window, game);
		clean_displayed_scene_name(game, save);
	}
}

void check_timer_special_player(window_t *window, game_t *game,
							int *a, char *save)
{
	get_time(&window->clocker);
	if (*a == 1 && window->clocker.seconds >= 2) {
		*a = 0;
		SPECIAL_HIT = 0;
		if (!my_strcmp(save, "USE_SPECIAL")
		&& game->battle.used_special) {
			add_scene_to_display_list(hm_get_bucket(SCENES,
						"BATTLE_BASIC_BUTTONS"), game);
			clean_displayed_scene_name(game, save);
			return;
		}
		if (!my_strcmp(save, "USE_SPECIAL"))
			game->battle.used_special = 1;
		if (!game->battle.win)
			reset_player_turn(window, game);
		clean_displayed_scene_name(game, save);
	}
}

int display_special_hit_player(window_t *window, game_t *game, char *scene)
{
	bucket_t *special = NULL;
	static int a = 0;
	static char *save = NULL;

	check_timer_special_player(window, game, &a, save);
	if (!scene)
		return (0);
	SPECIAL_HIT = 1;
	special = hm_get_bucket(SCENES, scene);
	if (!special)
		return (84);
	clean_displayed_scene_name(game, "BATTLE_BASIC_BUTTONS");
	clean_displayed_scene_name(game, "ENEMY_TURN");
	add_scene_to_display_list(special, game);
	sfClock_restart(window->clocker.clock);
	save = scene;
	a = 1;
	return (1);
}

int display_special_hit_enemy(window_t *window, game_t *game, char *scene)
{
	bucket_t *special = NULL;
	static int a = 0;
	static char *save = NULL;

	check_timer_special_enemy(window, game, &a, save);
	if (!scene)
		return (0);
	SPECIAL_HIT = 1;
	special = hm_get_bucket(SCENES, scene);
	if (!special)
		return (84);
	clean_displayed_scene_name(game, "BATTLE_BASIC_BUTTONS");
	clean_displayed_scene_name(game, "ENEMY_TURN");
	add_scene_to_display_list(special, game);
	sfClock_restart(window->clocker.clock);
	save = scene;
	a = 1;
	return (0);
}
