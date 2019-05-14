/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** tiles.c
*/

#include "rpg.h"
#include "my.h"

int get_npc_dialogue(npc_t *npc, game_t *game)
{
	if (my_strcmp(npc->line_01, "RANDOM") == 0
	|| my_strcmp(npc->line_02, "RANDOM") == 0
	|| my_strcmp(npc->line_03, "RANDOM") == 0)
		return (update_random_pnj_dialogue(npc->name, game));
	return (update_pnj_dialogue(npc, game));
}

int compare_coords(npc_t *npc, game_t *game, int (*fptr)())
{
	sfVector2i tile = npc->tile;

	if ((TILE_COOR_X == tile.x && TILE_COOR_Y == tile.y)
	|| (TILE_COOR_X + 1 == tile.x && TILE_COOR_Y == tile.y)
	|| (TILE_COOR_X - 1 == tile.x && TILE_COOR_Y == tile.y)
	|| (TILE_COOR_X == tile.x && TILE_COOR_Y + 1 == tile.y)
	|| (TILE_COOR_X == tile.x && TILE_COOR_Y - 1 == tile.y)
	|| (TILE_COOR_X + 1 == tile.x && TILE_COOR_Y + 1 == tile.y)
	|| (TILE_COOR_X - 1 == tile.x && TILE_COOR_Y + 1 == tile.y)
	|| (TILE_COOR_X == tile.x && TILE_COOR_Y + 2 == tile.y)) {
		return (fptr(npc, game));
	}
	return (0);
}

int check_dialogue_around(bucket_t *npc_bucket, game_t *game)
{
	npc_t *npc = npc_bucket->value;

	if (!npc)
		return (84);
	if (ZONE_COOR_X == npc->zone.x
	&& ZONE_COOR_Y == npc->zone.y
	&& AREA_COOR_X == npc->area.x
	&& AREA_COOR_Y == npc->area.y)
		return (compare_coords(npc, game, &get_npc_dialogue));
	return (0);
}

int process_npc_dialogue(game_t *game)
{
	int my_errno = 0;

	my_errno = read_hashmap(NULL, game, NPCS_LIB, &check_dialogue_around);
	if (my_errno != 0) {
		return (my_errno == 1 ? 0 : 84);
	}
	if (update_nothing_here(game) != 0)
		return (84);
	return (0);
}

int process_npc_action(game_t *game)
{
	int my_errno = 0;

	my_errno = read_hashmap(NULL, game, NPCS_LIB, &check_action_around);
	if (my_errno != 0) {
		return (my_errno);
	}
	return (0);
}