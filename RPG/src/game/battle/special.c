/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** special
*/

#include "rpg.h"

int process_special(window_t *window, game_t *game,
				sfText *using_special, sfText *used_special)
{
	int damages = PLAYER_SPECIALITY;
	sfMusic *boom = hm_get(AUDIO_LIB, "BOOM_SOUND");

	sfText_setString(using_special, "YOU    HIT    ALL    ENEMIES");
	sfText_setString(used_special, " ");
	display_special_hit_player(window, game, "USE_SPECIAL");
	manage_hit_enemy(game, 2, damages);
	for (int i = 0; i < 3; i++) {
		if (ENEMY[i])
			ENEMY[i]->stats.health -= damages;
		if (ENEMY[i] && ENEMY[i]->stats.health <= 0)
			ENEMY[i] = NULL;
	}
	if (reset_player_turn(window, game) == 84 || !boom)
		return (84);
	sfMusic_play(boom);
	return (1);
}

int use_special(window_t *window, game_t *game)
{
	bucket_t *bucket = hm_get_bucket(SCENES, "USE_SPECIAL");
	scene_t *scene = hm_get(SCENES, "USE_SPECIAL");
	sfText *used_special;
	sfText *using_special;

	if (!window || !game || !bucket || !scene)
		return (84);
	used_special = hm_get(scene->texts, "WHO");
	using_special = hm_get(scene->texts, "SPECIAL");
	if (!game->battle.used_special) {
		return (process_special(window, game,
		using_special, used_special));
	} else {
		sfText_setString(used_special,
		"YOU    ALREADY    USED    SPECIAL");
		sfText_setString(using_special, " ");
		display_special_hit_player(window, game, "USE_SPECIAL");
	}
	return (0);
}