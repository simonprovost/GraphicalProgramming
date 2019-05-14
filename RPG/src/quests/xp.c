/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** xp
*/

#include "rpg.h"

int give_xp_01(char **data_xp, game_t *game)
{
	int nb = 0;
	static int passage = 0;

	if (passage == 1)
		return (0);
	if (!data_xp)
		return (84);
	nb = my_getnbr(data_xp[1]);
	add_xp_to_player(game, nb);
	passage = 1;
	return (0);
}

int give_xp_02(char **data_xp, game_t *game)
{
	int nb = 0;
	static int passage = 0;

	if (passage == 1)
		return (0);
	if (!data_xp)
		return (84);
	nb = my_getnbr(data_xp[1]);
	add_xp_to_player(game, nb);
	passage = 1;
	return (0);
}

int give_xp_03(char **data_xp, game_t *game)
{
	int nb = 0;
	static int passage = 0;

	if (passage == 1)
		return (0);
	if (!data_xp)
		return (84);
	nb = my_getnbr(data_xp[1]);
	add_xp_to_player(game, nb);
	passage = 1;
	return (0);
}