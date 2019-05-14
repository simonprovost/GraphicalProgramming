/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** loot
*/

#include "rpg.h"

char *compute_slot(game_t *game)
{
	int random = rand() % 5;

	switch (random) {
		case 0:
			return ("PANTS_01");
		case 1:
			return ("GAUNTLETS_01");
		case 2:
			return ("HELMET_01");
		case 3:
			return ("CHEST_01");
	}
	if (!my_strcmp(PLAYER_NAME, "Avelus"))
		return ("BOW_01");
	else if (!my_strcmp(PLAYER_NAME, "Varyan"))
		return ("SWORD_01");
	return ("WAND_01");
}

char *common_rare(game_t *game)
{
	int random = rand() % 100;

	if (random < 15)
		return (my_strcat("RARE_", compute_slot(game)));
	else if (random >= 40)
		return (my_strcat("COMMON_", compute_slot(game)));
	return (NULL);
}

char *rare_epic(game_t *game)
{
	int random = rand() % 100;

	if (random < 15)
		return (my_strcat("EPIC_", compute_slot(game)));
	else if (random >= 40)
		return (my_strcat("RARE_", compute_slot(game)));
	return (NULL);
}

char *epic_mythic(game_t *game)
{
	int random = rand() % 100;

	if (random < 15)
		return (my_strcat("MYTHIC_", compute_slot(game)));
	else if (random >= 40)
		return (my_strcat("EPIC_", compute_slot(game)));
	return (NULL);
}

char *compute_loot(game_t *game)
{
	char *item = NULL;

	if (!my_strcmp(ZONE_NAME, "MORIA"))
		item = common_rare(game);
	else if (!my_strcmp(ZONE_NAME, "CURSED_FOREST"))
		item = rare_epic(game);
	else
		item = epic_mythic(game);
	return (item);
}