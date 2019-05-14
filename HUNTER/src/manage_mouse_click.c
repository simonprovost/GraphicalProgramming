/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

int manage_mouse_click(sfRenderWindow* window, v_t *duck)
{
	sfVector2i pos_mouse;
	int remove_duck = 0;

	pos_mouse = sfMouse_getPosition((sfWindow*) window);
	if ((pos_mouse.x >= duck->pos_duck.x - 40)
	&& (pos_mouse.x <= duck->pos_duck.x + 40)
	&& (pos_mouse.y >= duck->pos_duck.y - 40)
	&& (pos_mouse.y <= duck->pos_duck.y + 40) && remove_duck != -1) {
		remove_duck = 1;
	} else {
		remove_duck = -1;
	}
	return (remove_duck);
}
