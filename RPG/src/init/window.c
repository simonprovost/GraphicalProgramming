/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_timer(ctime_t *clocker)
{
	clocker->clock = sfClock_create();
	if (!clocker->clock)
		return (84);
	clocker->seconds = 0;
	return (0);
}

int init_window(window_t *window)
{
	window->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
					WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL},
					GAME_TITLE, sfClose | sfResize, NULL);
	if (!window->window)
		return (84);
	if (init_timer(&window->clocker) != 0)
		return (84);
	return (0);
}
