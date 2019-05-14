/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** lobby.c
*/

#include "rpg.h"

int save_npc(hashmap_t *hashmap)
{
	int fd = open("bin/save/npc.bin",
	O_RDWR | O_CREAT | O_TRUNC, 00777);

	if (fd == -1) {
		return (84);
	}
	if (write(fd, hashmap, sizeof(hashmap)) == -1) {
		return (84);
	}
	return (0);
}

int save_player(player_t *player)
{
	int fd = open("bin/save/player.bin",
	O_RDWR | O_CREAT | O_TRUNC, 00777);

	if (fd == -1) {
		return (84);
	}
	if (write(fd, player, sizeof(player_t)) == -1) {
		return (84);
	}
	return (0);
}

int save_game(game_t *game)
{
	if (save_npc(NPCS_LIB) != 0
	|| save_player(&PLAYER) != 0)
		return (84);
	return (0);
}