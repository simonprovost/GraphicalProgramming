/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** npc.c
*/

#include "rpg.h"

int get_npc(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	char **texture = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	npc_t *npc;

	if (!texture)
		return (84);
	npc = create_npc(type[1], texture[1]);
	if (!npc)
		return (84);
	*current_list = NPCS_LIB;
	if (check_already_existing(*current_list, type[1], "NPC.PCF") != 0)
		return (84);
	hm_add(*current_list, type[1], npc);
	CURRENT_BUCKET = hm_get_bucket(*current_list, type[1]);
	my_destroy_tab(texture);
	return (0);
}

int get_npc_zone(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	npc_t *npc;
	char **x = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined(CURRENT_BUCKET, type[0], "NPC") != 0)
		return (84);
	npc = CURRENT_BUCKET->value;
	if (!npc || !x || !y)
		return (84);
	npc->zone = V2I(my_getnbr(x[1]), my_getnbr(y[1]));
	(void)current_list;
	return (0);
}

int get_npc_area(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	npc_t *npc;
	char **x = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined(CURRENT_BUCKET, type[0], "NPC") != 0)
		return (84);
	npc = CURRENT_BUCKET->value;
	if (!npc || !x || !y)
		return (84);
	npc->area = V2I(my_getnbr(x[1]), my_getnbr(y[1]));
	(void)current_list;
	return (0);
}

int get_npc_tile(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	npc_t *npc;
	char **x = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);

	if (check_undefined(CURRENT_BUCKET, type[0], "NPC") != 0)
		return (84);
	npc = CURRENT_BUCKET->value;
	if (!npc || !x || !y)
		return (84);
	npc->tile = V2I(my_getnbr(x[1]), my_getnbr(y[1]));
	(void)current_list;
	return (0);
}