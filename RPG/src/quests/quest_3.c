/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest_3
*/

#include "rpg.h"

int quest_3(game_t *game)
{
	npc_t *tyler = hm_get(NPCS_LIB, "Tyler");

	if (!tyler)
		return (84);
	if (!my_strcmp(tyler->line_03, " zone is enchanted."))
		return (0);
	make_sound("NEW_QUEST", game);
	tyler->line_03 = my_strdup(" zone is enchanted.");
	add_xp_to_player(game, 400);
	if (update_quest_scene("The Lost Girl (main) :",
	"The ogre hide in\nDestiny Lake, North\nfrom here.\nThe way is hidden.",
	game) != 0)
		return (84);
	return (0);
}