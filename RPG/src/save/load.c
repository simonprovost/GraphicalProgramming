/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** load.c
*/

#include "rpg.h"

int load_player(int fd_player, player_t *player)
{
	char buffer[sizeof(player_t) + 1];
	int bytes = 0;

	memset(buffer, 0, sizeof(player_t));
	bytes = read(fd_player, buffer, sizeof(player_t));
	if (bytes == -1)
		return (84);
	*player = *(player_t *)buffer;
	return (0);
}

int load_save(int fd_player, int fd_npc, game_t *game)
{
	player_t player;

	(void)fd_npc;
	(void)game;
	if (load_player(fd_player, &player) != 0)
		return (84);
	return (0);
}