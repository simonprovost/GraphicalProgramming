/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest_2
*/

#include "rpg.h"

int quest_2(game_t *game)
{
	npc_t *npc = hm_get(NPCS_LIB, "Lee'nas");

	if (!npc)
		return (84);
	if (!my_strcmp(npc->line_01, "I hate ogres! I want to kill them all."))
		return (0);
	make_sound("NEW_QUEST", game);
	npc->line_01 = my_strdup("I hate ogres! I want to kill them all.");
	npc->line_02 = my_strdup(" ");
	npc->line_03 = my_strdup(" ");
	add_xp_to_player(game, 200);
	if (update_quest_scene("The Lost Girl (main) :",
	"An ogre expert is in\nthe Cursed Forest,\nEast from here.\nI should \
talk to him.",
	game) != 0)
		return (84);
	return (0);
}