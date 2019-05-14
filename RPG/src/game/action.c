/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** tiles.c
*/

#include "rpg.h"
#include "my.h"

static const action_t action_tab[] =
{
	{"TP", teleport},
	{"HEAL", heal},
	{"QUEST", quests},
	{"XP01", give_xp_01},
	{"BOSSBATTLE", init_boss_battle},
	{NULL, NULL},
};

int teleport(char **data_tp, game_t *game)
{
	unload_my_zone(game);
	ZONE_COOR_X = my_getnbr(data_tp[1]);
	ZONE_COOR_Y = my_getnbr(data_tp[2]);
	AREA_COOR_X = my_getnbr(data_tp[3]);
	AREA_COOR_Y = my_getnbr(data_tp[4]);
	TILE_COOR_X = my_getnbr(data_tp[5]);
	TILE_COOR_Y = my_getnbr(data_tp[6]);
	check_rain(game);
	if (load_my_zone(game) != 0)
		return (84);
	return (1);
}

int heal(char **data_heal, game_t *game)
{
	if (!game)
		return (84);
	(void)data_heal;
	PLAYER_HEALTH = PLAYER_MAX_HP;
	return (0);
}

int do_npc_action(npc_t *npc, game_t *game)
{
	char **action_desc = NULL;

	if (!npc->action)
		return (0);
	action_desc = my_str_to_word_array(npc->action, '_');
	if (!action_desc)
		return (84);
	for (int i = 0; action_tab[i].balise; i++)
		if (my_strcmp(action_desc[0], action_tab[i].balise) == 0)
			return (action_tab[i].fptr(action_desc, game));
	return (0);
}

int check_action_around(bucket_t *npc_bucket, game_t *game)
{
	npc_t *npc = npc_bucket->value;

	if (!npc)
		return (84);
	if (ZONE_COOR_X == npc->zone.x
	&& ZONE_COOR_Y == npc->zone.y
	&& AREA_COOR_X == npc->area.x
	&& AREA_COOR_Y == npc->area.y)
		return (compare_coords(npc, game, &do_npc_action));
	return (0);
}
