/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display
*/

#include "rpg.h"

int display_characters(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	sfRenderWindow_drawRectangleShape(window->window,
	PLAYER_CHARACTER->obj, NULL);
	if (game->battle.enemy[0])
		sfRenderWindow_drawRectangleShape(window->window,
		game->battle.enemy[0]->monster->obj, NULL);
	if (game->battle.enemy[1])
		sfRenderWindow_drawRectangleShape(window->window,
		game->battle.enemy[1]->monster->obj, NULL);
	if (game->battle.enemy[2])
		sfRenderWindow_drawRectangleShape(window->window,
		game->battle.enemy[2]->monster->obj, NULL);
	return (0);
}