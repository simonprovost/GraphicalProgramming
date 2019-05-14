/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** replace.c
*/

#include "rpg.h"

int replace_mouse_skin(obj_t *obj, sfVector2f *offset, game_t *game)
{
	if (!obj || !offset)
		return (84);
	MOUSE_SKIN = obj;
	MOUSE_SKIN_OFFSET = *offset;
	return (0);
}

int reset_mouse_skin(game_t *game)
{
	MOUSE_SKIN = create_obj(&(obj_data_t){"MOUSE", "MOUSE_ICON",
	0, V2F(0, 0)}, game);
	if (!MOUSE_SKIN)
		return (84);
	MOUSE_SKIN_OFFSET = V2F(0, 0);
	return (0);
}