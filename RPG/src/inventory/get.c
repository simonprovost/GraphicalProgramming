/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** get.c
*/

#include "rpg.h"

int items_foreach_horizontaly(int y, game_t *game,
				window_t *window, int (*fptr)())
{
	int my_errno = 0;

	for (int x = 0; x != INVENTORY_SIZE_X; x++) {
		if (!window) {
			my_errno = fptr(&ITEMS[y][x], &SLOT_POS(x, y), game);
		} else {
			my_errno = fptr(&ITEMS[y][x], window, game);
		}
		if (my_errno != 0)
			break;
	}
	return (my_errno);
}

int items_foreach(game_t *game, window_t *window, int (*fptr)())
{
	int my_errno = 0;

	if (!game) {
		my_printf("ERROR: YOU MUST PASS GAME \
		STRUCT TO ITEMS_FOREACH !\n");
		return (84);
	}
	for (int y = 0; y != INVENTORY_SIZE_Y; y++) {
		my_errno = items_foreach_horizontaly(y, game, window, fptr);
		if (my_errno != 0)
			break;
	}
	return (my_errno);
}
