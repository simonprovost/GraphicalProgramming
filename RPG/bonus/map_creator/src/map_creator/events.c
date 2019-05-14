/*
** EPITECH PROJECT, 2017
** my_world_2017
** File description:
** events.c created: 01/02/18 13:25
*/

#include "map_editor.h"

int check_timer(sfClock *my_clock)
{
	static sfTime timer;
	static float counter;

	timer = sfClock_getElapsedTime(my_clock);
	counter = timer.microseconds / 1000000.;
	if (counter > 0.4) {
		sfClock_restart(my_clock);
		return (1);
	}
	return (0);
}

void on_event(ressources_t *rsces, texture_list_t *list, sfEvent event,
							sfClock *my_clock)
{
	if (event.type == sfEvtClosed) {
		save_map(rsces->rsces);
		sfRenderWindow_close(rsces->window);
	}
	if (sfMouse_isButtonPressed(sfMouseLeft) && check_timer(my_clock))
		left_click_event(rsces, list);
	else if (sfMouse_isButtonPressed(sfMouseRight) && check_timer(my_clock))
		right_click_event(rsces, list);
	if (sfKeyboard_isKeyPressed(sfKeyB))
		rsces->mode = 1;
	else if (sfKeyboard_isKeyPressed(sfKeyE))
		rsces->mode = 0;
}
