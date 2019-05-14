/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

int reload(window_t *window, game_t *game)
{
	int fd_player = open("bin/save/player.bin", O_RDONLY);
	int fd_npc = open("bin/save/npc.bin", O_RDONLY);

	if (!window || !game)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, LOAD_GAME);
	if (check_unexisting_scene(CURRENT_BUCKET, LOAD_GAME) != 0)
		return (84);
	if (clean_displayed_scenes_and_add_back(game, LOAD_GAME) != 0)
		return (84);
	if (fd_npc != -1 && fd_player != -1)
		if (load_save(fd_player, fd_npc, game) != 0)
			return (84);
	(void)window;
	return (1);
}
