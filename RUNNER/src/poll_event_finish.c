/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** DESCRIPTION
*/

#include "my_runner.h"

int poll_event_finish(sfEvent event, sfRenderWindow *window)
{
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			return (0);
		if (sfKeyboard_isKeyPressed(sfKeyReturn))
			return (1);
	}
	return (0);
}