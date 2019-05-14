/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** entity.c
*/

#include "rpg.h"

int init_monsters_lib(game_t *game)
{
	const key_word_t monster_keys[] = {
	{"MONSTERS", 0, &get_monster, NULL},
	{"TEXTURE", 0, &get_enemy_data_texture, NULL},
	{"ZONE", 0, &get_monster_zone, NULL},
	{"STATS", 3, &get_monster_stats, (char *[]) {"HEALTH", "ARMOR",
	"DAMAGES", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/monster.pcf", INIT_CHAR, monster_keys,
	&list_savior};

	MONSTERS_LIB = hm_create(64, &monster_destroy);
	if (!MONSTERS_LIB || analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN MONSTERS LIB INIT !\n");
		return (84);
	}
	return (0);
}

int init_npcs_lib(game_t *game)
{
	const key_word_t npc_keys[] = {
	{"NPC", 1, &get_npc, (char *[]) {"TEXTURE", NULL}},
	{"ZONE", 2, &get_npc_zone, (char *[]) {"X", "Y", NULL}},
	{"AREA", 2, &get_npc_area, (char *[]) {"X", "Y", NULL}},
	{"TILE", 2, &get_npc_tile, (char *[]) {"X", "Y", NULL}},
	{"ACTION", 0, &get_npc_action, NULL},
	{"LINE_01", 0, &get_npc_line_01, NULL},
	{"LINE_02", 0, &get_npc_line_02, NULL},
	{"LINE_03", 0, &get_npc_line_03, NULL},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/npc.pcf", INIT_CHAR, npc_keys,
	&list_savior};

	NPCS_LIB = hm_create(64, &npc_destroy);
	if (!NPCS_LIB || analyse_pcf(game, &infos) != 0) {
		my_printf("WARNING: ERROR IN NPCS LIB INIT !\n");
		return (84);
	}
	return (0);
}

int set_npc(bucket_t *npc_bucket, game_t *game)
{
	npc_t *npc = npc_bucket->value;
	scene_t *game_scene;

	if (ZONE_COOR_X != npc->zone.x || ZONE_COOR_Y != npc->zone.y)
		return (0);
	game_scene = hm_get(SCENES, "GAME");
	if (!game_scene || !npc)
		return (84);
	AREA_COOR_X = npc->area.x;
	AREA_COOR_Y = npc->area.y;
	TILE_COOR_X = npc->tile.x;
	TILE_COOR_Y = npc->tile.y;
	if (check_invalid_tile_coords(npc->name, game) != 0
	|| add_tile_to_list(npc->texture, game) != 0)
		return (84);
	if (my_strcmp(npc->texture, "EMPTY") == 0)
		return (0);
	TILE_BLOCK = 1;
	AREA.tiles[TILE_COOR_Y + 1][TILE_COOR_X].block = 1;
	return (0);
}