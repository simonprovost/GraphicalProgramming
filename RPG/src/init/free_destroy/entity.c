/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** entity.c
*/

#include "rpg.h"

void npc_destroy(npc_t *npc)
{
	free(npc->name);
	free(npc->texture);
	free(npc->line_01);
	free(npc->line_02);
	free(npc->line_03);
	free(npc);
}

void monster_destroy(enemy_data_t *monster)
{
	free(monster->name);
	free(monster->zone);
	free(monster->texture);
	free(monster);
}