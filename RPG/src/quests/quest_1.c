/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** quest_1
*/

#include "rpg.h"

int remove_more(scene_t *scene)
{
	sfText *more_01 = hm_get(scene->texts, "MORE_01");
	sfText *more_02 = hm_get(scene->texts, "MORE_02");
	sfText *more_03 = hm_get(scene->texts, "MORE_03");

	if (!more_01 || !more_02 || !more_03)
		return (84);
	sfText_setString(more_01, "");
	sfText_setString(more_02, "");
	sfText_setString(more_03, "");
	return (0);
}

int update_quest_scene(char *quest_name, char *instruction, game_t *game)
{
	scene_t *scene = hm_get(SCENES, "QUESTS");
	sfText *name;
	sfText *line;
	static sfBool pass = sfFalse;

	if (!scene)
		return (84);
	name = hm_get(scene->texts, "MAIN");
	line = hm_get(scene->texts, "MORE");
	if (!name || !line)
		return (84);
	sfText_setString(name, quest_name);
	sfText_setString(line, instruction);
	if (pass == sfFalse) {
		pass = sfTrue;
		if (remove_more(scene) != 0)
			return (84);
	}
	return (0);
}

int quest_1(game_t *game)
{
	npc_t *npc = hm_get(NPCS_LIB, "Caleof");

	if (!npc)
		return (84);
	if (!my_strcmp(npc->line_01, "You may have to look for information,")
	|| !my_strcmp(npc->line_01, "Thanks to you, i found back my beloved"))
		return (0);
	make_sound("NEW_QUEST", game);
	npc->line_01 = my_strdup("You may have to look for information,");
	npc->line_02 = my_strdup( \
			" you should start with the tavern. Please hurry!");
	npc->line_03 = my_strdup(" ");
	if (update_quest_scene("The Lost Girl (main) :",
	"Caleof's daughter has\n been kidnapped by\nan ogre.\nI should seek \
for\n information.",
	game) != 0)
		return (84);
	return (0);
}

int quests(char **action, game_t *game)
{
	int nbr = 0;

	if (!action || !game)
		return (84);
	nbr = my_getnbr(action[1]);
	if (nbr == 1)
		quest_1(game);
	else if (nbr == 2)
		quest_2(game);
	else
		quest_3(game);
	return (0);
}