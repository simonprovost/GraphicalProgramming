/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void destroy_and_free(window_t *window, game_t *game)
{
	clean_displayed_scenes(game);
	destroy_libs(game);
	clocks_destroy(game, window);
	map_destroy(game);
	sfRenderWindow_destroy(window->window);
}
