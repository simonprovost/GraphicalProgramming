/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** npc.c
*/

#include "rpg.h"

int get_npc_line_01(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	npc_t *npc;

	if (check_undefined(CURRENT_BUCKET, type[0], "NPC") != 0)
		return (84);
	npc = CURRENT_BUCKET->value;
	if (!npc)
		return (84);
	npc->line_01 = my_strdup(type[1]);
	my_replace_char(npc->line_01, '_', ' ');
	(void)current_list;
	(void)infos;
	return (0);
}

int get_npc_line_02(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	npc_t *npc;

	if (check_undefined(CURRENT_BUCKET, type[0], "NPC") != 0)
		return (84);
	npc = CURRENT_BUCKET->value;
	if (!npc)
		return (84);
	npc->line_02 = my_strdup(type[1]);
	my_replace_char(npc->line_02, '_', ' ');
	(void)current_list;
	(void)infos;
	return (0);
}

int get_npc_line_03(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	npc_t *npc;

	if (check_undefined(CURRENT_BUCKET, type[0], "NPC") != 0)
		return (84);
	npc = CURRENT_BUCKET->value;
	if (!npc)
		return (84);
	npc->line_03 = my_strdup(type[1]);
	my_replace_char(npc->line_03, '_', ' ');
	(void)current_list;
	(void)infos;
	return (0);
}

int get_npc_action(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	npc_t *npc;

	if (check_undefined(CURRENT_BUCKET, type[0], "NPC") != 0)
		return (84);
	npc = CURRENT_BUCKET->value;
	if (!npc)
		return (84);
	npc->action = my_strdup(type[1]);
	(void)current_list;
	(void)infos;
	return (0);
}
