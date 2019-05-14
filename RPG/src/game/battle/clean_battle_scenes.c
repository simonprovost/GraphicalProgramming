/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** clean_battle_scenes
*/

#include "rpg.h"

int stop_battle_music(game_t *game)
{
	scene_t *scene = hm_get(SCENES, "BATTLE");

	if (!scene)
		return (84);
	sfMusic_stop(scene->music.music);
	return (0);
}

void lose_tp(game_t *game)
{
	unload_my_zone(game);
	ZONE_COOR_X = 0;
	ZONE_COOR_Y = 0;
	AREA_COOR_X = 0;
	AREA_COOR_Y = 0;
	TILE_COOR_X = 7;
	TILE_COOR_Y = 4;
	load_my_zone(game);
}

void win_tp(game_t *game)
{
	npc_t *npc = hm_get(NPCS_LIB, "Jassie");
	npc_t *caleof = hm_get(NPCS_LIB, "Caleof");

	npc->zone = V2I(0, 0);
	npc->area = V2I(0, 0);
	npc->tile = V2I(9, 8);
	npc->line_01 = my_strdup("Thank you so much to have saved me.");
	npc->line_02 = \
	my_strdup("I will be grateful for it during my whole life");
	caleof->line_01 = my_strdup("Thanks to you, i found back my beloved");
	caleof->line_02 = my_strdup(" ");
	caleof->line_03 = my_strdup(" ");
	unload_my_zone(game);
	ZONE_COOR_X = 0;
	ZONE_COOR_Y = 0;
	AREA_COOR_X = 0;
	AREA_COOR_Y = 0;
	TILE_COOR_X = 7;
	TILE_COOR_Y = 4;
	load_my_zone(game);
}

void clean_battle_scenes(game_t *game)
{
	stop_battle_music(game);
	clean_displayed_scenes_and_add_back(game, "GAME");
	add_scene_to_display_list(hm_get_bucket(SCENES, "WIN_SCREEN"), game);
	add_scene_to_display_list(hm_get_bucket(SCENES, "HEALTH_HUD"), game);
	add_scene_to_display_list(hm_get_bucket(SCENES, "AREA_HUD"), game);
	CURRENT_BUCKET = hm_get_bucket(SCENES, "WIN_SCREEN");
	sfRectangleShape_setPosition(PLAYER_CHARACTER->obj, PLAYER_POS);
}