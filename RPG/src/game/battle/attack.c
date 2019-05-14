/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** select_enemy
*/

#include "rpg.h"

int enemy_turn(window_t *window, game_t *game)
{
	static int i = 0;

	while (i < 2 && !game->battle.enemy[i])
		i++;
	game->battle.selected_enemy = i;
	if (check_last_enemy(game, i)) {
		LAST_ENEMY_TURN = 1;
		i = -1;
		ENEMY_TURN = 0;
	} else
		LAST_ENEMY_TURN = 0;
	if (wait_for_enemy_attack(window, game, 1) == 84)
		return (84);
	i++;
	return (0);
}

int enemy_attack(window_t *window, game_t *game)
{
	float bonus = ((float)(rand() % (ENEMY_DAMAGES * 2))
	- (float)ENEMY_DAMAGES) / 10.0;
	int damages = MAX(ENEMY_DAMAGES + round(bonus) - PLAYER_ARMOR, 0);
	int critical_hit = rand() % 100;
	sfMusic *hit_sound = hm_get(AUDIO_LIB, "SHOOT_SOUND");

	if (critical_hit >= 95) {
		damages *= 2;
		display_special_hit_enemy(window, game, "CRITICAL_HIT");
	} else if (critical_hit < 5) {
		damages = 0;
		display_special_hit_enemy(window, game, "ATTACK_FAILED");
	}
	manage_hit_enemy(game, -1, damages);
	PLAYER_HEALTH -= damages;
	if (reset_enemy_turn(window, game) == 84 || !hit_sound)
		return (84);
	sfMusic_play(hit_sound);
	return (0);
}

int player_attack(window_t *window, game_t *game)
{
	float bonus = ((float)(rand() % (PLAYER_DAMAGES * 2))
	- (float)PLAYER_DAMAGES) / 10.0;
	int damages = MAX(PLAYER_DAMAGES + round(bonus) - ENEMY_ARMOR, 0);
	int critical_hit = rand() % 100;

	clean_displayed_scene_name(game, "ATTACK");
	if (critical_hit >= 95) {
		damages *= 2;
		display_special_hit_player(window, game, "CRITICAL_HIT");
	} else if (critical_hit < 5) {
		damages = 0;
		display_special_hit_player(window, game, "ATTACK_FAILED");
	}
	manage_hit_enemy(game, game->battle.selected_enemy + 1, damages);
	ENEMY_HEALTH -= damages;
	if (ENEMY_HEALTH <= 0)
		SELECTED_ENEMY = NULL;
	if (reset_player_turn(window, game) == 84)
		return (84);
	return (0);
}

int attack(window_t *window, game_t *game)
{
	bucket_t *bucket = hm_get_bucket(SCENES, "ATTACK");

	if (!window || !game || !bucket)
		return (84);
	add_scene_to_display_list(bucket, game);
	game->battle.selected_enemy = first_enemy_available(game);
	change_arrow_position(game);
	clean_displayed_scene_name(game, "BATTLE_BASIC_BUTTONS");
	return (1);
}