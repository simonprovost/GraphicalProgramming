/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void clocks_destroy(game_t *game, window_t *window)
{
	sfClock_destroy(game->movement.timer.clock);
	sfClock_destroy(window->clocker.clock);
}
