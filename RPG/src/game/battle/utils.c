/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** utils
*/

#include "rpg.h"

char *get_item_rarity(char *item)
{
	if (item[0] == 'C')
		return ("COMMON");
	else if (item[0] == 'R')
		return ("RARE");
	else if (item[0] == 'E')
		return ("EPIC");
	return ("MYTHIC");
}

char *get_item_type(char *item)
{
	int i = 0;

	while (item[i] != '_')
		i++;
	i++;
	if (item[i] == 'C')
		return ("CHEST");
	if (item[i] == 'H')
		return ("HELMET");
	if (item[i] == 'G')
		return ("GAUNTLETS");
	if (item[i] == 'P')
		return ("PANTS");
	if (item[i] == 'B')
		return ("BOW");
	if (item[i] == 'W')
		return ("WAND");
	return ("SWORD");
}