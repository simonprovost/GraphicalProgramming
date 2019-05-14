/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "rpg.h"

int display_mouse(game_t *game, window_t *window)
{
	sfVector2f pos = {MOUSE_POS.x - MOUSE_SKIN_OFFSET.x,
	MOUSE_POS.y - MOUSE_SKIN_OFFSET.y};

	sfRectangleShape_setPosition(MOUSE_SKIN->obj, pos);
	sfRenderWindow_drawRectangleShape(window->window,
		MOUSE_SKIN->obj, NULL);
	return (0);
}
