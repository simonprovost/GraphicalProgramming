/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** battle.c
*/

#include "rpg.h"

void init_battle(game_t *game)
{
	STEP_TO_BATTLE = (rand() % 20 + 11) * 2;
	SPECIAL_HIT = 0;
	LAST_ENEMY_TURN = 0;
	ENEMY_TURN = 0;
	PLAYER_TURN = 1;
	NBR_ENEMIES = 0;
	for (int i = 0; i != 3; i++)
		game->battle.enemy[i] = NULL;
}