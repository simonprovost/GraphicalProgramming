/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** run_away
*/

#include "rpg.h"

int run_away(window_t *window, game_t *game)
{
	int run = rand() % 100;

	if (!window || !game)
		return (84);
	if (ENEMY[0] && !my_strcmp(ENEMY[0]->name, "MAD_OGRE"))
		run = 0;
	if (run >= 85) {
		display_special_hit_player(window, game, "RUN_SUCCESS");
		game->battle.run_away = 1;
	} else
		display_special_hit_player(window, game, "RUN_FAIL");
	return (1);
}

int check_run_away(game_t *game)
{
	if (game->battle.run_away && !SPECIAL_HIT) {
		clean_displayed_scenes_and_add_back(game, "GAME");
		add_scene_to_display_list(hm_get_bucket(SCENES,
							"HEALTH_HUD"), game);
		add_scene_to_display_list(hm_get_bucket(SCENES,
							"AREA_HUD"), game);
		CURRENT_BUCKET = hm_get_bucket(SCENES, "GAME");
		stop_battle_music(game);
		sfRectangleShape_setPosition(PLAYER_CHARACTER->obj,
		V2F(TARGET_TILE.x * 50, TARGET_TILE.y * 50));
		return (1);
	}
	return (0);
}